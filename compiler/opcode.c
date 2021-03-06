#include "../include/SVM_code.h"

OpcodeInfo svm_opcode_info[] = {
    [OP_FALSE] = {"FALSE", "b", 1},

    [OP_DATA_1] = {"DATA_1", "a", 2},
    [OP_DATA_2] = {"DATA_2", "a", 2},
    [OP_DATA_3] = {"DATA_3", "a", 2},
    [OP_DATA_4] = {"DATA_4", "a", 2},
    [OP_DATA_5] = {"DATA_5", "a", 2},
    [OP_DATA_6] = {"DATA_6", "a", 2},
    [OP_DATA_7] = {"DATA_7", "a", 2},
    [OP_DATA_8] = {"DATA_8", "a", 2},
    [OP_DATA_9] = {"DATA_9", "a", 2},
    [OP_DATA_10] = {"DATA_10", "a", 2},
    [OP_DATA_11] = {"DATA_11", "a", 2},
    [OP_DATA_12] = {"DATA_12", "a", 2},
    [OP_DATA_13] = {"DATA_13", "a", 2},
    [OP_DATA_14] = {"DATA_14", "a", 2},
    [OP_DATA_15] = {"DATA_15", "a", 2},
    [OP_DATA_16] = {"DATA_16", "a", 2},
    [OP_DATA_17] = {"DATA_17", "a", 2},
    [OP_DATA_18] = {"DATA_18", "a", 2},
    [OP_DATA_19] = {"DATA_19", "a", 2},
    [OP_DATA_20] = {"DATA_20", "a", 2},
    [OP_DATA_21] = {"DATA_21", "a", 2},
    [OP_DATA_22] = {"DATA_22", "a", 2},
    [OP_DATA_23] = {"DATA_23", "a", 2},
    [OP_DATA_24] = {"DATA_24", "a", 2},
    [OP_DATA_25] = {"DATA_25", "a", 2},
    [OP_DATA_26] = {"DATA_26", "a", 2},
    [OP_DATA_27] = {"DATA_27", "a", 2},
    [OP_DATA_28] = {"DATA_28", "a", 2},
    [OP_DATA_29] = {"DATA_29", "a", 2},
    [OP_DATA_30] = {"DATA_30", "a", 2},
    [OP_DATA_31] = {"DATA_31", "a", 2},
    [OP_DATA_32] = {"DATA_32", "a", 2},
    [OP_DATA_33] = {"DATA_33", "a", 2},
    [OP_DATA_34] = {"DATA_34", "a", 2},
    [OP_DATA_35] = {"DATA_35", "a", 2},
    [OP_DATA_36] = {"DATA_36", "a", 2},
    [OP_DATA_37] = {"DATA_37", "a", 2},
    [OP_DATA_38] = {"DATA_38", "a", 2},
    [OP_DATA_39] = {"DATA_39", "a", 2},
    [OP_DATA_40] = {"DATA_40", "a", 2},
    [OP_DATA_41] = {"DATA_41", "a", 2},
    [OP_DATA_42] = {"DATA_42", "a", 2},
    [OP_DATA_43] = {"DATA_43", "a", 2},
    [OP_DATA_44] = {"DATA_44", "a", 2},
    [OP_DATA_45] = {"DATA_45", "a", 2},
    [OP_DATA_46] = {"DATA_46", "a", 2},
    [OP_DATA_47] = {"DATA_47", "a", 2},
    [OP_DATA_48] = {"DATA_48", "a", 2},
    [OP_DATA_49] = {"DATA_49", "a", 2},
    [OP_DATA_50] = {"DATA_50", "a", 2},
    [OP_DATA_51] = {"DATA_51", "a", 2},
    [OP_DATA_52] = {"DATA_52", "a", 2},
    [OP_DATA_53] = {"DATA_53", "a", 2},
    [OP_DATA_54] = {"DATA_54", "a", 2},
    [OP_DATA_55] = {"DATA_55", "a", 2},
    [OP_DATA_56] = {"DATA_56", "a", 2},
    [OP_DATA_57] = {"DATA_57", "a", 2},
    [OP_DATA_58] = {"DATA_58", "a", 2},
    [OP_DATA_59] = {"DATA_59", "a", 2},
    [OP_DATA_60] = {"DATA_60", "a", 2},
    [OP_DATA_61] = {"DATA_61", "a", 2},
    [OP_DATA_62] = {"DATA_62", "a", 2},
    [OP_DATA_63] = {"DATA_63", "a", 2},
    [OP_DATA_64] = {"DATA_64", "a", 2},
    [OP_DATA_65] = {"DATA_65", "a", 2},
    [OP_DATA_66] = {"DATA_66", "a", 2},
    [OP_DATA_67] = {"DATA_67", "a", 2},
    [OP_DATA_68] = {"DATA_68", "a", 2},
    [OP_DATA_69] = {"DATA_69", "a", 2},
    [OP_DATA_70] = {"DATA_70", "a", 2},
    [OP_DATA_71] = {"DATA_71", "a", 2},
    [OP_DATA_72] = {"DATA_72", "a", 2},
    [OP_DATA_73] = {"DATA_73", "a", 2},
    [OP_DATA_74] = {"DATA_74", "a", 2},
    [OP_DATA_75] = {"DATA_75", "a", 2},


    [OP_PUSHDATA1] = {"PUSHDATA1", "a", 2},
    [OP_PUSHDATA2] = {"PUSHDATA2", "a", 2},
    [OP_PUSHDATA4] = {"PUSHDATA4", "a", 2},
    [OP_1NEGATE] = {"NEGATE", "l", 0},

    [OP_1] = {"1", "b", 1},
    [OP_2] = {"2", "b", 1},
    [OP_3] = {"3", "b", 1},
    [OP_4] = {"4", "b", 1},
    [OP_5] = {"5", "b", 1},
    [OP_6] = {"6", "b", 1},
    [OP_7] = {"7", "b", 1},
    [OP_8] = {"8", "b", 1},
    [OP_9] = {"9", "b", 1},
    [OP_10] = {"10", "b", 1},
    [OP_11] = {"11", "b", 1},
    [OP_12] = {"12", "b", 1},
    [OP_13] = {"13", "b", 1},
    [OP_14] = {"14", "b", 1},
    [OP_15] = {"15", "b", 1},
    [OP_16] = {"16", "b", 1},
    
    [OP_NOP] = {"NOP", "b", 1},

    [OP_JUMP] = {"JUMP", "l", 1},
    [OP_JUMPIF] = {"JUMPIF", "l", 1},
    [OP_VERIFY] = {"VERIFY", "b", 0},
    [OP_FAIL] = {"FAIL", "b", 0},

    [OP_TOALTSTACK] = {"TOALTSTACK", "b", -1},
    [OP_FROMALTSTACK] = {"FROMALTSTACK", "b", 1},
    [OP_2DROP] = {"DROP2", "s", -2},
    [OP_2DUP] = {"DUP2", "s", 2},
    [OP_3DUP] = {"DUP3", "l", 3},
    [OP_2OVER] = {"OVER2", "l", 2},
    [OP_2ROT] = {"ROT2", "s", 0},
    [OP_2SWAP] = {"SWAP2", "s", 0},
    [OP_IFDUP] = {"IFDUP", "b", 1},
    [OP_DEPTH] = {"DEPTH", "b", 1},
    [OP_DROP] = {"DROP", "b", -1},
    [OP_DUP] = {"DUP", "b", 1},
    [OP_NIP] = {"NIP", "b", -1},
    [OP_OVER] = {"OVER", "b", 1},
    [OP_PICK] = {"PICK", "b", 1},
    [OP_ROLL] = {"ROLL", "b", 0},
    [OP_ROT] = {"ROT", "b", 0},
    [OP_SWAP] = {"SWAP", "b", 0},
    [OP_TUCK] = {"TUCK", "b", 1},

    [OP_CAT] = {"CAT", "s", -1},
    [OP_SUBSTR] = {"SUBSTR", "l", -2},
    [OP_LEFT] = {"LEFT", "s", -1},
    [OP_RIGHT] = {"RIGHT", "s", -1},
    [OP_SIZE] = {"SIZE", "b", 1},
    [OP_CATPUSHDATA] = {"CATPUSHDATA", "s", -1},

    [OP_INVERT] = {"INVERT", "b", 0},
    [OP_AND] = {"AND", "b", 0},
    [OP_OR] = {"OR", "b", 0},
    [OP_XOR] = {"XOR", "b", 0},
    [OP_EQUAL] = {"EQUAL", "b", 1},
    [OP_EQUALVERIFY] = {"EQUALVERIFY", "", 1},

    [OP_1ADD] = {"ADD1", "b", 0},
    [OP_1SUB] = {"SUB1", "b", 0},
    [OP_2MUL] = {"MUL2", "b", 0},
    [OP_2DIV] = {"DIV2", "b", 0},
    [OP_NEGATE] = {"NEGATE", "b", 0},
    [OP_ABS] = {"ABS", "b", 0},
    [OP_NOT] = {"NOT", "b", 0},
    [OP_0NOTEQUAL] = {"NOTEQUAL0", "b", 0},
    [OP_ADD] = {"ADD", "b", 1},
    [OP_SUB] = {"SUB", "b", 11},
    [OP_MUL] = {"MUL", "b", 1},
    [OP_DIV] = {"DIV", "b", 1},
    [OP_MOD] = {"MOD", "b", 1},
    [OP_LSHIFT] = {"LSHIFT", "b", 1},
    [OP_RSHIFT] = {"RSHIFT", "b", 1},
    [OP_BOOLAND] = {"BOOLAND", "b", 1},
    [OP_BOOLOR] = {"BOOLOR", "b", 1},
    [OP_NUMEQUAL] = {"NUMEQUAL", "b", 1},
    [OP_NUMEQUALVERIFY] = {"NUMEQUALVERIFY", "b", 1},
    [OP_NUMNOTEQUAL] = {"NUMNOTEQUAL", "b", 1},
    [OP_LESSTHAN] = {"LESSTHAN", "b", 1},
    [OP_GREATERTHAN] = {"GREATERTHAN", "b", 1},
    [OP_LESSTHANOREQUAL] = {"LESSTHANOREQUAL", "b", 1},
    [OP_GREATERTHANOREQUAL] = {"GREATERTHANOREQUAL", "b", 1},
    [OP_MIN] = {"MIN", "b", 1},
    [OP_MAX] = {"MAX", "b", 1},
    [OP_WITHIN] = {"WITHIN", "b", 1},

    [OP_SHA256] = {"SHA256", "b", 1},
    [OP_SHA3] = {"SHA3", "b", 1},
    [OP_HASH160] = {"HASH160", "b", 1},
    [OP_CHECKSIG] = {"CHECKSIG", "b", 1},
    [OP_CHECKMULTISIG] = {"CHECKMULTISIG", "b", 1},
    [OP_TXSIGHASH] = {"TXSIGHASH", "b", 1},

    [OP_CHECKOUTPUT] = {"CHECKOUTPUT", "b", 1},
    [OP_ASSET] = {"ASSET", "b", 1},
    [OP_AMOUNT] = {"AMOUNT", "b", 1},
    [OP_PROGRAM] = {"PROGRAM", "b", 1},
    [OP_INDEX] = {"INDEX", "b", 1},
    [OP_ENTRYID] = {"ENTRYID", "b", 1},
    [OP_OUTPUTID] = {"OUTPUTID", "b", 1},
    [OP_BLOCKHEIGHT] = {"BLOCKHEIGHT", "b", 1},

    [OP_DATA_INT] = {"DATA_4", "a", 2},
    [OP_DATA_INT64] = {"DATA_8", "a", 2},
};