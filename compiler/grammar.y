%{
#include <stdio.h>
#include <stdlib.h>
#include "compiler/summoner.h"

int yylex();
int yyerror(const char *s);
%}

%union {
    char        *identifier;
    char        *str_value;
    double      double_value;
    int         int_value;
    struct Expression* expression;
    struct Declaration* declaration;
    struct Statement *statement;
    struct StatementList *statement_list;
    struct Block *block;
    struct Elseif *elseif;
    struct TypeSpecifier *type_specifier;
    struct ParameterList *parameter_list;
    struct Definition *definition;
    struct DefinitionList *definition_list;
    struct ArgumentList *argument_list;
}

%token <double_value> DOUBLE_LITERAL
%token <int_value> INT_LITERAL BOOL_LITERAL
%token <str_value> STRING_LITERAL
%token <identifier> IDENTIFIER
%token VAR CONST FUNCTION IF ELSE FOR RETURN BREAK CONTINUE NIL
%token BOOL_T INT_T DOUBLE_T STRING_T ASSET_T HASH_T AMOUNT_T PUBKEY_T SIG_T HEX_T

%type <expression> expr bool_expr func_call_expr identifier_expr literal
%type <declaration> variable_declaration variable_declaration_list
%type <statement> stmt if_stmt return_stmt declaration_stmt assign_stmt compound_assign_stmt variable_declaration_stmt const_stmt
%type <statement_list> stmt_list
%type <block> block
%type <elseif> elseif elseif_list
%type <type_specifier> type_specifier
%type <parameter_list> parameter_list paramter
%type <definition> definition func_definition variable_definition const_definition
%type <definition_list> definition_list
%type <argument_list> argument_list

%nonassoc '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN DECL_ASSIGN
%left AND OR
%nonassoc EQ NE
%nonassoc '>' '<' LE GE
%left '+' '-'
%left '*' '/'
%nonassoc MINUS
%nonassoc NOT

%%

translation_unit:
                  new_line_option definition_list new_line_option { add_definitions_to_compiler($2); }
                ;

definition_list:
                  definition                          { $$ = alloc_definition_list($1); }
                | definition_list new_line definition { $$ = chain_definition_list($1, $3); }
                ;

definition:
            func_definition
          | const_definition          
          | variable_definition
          ;

func_definition:
                 FUNCTION IDENTIFIER '(' parameter_list ')' type_specifier block { $$ = alloc_func_definition($2, $4, $6, $7); }
               | FUNCTION IDENTIFIER '(' ')' type_specifier block                { $$ = alloc_func_definition($2, NULL, $5, $6); }
               | FUNCTION IDENTIFIER '(' parameter_list ')' block                { $$ = alloc_func_definition($2, $4, NULL, $6); }
               | FUNCTION IDENTIFIER '(' ')' block                               { $$ = alloc_func_definition($2, NULL, NULL, $5); }
               ;

variable_definition:
                     variable_declaration_stmt { $$ = alloc_declaration_definition($1); }
                   ;

const_definition:
                  const_stmt { $$ = alloc_declaration_definition($1); }
                ;

parameter_list:
                 paramter
               | parameter_list ',' paramter { $$ = chain_parameter($1, $3); }
               ;

paramter:
         IDENTIFIER type_specifier { $$ = alloc_parameter($2, $1); }
         ;

stmt_list:
          stmt                    {$$ = chain_stmt_list(NULL, $1); }
        | stmt_list new_line stmt {$$ = chain_stmt_list($1, $3); }
        ;

stmt:
       expr                { $$ = alloc_expression_stmt($1); }
     | block               { $$ = alloc_block_stmt($1); }
     | assign_stmt
     | if_stmt
     | declaration_stmt
     | return_stmt
     ;

assign_stmt:
             identifier_expr '=' expr  { $$ = alloc_assign_stmt($1, $3); }
           | compound_assign_stmt 
           ;

compound_assign_stmt:
                      identifier_expr ADD_ASSIGN expr { $$ = alloc_compound_assign_stmt($1, ADD_EXPRESSION, $3); }
                    | identifier_expr SUB_ASSIGN expr { $$ = alloc_compound_assign_stmt($1, SUB_EXPRESSION, $3); }
                    | identifier_expr MUL_ASSIGN expr { $$ = alloc_compound_assign_stmt($1, MUL_EXPRESSION, $3); }
                    | identifier_expr DIV_ASSIGN expr { $$ = alloc_compound_assign_stmt($1, DIV_EXPRESSION, $3); }
                    ;

const_stmt:
            CONST IDENTIFIER '=' expr                 { $$ = alloc_const_declaration_stmt($2, NULL, $4); }
          | CONST IDENTIFIER type_specifier '=' expr  { $$ = alloc_const_declaration_stmt($2, $3, $5); }
          ;

declaration_stmt:
                    IDENTIFIER DECL_ASSIGN expr            { $$ = alloc_declaration_stmt(alloc_declaration($1, NULL, $3)); }
                  | variable_declaration_stmt 
                  ;

variable_declaration_stmt:
                           VAR new_line_option variable_declaration                               { $$ = alloc_declaration_stmt($3); }
                         | VAR '(' new_line_option variable_declaration_list new_line_option ')'  { $$ = alloc_declaration_stmt($4); }
                         ;

variable_declaration_list:
                           variable_declaration
                         | variable_declaration_list new_line variable_declaration { $$ = chain_declaration_list($1, $3); }
                         ;

variable_declaration:       
                      IDENTIFIER type_specifier          { $$ = alloc_declaration($1, $2, NULL); }
                    | IDENTIFIER type_specifier '=' expr { $$ = alloc_declaration($1, $2, $4); }
                    | IDENTIFIER '=' expr                { $$ = alloc_declaration($1, NULL, $3); }
                    ;

type_specifier:
                BOOL_T   { $$ = alloc_type_specifier(BOOLEAN_TYPE); }
              | INT_T    { $$ = alloc_type_specifier(INT_TYPE); }
              | DOUBLE_T { $$ = alloc_type_specifier(DOUBLE_TYPE); }
              | STRING_T { $$ = alloc_type_specifier(STRING_TYPE); }
              | ASSET_T  { $$ = alloc_type_specifier(ASSET_TYPE); }
              | HASH_T   { $$ = alloc_type_specifier(HASH_TYPE); }
              | AMOUNT_T { $$ = alloc_type_specifier(AMOUNT_TYPE); }
              | PUBKEY_T { $$ = alloc_type_specifier(PUBKEY_TYPE); }
              | SIG_T    { $$ = alloc_type_specifier(SIG_TYPE); }
              | HEX_T    { $$ = alloc_type_specifier(HEX_TYPE); }
              ;

return_stmt:
             RETURN expr { $$ = alloc_return_stmt($2); }
           ;

if_stmt:
          IF bool_expr block                        { $$ = alloc_if_stmt($2, $3, NULL, NULL); }
        | IF bool_expr block ELSE block             { $$ = alloc_if_stmt($2, $3, NULL, $5); } 
        | IF bool_expr block elseif_list            { $$ = alloc_if_stmt($2, $3, $4, NULL); }
        | IF bool_expr block elseif_list ELSE block { $$ = alloc_if_stmt($2, $3, $4, $6); }
        ;

elseif_list: 
             elseif
           | elseif_list elseif { $$ = chain_else_if_list($1, $2); }
           ;

elseif:
        ELSE IF bool_expr block { $$ = alloc_else_if($3, $4); }
      ;

block:
         '{' new_line_option stmt_list new_line_option       { $<block>$ = open_block(); }
                                                       '}'   { $$ = close_block($<block>5, $3); }
       | '{' new_line_option '}'                             { $<block>$ = alloc_block(NULL); }
       ;

expr:
           literal
         | identifier_expr
         | expr '+' expr               { $$ = alloc_binary_expression(ADD_EXPRESSION, $1, $3); }
         | expr '-' expr               { $$ = alloc_binary_expression(SUB_EXPRESSION, $1, $3); }
         | expr '*' expr               { $$ = alloc_binary_expression(MUL_EXPRESSION, $1, $3); }
         | expr '/' expr               { $$ = alloc_binary_expression(DIV_EXPRESSION, $1, $3); }
         | '-' expr %prec MINUS        { $$ = alloc_unary_expression(MINUS_EXPRESSION, $2); }
         | '(' expr ')'                { $$ = $2; }
         | type_specifier '(' expr ')' { $$ = alloc_type_cast_expression($1, $3); }
         | bool_expr
         | func_call_expr
         ;

literal:
           INT_LITERAL           { $$ = alloc_int_expression($1); }
         | DOUBLE_LITERAL        { $$ = alloc_double_expression($1); }
         | BOOL_LITERAL          { $$ = alloc_bool_expression($1); }
         | STRING_LITERAL        { $$ = alloc_string_expression($1); }
         ;

bool_expr:
             expr '>' expr         { $$ = alloc_binary_expression(GT_EXPRESSION, $1, $3); }
           | expr GE expr          { $$ = alloc_binary_expression(GE_EXPRESSION, $1, $3); }
           | expr '<' expr         { $$ = alloc_binary_expression(LT_EXPRESSION, $1, $3); }
           | expr LE expr          { $$ = alloc_binary_expression(LE_EXPRESSION, $1, $3); }
           | expr EQ expr          { $$ = alloc_binary_expression(EQ_EXPRESSION, $1, $3); }
           | expr NE expr          { $$ = alloc_binary_expression(NE_EXPRESSION, $1, $3); }
           | expr AND expr         { $$ = alloc_binary_expression(AND_EXPRESSION, $1, $3); }
           | expr OR expr          { $$ = alloc_binary_expression(OR_EXPRESSION, $1, $3); }
           | '!' expr %prec NOT    { $$ = alloc_unary_expression(NOT_EXPRESSION, $2); }
           ;

func_call_expr:
                identifier_expr '(' ')'               { $$ = alloc_func_call_expression($1, NULL); }
              | identifier_expr '(' argument_list ')' { $$ = alloc_func_call_expression($1, $3); }
              ;

identifier_expr:
                 IDENTIFIER { $$ = alloc_identifier_expression($1); }
               ;

argument_list:
               expr                   { $$ = chain_argument_list(NULL, $1); }
             | argument_list ',' expr { $$ = chain_argument_list($1, $3); }
             ;

new_line_option:
               | new_line
               ;

new_line:
          '\n'
        | new_line '\n'

%%
