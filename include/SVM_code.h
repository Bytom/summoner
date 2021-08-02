#ifndef _SVMCODE_H_
#define _SVMCODE_H_

typedef enum {
    FALSE = 0x00,
    ZERO = 0x00,

    ONE = 0x51,
    TRUE = 0x51,

    PUSHDATA1 = 0x4c,
    PUSHDATA2,
    PUSHDATA4,
    NEGATE1,
    NOP,
    JUMP,
    JUMPIF,
    VERIFY,
    FAIL,
    TOALTSTACK,
    FROMALTSTACK,
    DROP2,
    DUP2,
    DUP3,
    OVER2,
    ROT2,
    SWAP2,
    IFDUP,
    DEPTH,
    DROP,
    DUP,
    NIP,
    OVER,
    PICK,
    ROLL,
    ROT,
    SWAP,
    TUCK,
    CAT,
    SUBSTR,
    LEFT,
    RIGHT,
    SIZE,
    CATPUSHDATA,
    INVERT,
    AND,
    OR,
    XOR,
    EQUAL,
    EQUALVERIFY,
    ADD1,
    SUB1,
    MUL2,
    DIV2,
    NEGATE,
    ABS,
    NOT,
    NOTEQUAL0,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    LSHIFT,
    RSHIFT,
    BOOLAND,
    BOOLOR,
    NUMEQUAL,
    NUMEQUALVERIFY,
    NUMNOTEQUAL,
    LESSTHAN,
    GREATERTHAN,
    LESSTHANOREQUAL,
    GREATERTHANOREQUAL,
    MIN,
    MAX,
    WITHIN,
    /**********/
    SHA256,
    SHA3,
    HASH160,
    CHECKSIG,
    CHECKMULTISIG,
    TXSIGHASH,
    /**********/
    CHECKOUTPUT,
    ASSET,
    AMOUNT,
    PROGRAM,
    INDEX,
    ENTRYID,
    OUTPUTID,
    BLOCKHEIGHT
}SVM_Opcode;

typedef struct {
    char        *mnemonic;
    char        *parameter;
    int         stack_increment;
} OpcodeInfo;

#endif