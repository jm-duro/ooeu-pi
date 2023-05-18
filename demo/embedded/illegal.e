
-- Helpers for illegal_builtin()
-- These constants make it easier to declare groups of builtin routines illegal.
-- See keylist.e for a full list of builtin routines.
global constant
MACHINE_BUILTIN = { 
	"machine_func", 
	"machine_proc" 
	},
MEMORY_BUILTIN  = {
	"poke",
	"poke4"
	"peek",
	"peek4u",
	"peek4s",
	"mem_set",
	"mem_copy" 
	},
C_BUILTIN = {
	"call",
	"c_func",
	"c_proc"
	},
SYSTEM_BUILTIN = {
	"abort",
	"system",
	"system_exec",
	"command_line",
	"getenv"
	},
IO_BUILTIN = {
	"print",
	"printf",
	"puts",
	"gets",
	"getc",
	"get_key"
	"?"
	}

	
