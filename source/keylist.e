-- Euphoria 2.5
-- KEYWORDS and BUILTIN ROUTINES
include reswords.e as r
global constant 
    K_NAME = 1,      -- string
    K_SCOPE = 2,     -- keyword or predefined 
    K_TOKEN = 3,     -- token number returned to parser 
    K_OPCODE = 4,    -- opcode to emit (predefined subprograms) 
    K_NUM_ARGS = 5,  -- number of arguments (predefined subprograms) 
    K_EFFECT = 6     -- side effects 

global sequence keylist
-- N.B. order and number of keywords and builtins 
-- is assumed by scanner.e, euphoria\bin\keywords.e, and others
keylist = 
  {  
    -- KEYWORDS
    {"if",        SC_KEYWORD, IF, 0, 0, 0},
    {"end",       SC_KEYWORD, END, 0, 0, 0},
    {"then",      SC_KEYWORD, THEN, 0, 0, 0},
    {"procedure", SC_KEYWORD, PROCEDURE, 0, 0, 0},
    {"else",      SC_KEYWORD, ELSE, 0, 0, 0},
    {"for",       SC_KEYWORD, FOR, 0, 0, 0},
    {"return",    SC_KEYWORD, RETURN, 0, 0, 0},
    {"do",        SC_KEYWORD, DO, 0, 0, 0},
    {"elsif",     SC_KEYWORD, ELSIF, 0, 0, 0},
    {"while",     SC_KEYWORD, WHILE, 0, 0, 0},
    {"type",      SC_KEYWORD, TYPE_DECL, 0, 0, 0},
    {"constant",  SC_KEYWORD, CONSTANT, 0, 0, 0},
    {"to",        SC_KEYWORD, TO, 0, 0, 0},
    {"and",       SC_KEYWORD, AND, 0, 0, 0},
    {"or",        SC_KEYWORD, OR, 0, 0, 0},
    {"exit",      SC_KEYWORD, EXIT, 0, 0, 0},
    {"function",  SC_KEYWORD, FUNCTION, 0, 0, 0},
    {"global",    SC_KEYWORD, GLOBAL, 0, 0, 0},
    {"by",        SC_KEYWORD, BY, 0, 0, 0},
    {"not",       SC_KEYWORD, NOT, 0, 0, 0},
    {"include",   SC_KEYWORD, INCLUDE, 0, 0, 0},
    {"with",      SC_KEYWORD, WITH, 0, 0, 0},
    {"without",   SC_KEYWORD, WITHOUT, 0, 0, 0},
    {"xor",       SC_KEYWORD, XOR, 0, 0, 0},
    -- new ones must go at end to maintain upward compatibility with
    -- old shrouded code

    -- PREDEFINED SUBPROGRAMS and TYPEs 
    {"length",    SC_PREDEF, r:FUNC, LENGTH, 1, E_PURE},
    {"puts",      SC_PREDEF, r:PROC, PUTS, 2, E_OTHER_EFFECT},
    {"integer",   SC_PREDEF, TYPE, IS_AN_INTEGER, 1, E_PURE},
    {"sequence",  SC_PREDEF, TYPE, IS_A_SEQUENCE, 1, E_PURE},
    {"position",  SC_PREDEF, r:PROC, POSITION, 2, E_OTHER_EFFECT},
    {"object",    SC_PREDEF, TYPE, IS_AN_OBJECT, 1, E_PURE},
    {"append",    SC_PREDEF, r:FUNC, APPEND, 2, E_PURE},
    {"prepend",   SC_PREDEF, r:FUNC, PREPEND, 2, E_PURE},
    {"print",     SC_PREDEF, r:PROC, PRINT, 2, E_OTHER_EFFECT},
    {"printf",    SC_PREDEF, r:PROC, PRINTF, 3, E_OTHER_EFFECT},
    {"clear_screen", SC_PREDEF,r:PROC,CLEAR_SCREEN, 0, E_OTHER_EFFECT},
    {"floor",     SC_PREDEF, r:FUNC, FLOOR, 1, E_PURE},
    {"getc",      SC_PREDEF, r:FUNC, GETC, 1, E_OTHER_EFFECT},
    {"gets",      SC_PREDEF, r:FUNC, GETS, 1, E_OTHER_EFFECT},
    {"get_key",   SC_PREDEF, r:FUNC, GET_KEY, 0, E_PURE}, -- tiny effect, unimportant
    {"rand",      SC_PREDEF, r:FUNC, RAND, 1, E_PURE}, -- effect usually not important
    {"repeat",    SC_PREDEF, r:FUNC, REPEAT, 2, E_PURE},
    {"atom",      SC_PREDEF, TYPE, IS_AN_ATOM, 1, E_PURE},
    {"compare",   SC_PREDEF, r:FUNC, COMPARE, 2, E_PURE},
    {"find",      SC_PREDEF, r:FUNC, FIND, 2, E_PURE},
    {"match",     SC_PREDEF, r:FUNC, MATCH, 2, E_PURE},
    {"time",      SC_PREDEF, r:FUNC, TIME, 0, E_PURE},
    {"command_line",SC_PREDEF,r:FUNC,COMMAND_LINE, 0, E_PURE},
    {"open",      SC_PREDEF, r:FUNC, OPEN, 2, E_OTHER_EFFECT},
    {"close",     SC_PREDEF, r:PROC, CLOSE, 1, E_OTHER_EFFECT},
    {"trace",     SC_PREDEF, r:PROC, TRACE, 1, E_PURE},
    {"getenv",    SC_PREDEF, r:FUNC, GETENV, 1, E_PURE},
    {"sqrt",      SC_PREDEF, r:FUNC, SQRT, 1, E_PURE},
    {"sin",       SC_PREDEF, r:FUNC, SIN, 1, E_PURE},
    {"cos",       SC_PREDEF, r:FUNC, COS, 1, E_PURE},
    {"tan",       SC_PREDEF, r:FUNC, TAN, 1, E_PURE},
    {"log",       SC_PREDEF, r:FUNC, LOG, 1, E_PURE},
    {"system",    SC_PREDEF, r:PROC, SYSTEM, 2, E_OTHER_EFFECT},
    {"date",      SC_PREDEF, r:FUNC, DATE, 0, E_PURE}, 
    {"remainder", SC_PREDEF, r:FUNC, REMAINDER, 2, E_PURE},
    {"power",     SC_PREDEF, r:FUNC, POWER, 2, E_PURE},
    {"machine_func", SC_PREDEF, r:FUNC, MACHINE_FUNC, 2, E_OTHER_EFFECT},
    {"machine_proc", SC_PREDEF, r:PROC, MACHINE_PROC, 2, E_OTHER_EFFECT},
    {"abort",     SC_PREDEF, r:PROC, ABORT, 1, E_OTHER_EFFECT},
    {"peek",      SC_PREDEF, r:FUNC, PEEK, 1, E_PURE},
    {"poke",      SC_PREDEF, r:PROC, POKE, 2, E_OTHER_EFFECT},
    {"call",      SC_PREDEF, r:PROC, CALL, 1, E_OTHER_EFFECT},
    {"sprintf",   SC_PREDEF, r:FUNC, SPRINTF, 2, E_PURE},
    {"arctan",    SC_PREDEF, r:FUNC, ARCTAN, 1, E_PURE},
    {"and_bits",  SC_PREDEF, r:FUNC, AND_BITS, 2, E_PURE},
    {"or_bits",   SC_PREDEF, r:FUNC, OR_BITS, 2, E_PURE},
    {"xor_bits",  SC_PREDEF, r:FUNC, XOR_BITS, 2, E_PURE},
    {"not_bits",  SC_PREDEF, r:FUNC, NOT_BITS, 1, E_PURE},
    {"pixel",     SC_PREDEF, r:PROC, PIXEL, 2, E_OTHER_EFFECT},
    {"get_pixel", SC_PREDEF, r:FUNC, GET_PIXEL, 1, E_PURE},
    {"mem_copy",  SC_PREDEF, r:PROC, MEM_COPY, 3, E_OTHER_EFFECT},
    {"mem_set",   SC_PREDEF, r:PROC, MEM_SET, 3, E_OTHER_EFFECT},
    {"c_proc",    SC_PREDEF, r:PROC, C_PROC, 2,  E_ALL_EFFECT}, 
    {"c_func",    SC_PREDEF, r:FUNC, C_FUNC, 2, E_ALL_EFFECT},
    {"routine_id",SC_PREDEF, r:FUNC, ROUTINE_ID, 1, E_PURE},
    {"call_proc", SC_PREDEF, r:PROC, CALL_PROC, 2, E_ALL_EFFECT},
    {"call_func", SC_PREDEF, r:FUNC, CALL_FUNC, 2, E_ALL_EFFECT},
    {"poke4",     SC_PREDEF, r:PROC, POKE4, 2, E_OTHER_EFFECT},
    {"peek4s",    SC_PREDEF, r:FUNC, PEEK4S, 1, E_PURE},
    {"peek4u",    SC_PREDEF, r:FUNC, PEEK4U, 1, E_PURE},
    {"profile",   SC_PREDEF, r:PROC, PROFILE, 1, E_PURE},
    {"equal",     SC_PREDEF, r:FUNC, EQUAL, 2, E_PURE},
    {"system_exec",SC_PREDEF,r:FUNC, SYSTEM_EXEC, 2, E_OTHER_EFFECT},
    {"platform",  SC_PREDEF, r:FUNC, PLATFORM, 0, E_PURE}
    -- begin mwl
    ,
    {"euclass", SC_KEYWORD, CLASS, CLASS, 0, 0, 0},
    {"eval", SC_PREDEF, r:FUNC, EVAL, 1, E_ALL_EFFECT},
    {"eval_error",    SC_PREDEF, r:FUNC, EVAL_ERROR, 0, E_PURE},
    {"var_id", SC_PREDEF, r:FUNC, VAR_ID, 1, E_PURE},
    {"read_var", SC_PREDEF, r:FUNC, READ_VAR, 1, E_PURE},
    {"write_var", SC_PREDEF, r:PROC, WRITE_VAR, 2, E_ALL_EFFECT},
    {"dump_vars", SC_PREDEF, r:FUNC, DUMP_VARS, 0, E_PURE},
    {"of", SC_KEYWORD, OF, 0, 0, 0},
    {"continue", SC_KEYWORD, CONTINUE, 0, 0, 0},
    {"goto", SC_KEYWORD, GOTO, 0, 0, 0 },
    {"default_goto", SC_PREDEF, r:PROC, DEFAULT_GOTO, 1, E_PURE},
    {"is_goto", SC_PREDEF, r:FUNC, IS_GOTO, 1, E_PURE},
    {"embedded_procedure_call", SC_PREDEF, r:PROC, EMBEDDED_PROCEDURE_CALL, 2, E_ALL_EFFECT },
    {"embedded_function_call",  SC_PREDEF, r:FUNC, EMBEDDED_FUNCTION_CALL, 2, E_ALL_EFFECT },
    {"find_from", SC_PREDEF, r:FUNC, FIND_FROM, 3, E_PURE },
    {"match_from", SC_PREDEF, r:FUNC, MATCH_FROM, 3, E_PURE }

    -- end mwl
}
    -- new words must go at end to maintain upward compatibility 

    
-- top level pseudo-procedure (assumed to be last on the list) 
keylist = append(keylist, {"_toplevel_", SC_PREDEF, r:PROC, 0, 0, E_ALL_EFFECT})
-- begin mwl
keylist = append(keylist, {"_eval_", SC_PREDEF, r:PROC, 0, 0, E_ALL_EFFECT})
-- end mwl
