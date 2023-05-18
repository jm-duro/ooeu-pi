-- Euphoria 2.5
-- Global declarations 

global constant INTERPRETER_VERSION = "2.5", OOEU_VERSION = {1,9,0}

global type boolean(integer x)
    return x = TRUE or x = FALSE
end type

-- operating system:
global constant ELINUX = platform() = LINUX,
		EWINDOWS = platform() = WIN32,
		EDOS = platform() = DOS32,
		EBSD = FALSE -- FOR NOW

-- specific C compiler used (one may be TRUE)
global constant EWATCOM = TRUE,
		EBORLAND = FALSE,
		ELCC = FALSE,
		EDJGPP = FALSE
		-- (assume GNU C for LINUX/FreeBSD)

global boolean w32 -- Windows option for BIND
		
global sequence version_name
if EDOS then
    if EDJGPP then
	version_name = "DOS32 built for DJGPP"
    else
	version_name = "DOS32"
    end if
elsif EWINDOWS then
    version_name = "WIN32"
elsif ELINUX then 
    version_name = "Linux"
end if

global integer PATH_SEPARATOR, SLASH
global sequence SLASH_CHARS
if ELINUX then
    PATH_SEPARATOR = ':' -- in PATH environment variable
    SLASH = '/'          -- preferred on Linux/FreeBSD
    SLASH_CHARS =  "/"   -- special chars allowed in a path
else
    PATH_SEPARATOR = ';'
    SLASH = '\\'
    SLASH_CHARS = "\\/:"
end if

-- common fields for all symbols, literal constants and temporaries 
global constant 
	 S_OBJ = 1,     -- initialized for literal constants
		      -- NOVALUE for other temps 
		      -- run time object (vars)
		      -- must be first field in C
	 S_NEXT = 2,    -- index of next temp, or next var, or 0
	 S_MODE = 3,    -- M_NORMAL, M_TEMP or M_CONSTANT 
	 S_SCOPE = 4,   -- for temps at compile time: FREE or IN_USE, 
		      -- or DELETED (Translator-only) 
	 S_USAGE = 5    -- for temps: type T_UNKNOWN or T_INTEGER 
		      -- for vars, read/written/to be deleted

-- extra fields for vars (and routines) only but not temps 
global constant 
	 S_FILE_NO = 6,   -- file number where symbol is defined
	 S_NAME = 7,      -- name string
	 S_SAMEHASH = 8,  -- index of next symbol with same hash value
	 S_TOKEN = 9,     -- token number to return to parser
	 S_HASHVAL = 10,  -- hash value 
	 S_NREFS = 11     -- number of references to this symbol 

	 -- for vars only:  
global constant 
	 S_VARNUM = 12,   -- local variable number 
	 S_INITLEVEL = 13,-- nesting level where initialized or -1 
	 S_VTYPE = 14     -- variable type or NULL 

	 -- for routines only: 
global constant 
	 S_CODE = 15,     -- IL code for proc/func/type 
	 S_LINETAB = 16,  -- Line table for traceback
	 S_FIRSTLINE = 17,-- global line number of start of routine
	 S_TEMPS = 18,    -- pointer to linked list of temps, or 0
	 S_OPCODE = 19,   -- opcode to emit (predefined subprograms)
	 S_NUM_ARGS = 20, -- number of arguments
	 S_EFFECT = 21,   -- side effects
	 S_REFLIST = 22,  -- list of referenced symbols (for BIND)
	 S_ACTIVE = 23    -- currently in use (at run-time)
	 
	 -- begin mwl
global constant
	 S_GOTO = 24,
	 S_BYREF = 25
	 -- end mwl


global constant SIZEOF_ROUTINE_ENTRY = 23 + 24 * TRANSLATE + 2, -- added one for GOTO's and one for BYREF
		SIZEOF_VAR_ENTRY = 14 + 33 * TRANSLATE,
		SIZEOF_TEMP_ENTRY = 5 + 25 * TRANSLATE
	 
-- Permitted values for various symbol table fields

-- MODE values:
global constant M_NORMAL   = 1,  -- all variables
	 M_CONSTANT = 2,         -- literals and declared constants
	 M_TEMP     = 3          -- temporaries

-- SCOPE values: 
global constant SC_LOOP_VAR = 2, -- "private" loop vars known within a single loop 
	 SC_PRIVATE  = 3,    -- private within subprogram
	 SC_GLOOP_VAR = 4,   -- "global" loop var 
	 SC_LOCAL    = 5,    -- local to the file
	 SC_GLOBAL   = 6,    -- global across all files 
	 SC_PREDEF   = 7,    -- predefined symbol - could be overriden
	 SC_KEYWORD  = 8,    -- a keyword
	 SC_UNDEFINED = 9,   -- new undefined symbol 
	 SC_MULTIPLY_DEFINED = 10  -- global symbol defined in 2 or more other files

-- USAGE values          -- how symbol has been used (1,2 can be OR'd) 
global constant U_UNUSED    = 0,     
	 U_READ      = 1,
	 U_WRITTEN   = 2,
	 U_DELETED   = 99   -- we've decided to delete this symbol 

-- Does a routine have an effect other than just returning a value?
-- We use 30 bits of information (to keep it in integer range).
-- Bits 0..28 give a rough indication of which local/global vars a routine 
-- might directly or indirectly modify. This helps to optimize a rare 
-- situation when assigning to a multiply-subscripted sequence.
-- Bit 29 indicates all other side effects (I/O etc.)
global constant 
	    E_PURE = 0,  -- routine has no side effects
	    E_SIZE = 29,  -- number of bits for screening out vars
    E_OTHER_EFFECT = power(2, E_SIZE),  -- routine has other effects, e.g. I/O
    E_ALL_EFFECT = #3FFFFFFF -- all bits (0..29) are set
    
global constant FREE = 0, 
	      IN_USE = 1, 
	     DELETED = 2

-- result types
global constant T_INTEGER = 1,
		T_SEQUENCE = 3,
		T_ATOM = 4,
		T_UNKNOWN = 5
		
global constant MIN = 1,
		MAX = 2

global constant MAXINT = #3FFFFFFF,
		MININT = -MAXINT-1,   -- should be -ve
		MININT_VAL = MININT,  -- these are redundant ...
		MAXINT_VAL = MAXINT,
		MININT_DBL = MININT_VAL,
		MAXINT_DBL = MAXINT_VAL

global constant NOVALUE = -1.295837195871e307  
-- An unlikely number. If it occurs naturally, 
-- there will be a slight loss of optimization 
-- as we will not know the value of a variable at compile time.
-- (NaN could be used, but it's not 100% portable).

global sequence SymTab  -- the symbol table
SymTab = {}


--------- Global Types for Debugging -----------


global type symtab_entry(sequence x)
-- (could test all the fields)  
    return length(x) = SIZEOF_ROUTINE_ENTRY or 
	   length(x) = SIZEOF_VAR_ENTRY
end type

global type symtab_index(integer x)
-- index of a normal symbol or temporary    
    if x = 0 then
	return TRUE -- NULL value
    end if
    if x < 0 or x > length(SymTab) then
	return FALSE
    end if
    return find(length(SymTab[x]), {SIZEOF_VAR_ENTRY, SIZEOF_ROUTINE_ENTRY,
			  SIZEOF_TEMP_ENTRY})
end type

global type temp_index(integer x)
    return x >= 0 and x <= length(SymTab)
end type

-- token fields
global constant T_ID = 1,
		T_SYM = 2

global type token(sequence t)
-- scanner token
    return length(t) = 2 and integer(t[T_ID]) and symtab_index(t[T_SYM])
end type

global type file(integer f)
-- a file number
    return f >= -1 and f < 100 -- rough limit
end type

---------------- Global Variables ----------------------

global object eudir           -- path to Euphoria directory 
global sequence file_name     -- names of all the source files 
file_name = {}
global integer current_file_no    -- current file number 
current_file_no = 1
global integer line_number  -- source line number within current file (16 bits)  
global integer gline_number  -- overall line number (32 bits) 
global symtab_index file_start_sym
global symtab_index TopLevelSub       -- s.t. index of top level procedure 
global symtab_index CurrentSub        -- s.t. index of current routine 
global integer num_routines      -- sequence number for routine_id lookups 
num_routines = 0
global integer Argc             -- (our) number of args to main 
global sequence Argv            -- (our) arguments to main 


-- With/Without Options
global integer OpWarning            -- compile-time warnings option 
global integer OpTrace              -- trace option 
global integer OpTypeCheck          -- type check option 
global integer OpProfileStatement   -- statement profile option currently on 
global integer OpProfileTime        -- time profile option currently on 
-- begin mwl:
global integer OpStrictGoto
-- end mwl

-- COMPILE only
global object dj_path, wat_path, bor_path
dj_path = 0         -- DJGPP directory or 0
wat_path = 0        -- WATCOM directory or 0
bor_path = 0        -- BORLAND directory or 0
global integer cfile_count, cfile_size 
cfile_count = 0
cfile_size = 0
global integer Initializing 
Initializing = FALSE

global sequence temp_name_type
temp_name_type = repeat({0, 0}, 4)  -- skip 1..4
global constant T_GTYPE = 1,
		T_GTYPE_NEW = 2

global integer main_name_num 
main_name_num = 0

global integer Execute_id

global sequence Code       -- The IL Code we are currently working with
global sequence LineTable  -- the line table we are currently building

global sequence slist 
slist = {}
global constant SRC = 1,  -- line of source code
	       LINE = 2,  -- line number within file
      LOCAL_FILE_NO = 3,  -- file number
	    OPTIONS = 4   -- options in effect

-- option bits:
global constant SOP_TRACE = #01,      -- statement trace
	 SOP_PROFILE_STATEMENT = #04, -- statement profile
	 SOP_PROFILE_TIME = #02       -- time profile


-- begin mwl
global sequence class_table, method_table, member_table
global constant
	CLASS_NAME = 1,
	CLASS_METHOD = 2,
	CLASS_VARIABLE = 3,
	CLASS_PARENT = 4,
	CLASS_VARTYPE = 5,
	CLASS_SYM = 6,
	CLASS_SEQUENCEOF = 7,
	
	CLASS_ENTRY = 7,
	
	METHOD_NAME = 1,
	METHOD_ARGLIST = 2,
	METHOD_SYM = 3,
	METHOD_CLASS = 4,
	
	METHOD_ENTRY = 4,
	
	MEMBER_NAME = 1,
	MEMBER_CLASS = 2,
	MEMBER_VARTYPE = 3,
	MEMBER_SUBSCRIPT = 4,
	MEMBER_SYM = 5,
	
	MEMBER_ENTRY = 5

class_table = repeat( {}, CLASS_ENTRY )
method_table = repeat( {}, METHOD_ENTRY )
member_table = repeat( {}, MEMBER_ENTRY )

global sequence source_name

global integer current_class, current_method, parse_method, current_term, forward_method_func,
	forward_method, execute, bind, bound, no_source, preprocess, full_debug, eval_sym,
	forward_do_exec, eval_used, use_eval, delete_symbols, forward_putback, eval_file,
	forward_eval_exec
	
global atom debugger, debug_main, get_value_cb, get_symbols_cb, get_line_cb, get_lines_cb,
	set_break_cb, get_files_cb, set_trace_cb, trace_func, set_object_cb, current_sub_cb,
	update_vars, get_pc_cb, display_var_cb, erase_symbol_cb, erase_privates_cb,
	cleanup_cb, hide_debugger, set_values_cb, get_object_cb, debug_out, set_debug_io_cb

global sequence current_instance, method_stack, method_args, method_name, term_stack, 
	parse_method_stack, line_tokens, token_boundaries, processed_files,
	start_line, start_line_token, remember_line, traced_lines, token_ws,
	break_points, eval_stack, eval_buffer, eval_error, geval_error, eval_file_no,
	file_eval, precompiled, member_stack, loop_stack, loop_sym_stack, loop_bp_stack,
	goto_back_patch

global object debugger_name

goto_back_patch = {{}}
loop_stack = {0}
loop_sym_stack = {0}
loop_bp_stack = {0}
token_ws = {0}
traced_lines = {}
term_stack = {{0,0}}
current_term = 0
current_class = 0
current_instance = {0}
current_method = 0
method_stack = {}
method_args = {}
method_name = {}
parse_method = 0
parse_method_stack = {0}
execute = 1
bind = 0
bound = 0
no_source = 0
preprocess = 0
line_tokens = {}
token_boundaries = {}
processed_files = {}
start_line = {0}
start_line_token = {0}
remember_line = {0}
full_debug = 0
break_points = {}
eval_stack = {0}
eval_buffer = {}
eval_sym = 0
eval_error = {{}}
geval_error = {}
eval_file_no = {0}
file_eval = {0}
eval_used = 0
precompiled = {}
member_stack = {0}
debugger = -1
delete_symbols = 1
eval_file = 0

debugger_name = getenv("OOEU_DEBUGGER")

if atom(debugger_name) then
if platform() = LINUX then
    debugger_name = "ooeu_trace.so"

else
	debugger_name = "ooeu_trace.dll"

end if
end if


global constant 
MAGIC_NUMBER = { 116, 124, 142, 251 },
SHROUD_VERSION = 3,
FORWARD_ROUTINE_ID = FALSE,

G_LABEL = 1,
G_PC = 2,
G_DEFAULT = 3

global integer POST_PROCESS_RID
global sequence hide_member
hide_member = {{}}

global sequence ref_list

global atom embedded_call_back
embedded_call_back = 0
-- end mwl
