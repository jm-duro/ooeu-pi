
-- Euphoria 2.5
-- Symbol Table Routines
include reswords.e as r
global constant NBUCKETS = 2003  -- prime helps  
global sequence buckets   -- hash buckets
buckets = repeat(0, NBUCKETS)

global symtab_index object_type       -- s.t. index of object type 
global symtab_index atom_type         -- s.t. index of atom type 
global symtab_index sequence_type     -- s.t. index of sequence type 
global symtab_index integer_type      -- s.t. index of integer type 

sequence e_routine   -- sequence of symbol table pointers for routine_id
e_routine = {}

global symtab_index literal_init
literal_init = 0

global sequence lastintval, lastintsym
lastintval = {}
lastintsym = {}

global integer last_sym
last_sym = 0

-- begin mwl
-- made global
global function hashfn(sequence name) 
-- end mwl
-- hash function for symbol table
    integer len
    integer val -- max is 268,448,190+len

    len = length(name)
    val = name[len] * 256 + name[1]*2 + len
    if len >= 4 then
	val = val * 64 + name[2]
	val = val * 64 + name[3]
    elsif len >= 3 then
	val = val * 64 + name[2]
    end if
    return remainder(val, NBUCKETS) + 1
end function

global function NewEntry(sequence name, integer varnum, integer scope, 
		  integer token, integer hashval, symtab_index samehash, 
		  symtab_index type_sym)
-- Enter a symbol into the table at the next available position 
    sequence new

    if TRANSLATE then
	new = repeat(0, SIZEOF_ROUTINE_ENTRY)
    else
	new = repeat(0, SIZEOF_VAR_ENTRY)
    end if
    
    new[S_NEXT] = 0
    new[S_NAME] = name
    new[S_SCOPE] = scope
    new[S_MODE] = M_NORMAL
    new[S_USAGE] = U_UNUSED
    new[S_FILE_NO] = current_file_no

    new[S_TOKEN] = token
    new[S_VARNUM] = varnum
    new[S_INITLEVEL] = -1
    new[S_VTYPE] = type_sym
    new[S_HASHVAL] = hashval
    new[S_SAMEHASH] = samehash
    new[S_OBJ] = NOVALUE -- important 
    
    -- add new symbol to the end of the symbol table
    SymTab = append(SymTab, new)
    if last_sym then
		SymTab[last_sym][S_NEXT] = length(SymTab)
    end if
    last_sym = length(SymTab)
    return last_sym
end function

constant BLANK_ENTRY = repeat(0, SIZEOF_TEMP_ENTRY)

global function tmp_alloc()
-- return SymTab index for a new temporary var/literal constant
    symtab_index new
    
    SymTab = append(SymTab, BLANK_ENTRY)
    new = length(SymTab)
    SymTab[new][S_USAGE] = T_UNKNOWN
    return new
end function

function PrivateName(sequence name, symtab_index proc)
-- does name match that of a private in the current active proc?
    symtab_index s
    
    s = proc[S_NEXT] -- start at next entry
    while s and s[S_SCOPE] <= SC_PRIVATE do
	if equal(name, SymTab[s][S_NAME]) then
	    return TRUE
	end if
	s = SymTab[s][S_NEXT]
    end while
    return FALSE
end function

global procedure DefinedYet(symtab_index sym)
-- make sure sym has not been defined yet, except possibly as
-- a predefined symbol, or a global in a previous file 
    if not find(SymTab[sym][S_SCOPE], 
		{SC_UNDEFINED, SC_MULTIPLY_DEFINED, SC_PREDEF}) then
	if SymTab[sym][S_FILE_NO] = current_file_no then
	    CompileErr(sprintf("attempt to redefine %s", {SymTab[sym][S_NAME]}))
	end if
    end if
end procedure

global function name_ext(sequence s)
-- Returns a pointer to the 8.3 file name & extension part of a path.
-- Note: both forward slash and backslash are handled for all platforms. 
    integer i
    
    i = length(s)
    while i >= 1 and not find(s[i], "/\\:") do  
	i -= 1
    end while
    
    return s[i+1..$]
end function

constant SEARCH_LIMIT = 20 + 500 * (TRANSLATE or BIND)

global function NewStringSym(sequence s)
-- create a new temp that holds a string 
    symtab_index p, tp, prev
    integer search_count

    -- check if it exists already
    tp = literal_init
    prev = 0
    search_count = 0
    while tp != 0 do
	search_count += 1
	if search_count > SEARCH_LIMIT then  -- avoid n-squared algorithm
	    exit
	end if
	if equal(s, SymTab[tp][S_OBJ]) then
	    -- move it to first on list
	    if tp != literal_init then
		SymTab[prev][S_NEXT] = SymTab[tp][S_NEXT]
		SymTab[tp][S_NEXT] = literal_init
		literal_init = tp
	    end if
	    return tp
	end if
	prev = tp
	tp = SymTab[tp][S_NEXT]
    end while
    
    p = tmp_alloc()
    SymTab[p][S_OBJ] = s
    SymTab[p][S_MODE] = M_CONSTANT
    SymTab[p][S_NEXT] = literal_init
    literal_init = p
    return p
end function

global function NewIntSym(integer int_val)
-- New integer symbol 
-- int_val must not be too big for a Euphoria int 
    symtab_index p
    integer x
    
    x = find(int_val, lastintval) 
    if x then
	return lastintsym[x]  -- saves space, helps Translator reduce code size
	    
    else 
	p = tmp_alloc()
	SymTab[p][S_MODE] = M_CONSTANT
	SymTab[p][S_OBJ] = int_val
	lastintval = prepend(lastintval, int_val)
	lastintsym = prepend(lastintsym, p)
	if length(lastintval) > SEARCH_LIMIT then
	    lastintval = lastintval[1..floor(SEARCH_LIMIT/2)]
	end if
	return p
    end if
end function

global function NewDoubleSym(atom d)
-- allocate space for a new double literal value at compile-time 
    symtab_index p, tp, prev
    integer search_count
    
    -- check if it exists already
    tp = literal_init
    prev = 0
    search_count = 0
    while tp != 0 do
	search_count += 1
	if search_count > SEARCH_LIMIT then  -- avoid n-squared algorithm
	    exit
	end if
	if equal(d, SymTab[tp][S_OBJ]) then
	    -- found it
	    if tp != literal_init then
		-- move it to first on list
		SymTab[prev][S_NEXT] = SymTab[tp][S_NEXT]
		SymTab[tp][S_NEXT] = literal_init
		literal_init = tp
	    end if
	    return tp
	end if
	prev = tp
	tp = SymTab[tp][S_NEXT]
    end while
    
    p = tmp_alloc()
    SymTab[p][S_MODE] = M_CONSTANT
    SymTab[p][S_OBJ] = d
    SymTab[p][S_NEXT] = literal_init
    literal_init = p
    return p
end function

global integer temps_allocated   -- number of temps allocated for CurrentSub 
temps_allocated = 0

global function NewTempSym()
-- allocate a new temp and link it with the list of temps
-- for the current subprogram 
    symtab_index p
    
    p = SymTab[CurrentSub][S_TEMPS]
    while p != 0 and SymTab[p][S_SCOPE] != FREE do
	p = SymTab[p][S_NEXT]
    end while
    
    if p = 0 then
	-- no free temps available 
	temps_allocated += 1
	p = tmp_alloc()
	SymTab[p][S_MODE] = M_TEMP
	SymTab[p][S_NEXT] = SymTab[CurrentSub][S_TEMPS]
	SymTab[CurrentSub][S_TEMPS] = p
    end if
    SymTab[p][S_OBJ] = NOVALUE
    SymTab[p][S_USAGE] = T_UNKNOWN
    SymTab[p][S_SCOPE] = IN_USE
    return p
end function

global procedure InitSymTab()
-- Initialize the Symbol Table 
    integer hashval, len
    --register symtab_index *bptr
    symtab_index s,st_index
    sequence kname
    
    for k = 1 to length(keylist) do 
	kname = keylist[k][K_NAME]
	len = length(kname)
	hashval = hashfn(kname)
	st_index = NewEntry(kname,
			    0, 
			    keylist[k][K_SCOPE], 
			    keylist[k][K_TOKEN],
			    hashval, 0, 0)
	if find(keylist[k][K_TOKEN], {r:PROC, r:FUNC, TYPE}) then
	    SymTab[st_index] = SymTab[st_index] & 
			repeat(0, SIZEOF_ROUTINE_ENTRY - 
				  length(SymTab[st_index]))         
	    SymTab[st_index][S_NUM_ARGS] = keylist[k][K_NUM_ARGS]
	    SymTab[st_index][S_OPCODE] = keylist[k][K_OPCODE]
	    SymTab[st_index][S_EFFECT] = keylist[k][K_EFFECT]
	    SymTab[st_index][S_REFLIST] = {}
	end if
	if keylist[k][K_TOKEN] = r:PROC then
	    if equal(kname, "_toplevel_") then
		TopLevelSub = st_index
	    -- begin mwl
		elsif equal(kname, "_eval_") then
			eval_sym = st_index
		-- end mwl
	    end if
	elsif keylist[k][K_TOKEN] = TYPE then
	    if equal(kname, "object") then
		object_type = st_index
	    elsif equal(kname, "atom") then
		atom_type = st_index
	    elsif equal(kname, "integer") then
		integer_type = st_index
	    elsif equal(kname, "sequence") then
		sequence_type = st_index
	    end if
	end if
	if buckets[hashval] = 0 then
	    buckets[hashval] = st_index
	else 
	    s = buckets[hashval]
	    while SymTab[s][S_SAMEHASH] != 0 do 
		s = SymTab[s][S_SAMEHASH]
	    end while
	    SymTab[s][S_SAMEHASH] = st_index
	end if
    end for
    file_start_sym = length(SymTab)
end procedure

global procedure add_ref(token tok)
-- BIND only: add a reference to a symbol from the current routine
    symtab_index s
    -- begin mwl
    if BIND or not execute then
		s = tok[T_SYM]
		if s != CurrentSub and -- ignore self-ref's
		   not find(s,  SymTab[CurrentSub][S_REFLIST]) then
		    -- new reference
	SymTab[s][S_NREFS] += 1
		    SymTab[CurrentSub][S_REFLIST] &= s
		end if  
    end if
    -- end mwl
end procedure

global procedure MarkTargets(symtab_index s, integer attribute)
-- Note the possible targets of a routine id call 
    symtab_index p
    sequence sname
    sequence string
    integer colon, h
    
    if (SymTab[s][S_MODE] = M_TEMP or
	SymTab[s][S_MODE] = M_CONSTANT) and 
	sequence(SymTab[s][S_OBJ]) then
	-- hard-coded string  
	string = SymTab[s][S_OBJ] 
	colon = find(':', string)
	if colon = 0 then
	    sname = string
	else 
	    sname = string[colon+1..$]  -- ignore namespace part
	    while length(sname) and sname[1] = ' ' or sname[1] = '\t' do
		sname = sname[2..$]
	    end while   
	end if
	
	-- simple approach - mark all names in hash bucket that match, 
	-- ignoring GLOBAL/LOCAL 
	h = buckets[hashfn(sname)]
	while h do
	    if equal(sname, SymTab[h][S_NAME]) then
		if attribute = S_NREFS then
		    add_ref({r:PROC, h}) 
		else
		    SymTab[h][attribute] += 1
		end if
	    end if
	    h = SymTab[h][S_SAMEHASH]
	end while           
    else 
	-- mark all visible routines parsed so far 
	p = SymTab[TopLevelSub][S_NEXT]
	while p != 0 do
	    if SymTab[p][S_FILE_NO] = current_file_no or
	       SymTab[p][S_SCOPE] = SC_GLOBAL then
		SymTab[p][attribute] += 1
	    end if
	    p = SymTab[p][S_NEXT]
	end while
    end if
end procedure

global sequence dup_globals

global function keyfind(sequence word, integer file_no)
-- Uses hashing algorithm to try to match 'word' in the symbol
-- table. If not found, 'word' must be a new user-defined identifier. 
-- If file_no is not -1 then file_no must match and symbol must be a GLOBAL. 
    integer hashval, scope, defined
    symtab_index st_ptr
    token tok, gtok

    dup_globals = {}
    hashval = hashfn(word)



    st_ptr = buckets[hashval] 

    while st_ptr do
		if equal(word, SymTab[st_ptr][S_NAME]) then
		    -- name matches 

		    tok = {SymTab[st_ptr][S_TOKEN], st_ptr}
		    
		    if file_no = -1 then
				-- unqualified  
				
				-- Consider: S_PREDEF 
				
				scope = SymTab[st_ptr][S_SCOPE]
				
				if scope = SC_GLOBAL then
				    if current_file_no = SymTab[st_ptr][S_FILE_NO] then
						-- found global in current file 
						add_ref(tok)
						return tok
				    end if
				    -- found global in another file 
				    gtok = tok
				    dup_globals &= st_ptr               
				    -- continue looking for more globals with same name 
				
				elsif scope = SC_LOCAL then 
				    if current_file_no = SymTab[st_ptr][S_FILE_NO] then
					-- found local in current file 
					add_ref(tok)
					return tok
					-- begin mwl
					elsif eval_file_no[$] = SymTab[st_ptr][S_FILE_NO] then
					add_ref(tok)
					return tok
					-- end mwl
				    end if
				
				elsif scope = SC_PREDEF then
				    if length(dup_globals) = 0 then
					add_ref(tok)
					return tok
				    end if
				    -- else a global has overridden this symbol 
				
				else 
				    add_ref(tok)
				    return tok -- keyword, private
				
				end if
		    
		    else 
				-- qualified - must match global symbol in specified file 
				if file_no = SymTab[tok[T_SYM]][S_FILE_NO] and
				    SymTab[tok[T_SYM]][S_SCOPE] = SC_GLOBAL then
				    add_ref(tok)
				    return tok 
				end if
		    end if
		    
		    -- otherwise keep looking 
else
if equal( word, "ECircle" ) then printf(1, "    no match: %d %s\n", {st_ptr, SymTab[st_ptr][S_NAME]} )  end if
		end if 

		st_ptr = SymTab[st_ptr][S_SAMEHASH]
    end while
    
    if length(dup_globals) = 1 then
		-- matched exactly one global
		add_ref(gtok)
		return gtok
    end if
    
    -- couldn't find unique one 
    if length(dup_globals) = 0 then
		defined = SC_UNDEFINED
    else
		defined = SC_MULTIPLY_DEFINED
    end if
    
    -- begin mwl
    if current_instance[$] then
    	defined = SC_PRIVATE
    end if
    -- end mwl
    tok = {VARIABLE, NewEntry(word, 0, defined, 
		       VARIABLE, hashval, buckets[hashval], 0)}
    buckets[hashval] = tok[T_SYM]
    return tok  -- no ref on newly declared symbol
end function


global procedure Hide(symtab_index s)
-- remove the visibility of a symbol
-- by deleting it from its hash chain 
    symtab_index prev, p

    p = buckets[SymTab[s][S_HASHVAL]]
    prev = 0
    while p != s and p != 0 do
		prev = p
		p = SymTab[p][S_SAMEHASH]
    end while
    if p = 0 then
		return -- already hidden 
    end if
    if prev = 0 then
		buckets[SymTab[s][S_HASHVAL]] = SymTab[s][S_SAMEHASH]
    else
		SymTab[prev][S_SAMEHASH] = SymTab[s][S_SAMEHASH]
    end if
end procedure

procedure LintCheck(symtab_index s)
-- do some lint-like checks on s 
    integer u, n
    sequence vtype, place, problem, file
    
    u = SymTab[s][S_USAGE]
    file = name_ext(file_name[current_file_no])
    
    if SymTab[s][S_SCOPE] = SC_LOCAL then
	if SymTab[s][S_MODE] = M_CONSTANT then
	    vtype = "local constant"
	else
	    vtype = "local variable"
	end if
	place = ""
    
    else  
	n = SymTab[CurrentSub][S_NUM_ARGS]
	if SymTab[s][S_VARNUM] < n then
	    vtype = "parameter"
	else
	    vtype = "private variable"
	end if
	place = SymTab[CurrentSub][S_NAME]
    
    end if
    
    problem = ""
    if u != or_bits(U_READ, U_WRITTEN) then
	if u = U_UNUSED or 
	     (u = U_WRITTEN and 
		(equal(vtype, "local constant") 
--               or equal(vtype, "parameter") -- this is rarely a real problem
		 ))
		 then
	    problem = "not used" 
	
	elsif u = U_READ then
	    problem = "never assigned a value"
	
	end if
	
	if length(problem) then
	    if length(place) then
		Warning(sprintf("%s %s in %s() in %s is %s", 
				   {vtype, SymTab[s][S_NAME], 
				   place, file, problem}))
	    else
		Warning(sprintf("%s %s in %s is %s", 
				   {vtype, SymTab[s][S_NAME], 
				   file, problem}))
	    end if
	end if
    end if
end procedure

-- begin mwl
global procedure HidePrivates( symtab_index sub, integer hide )
	symtab_index sym, s2
	integer hashval
	sym = SymTab[sub][S_NEXT]
	while sym and find(SymTab[sym][S_SCOPE], { SC_PRIVATE, SC_LOOP_VAR}) do
		hashval = SymTab[sym][S_HASHVAL]
		if hide then
			s2 = buckets[hashval]
			if s2 = sym then
				buckets[hashval] = SymTab[sym][S_SAMEHASH]
			else
				while SymTab[s2][S_SAMEHASH] do
					if SymTab[s2][S_SAMEHASH] = sym then
						SymTab[s2][S_SAMEHASH] = SymTab[sym][S_SAMEHASH]
						exit
					end if
					s2 = SymTab[s2][S_SAMEHASH]
				end while
			end if
		else
			SymTab[sym][S_SAMEHASH] = buckets[hashval]
			buckets[hashval] = sym
		end if
		sym = SymTab[sym][S_NEXT]
	end while
end procedure
-- end mwl

global procedure HideLocals()
-- hide the local symbols and "lint" check them
    symtab_index s

    s = file_start_sym
    while s do 
	if SymTab[s][S_SCOPE] = SC_LOCAL and 
	   SymTab[s][S_FILE_NO] = current_file_no then
	    Hide(s)
	    if SymTab[s][S_TOKEN] = VARIABLE then
		LintCheck(s)
	    end if
	end if
	s = SymTab[s][S_NEXT]
    end while
end procedure

global procedure ExitScope()
-- delete all the private scope entries for the current routine 
-- and "lint" check them
    symtab_index s

    s = SymTab[CurrentSub][S_NEXT]
    while s and SymTab[s][S_SCOPE] = SC_PRIVATE do
		Hide(s) 
		LintCheck(s)
	
		s = SymTab[s][S_NEXT]

    end while
    
    -- begin mwl
    -- Hide the members.  They show up in the symbol table without
    -- qualifiers, and just cause problems
    for i = 1 to length(hide_member[$]) do
    	Hide( hide_member[$][i] )
    end for
    hide_member = hide_member[1..$-1]
    -- end mwl
end procedure

-- begin mwl
global function new_class( symtab_index sym )
	integer class_ix, parent, mx
	symtab_index vtype
	sequence entry

	for i = 1 to CLASS_ENTRY do
		class_table[i] = append( class_table[i], {} )
	end for
	class_ix = length(class_table[1])
	
	class_table[CLASS_NAME][class_ix] = SymTab[sym][S_NAME]
	vtype = SymTab[sym][S_VTYPE]
	class_table[CLASS_VARTYPE][class_ix] = vtype
	class_table[CLASS_PARENT][class_ix] = find( vtype, class_table[CLASS_SYM] )
	if find( vtype, class_table[CLASS_SYM] ) then
		if vtype = class_ix then
			CompileErr("a class must be of a distinct type")
			return 0
		end if
		add_ref( {CLASS, vtype})
		parent = class_table[CLASS_PARENT][class_ix]
		-- reference the members...
		for i = 1 to length(member_table[1]) do
--			if member_table[MEMBER_CLASS][i] = parent then
--				print(2, member_table[MEMBER_NAME][i] ) puts(2,"\n")
--				add_ref( {0, member_table[MEMBER_SYM][i]})
--			end if
		end for
	end if
	class_table[CLASS_SYM][class_ix] = sym
	class_table[CLASS_SEQUENCEOF][class_ix] = 0
	return class_ix
end function

global function is_sequenceof( symtab_index sym )
	integer class
	symtab_index type_sym
	if not sym then
		return 0
	end if
	type_sym = SymTab[sym][S_VTYPE]
	class = find( type_sym, class_table[CLASS_SYM] )
	if not class then
		return 0
	end if
	
	return class_table[CLASS_NAME][class][1] = '_'
end function

global function member_stack_is_sequenceof()
	integer ms, class
	
	ms = length(member_stack)
	while ms and member_stack[ms] < 0 do
		ms -= 1
	end while
	
	if ms = 0  or member_stack[ms] = 0 then
		return 0
	end if
	
	-- here is the member:
	ms = member_table[MEMBER_SYM][member_stack[ms]]
	class = find( SymTab[ms][S_VTYPE], class_table[CLASS_SYM] )
	if not class then
		return 0
	end if
	
	return class_table[CLASS_NAME][class][1] = '_'
end function

global function member_is_sequenceof( integer member )
	integer class
	if member <= 0 then
		return 0
	end if
	
	class = find(member_table[MEMBER_VARTYPE][member], class_table[CLASS_SYM] )
	if class and class_table[CLASS_NAME][class][1] = '_' then
		return 1
	end if
	return 0
end function

-- convert between sequence of and normal...
global function sequence_of_class( integer class )
	integer soc
	if not class then
		return 0
	end if
	soc = class_table[CLASS_SEQUENCEOF][class]
	if not soc then
		-- add a new euclass type...
		SymTab = append( SymTab, SymTab[class_table[CLASS_SYM][class]] )
		SymTab[$][S_NAME] = prepend( SymTab[$][S_NAME], '_' )
	    if last_sym then
			SymTab[last_sym][S_NEXT] = length(SymTab)
	    end if
	    last_sym = length(SymTab)
	    soc = new_class( last_sym )
	    class_table[CLASS_SEQUENCEOF][class] = soc
	    class_table[CLASS_SEQUENCEOF][soc] = class
	end if
	return soc
end function

-- returns a class index from its sym
global function sym_to_class( symtab_index sym )
	return find( sym, class_table[CLASS_SYM] )
end function

global function var_class( symtab_index sym )
	if length(SymTab[sym]) < S_VTYPE then
		return 0
	end if
	return find( SymTab[sym][S_VTYPE], class_table[CLASS_SYM] )
end function

global procedure add_method( symtab_index sym )
	integer method, ix
	sequence decorated, alist
	
	for i = 1 to METHOD_ENTRY do
		method_table[i] = append( method_table[i], {} )
	end for
	
	decorated = SymTab[sym][S_NAME]
	method = length(method_table[1])
	method_table[METHOD_NAME][method] = decorated
	method_table[METHOD_CLASS][method] = current_class
	method_table[METHOD_SYM][method] = sym

	class_table[CLASS_METHOD][current_class] &= method

	-- strip off the 'this' parameter
	ix = find( '@', decorated )
	
	if compare( decorated[1..ix-1], class_table[CLASS_NAME][current_class]) then
		-- make sure it's not a constructor, in which case there's no 'this'
		decorated = decorated[ix+1..$]
		ix = find( '@', decorated )
		decorated = decorated[ix+1..$]
		
	else
		decorated = decorated[ix+1..$]
		
	end if

	alist = {}

	-- now parse the arglist
	while length( decorated ) do
		if decorated[1] = '@' then
			decorated = decorated[2..$]
			ix = find( '@', decorated )
			alist = append( alist, '@' & decorated[1..ix] )
			decorated = decorated[ix+1..$]
			
		elsif decorated[1] = '!' then
			decorated = decorated[2..$]
			ix = find( '!', decorated )
			alist = append( alist, '!' & decorated[1..ix] )
			decorated = decorated[ix+1..$]			
		else
			alist = append( alist, {decorated[1]})
			decorated = decorated[2..$]
			
		end if
	end while
	
	method_table[METHOD_ARGLIST][method] = alist
end procedure

global function member_count( integer class )
	integer count
	sequence classes
	if class = 0 then
		return 0
	end if
	count = member_count( class_table[CLASS_PARENT][class] )
	classes = member_table[MEMBER_CLASS]
	for i = 1 to length(classes) do
		if classes[i] = class then
			count += 1
		end if
	end for
	return count
end function

global function add_member( symtab_index sym )
	integer class, mx
	
	class = current_class
	-- enlarge the table
	for i = 1 to MEMBER_ENTRY do
		member_table[i] &= {{}}
	end for
	mx = length(member_table[1])
	
	member_table[MEMBER_NAME][mx] = SymTab[sym][S_NAME]
	member_table[MEMBER_CLASS][mx] = class
	member_table[MEMBER_VARTYPE][mx] = SymTab[sym][S_VTYPE]
	SymTab[sym][S_OBJ] = member_count( class )
	SymTab[sym][S_SCOPE] = SC_GLOBAL
	SymTab[sym][S_MODE] = M_CONSTANT
	member_table[MEMBER_SYM][mx] = sym
	return mx
end function

global function is_member( token tok )
	symtab_index sym, classtype
	integer class, ix
	sequence name, members
	
	sym = tok[T_SYM]
	class = 0
	if member_stack[$] > 0 then
		classtype = member_table[MEMBER_VARTYPE][member_stack[$]]
		class = find( classtype, class_table[CLASS_SYM] )
	elsif member_stack[$] < 0 then
		-- 'sequence of' subscripted member
		ix = length(member_stack)
		while ix and member_stack[ix] < 0 do
			ix -= 1
		end while
		if not ix then
			return 0
		end if
		if member_stack[ix] then
			classtype = member_table[MEMBER_VARTYPE][member_stack[ix]]
			
		else
			
			
			if length( SymTab[current_instance[$]] ) = 5 then
				-- it's a sequence of...
				
			else
				-- works when instance isn't a sequence of
				classtype = SymTab[current_instance[$]][S_VTYPE]
			end if
			
			
		end if
		class = find( classtype, class_table[CLASS_SYM] )
		
	elsif current_instance[$] then
		-- could be a class itself...
		class = find( current_instance[$], class_table[CLASS_SYM] )
		if not class then
			classtype = SymTab[current_instance[$]][S_VTYPE]
			class = find( classtype, class_table[CLASS_SYM] )
		end if
		
	end if
	

	while class do
		if class_table[CLASS_NAME][class][1] = '_' then
			class = class_table[CLASS_SEQUENCEOF][class]
		end if
		members = member_table[MEMBER_CLASS]
		name = SymTab[sym][S_NAME]
		for i = 1 to length(members) do
			if members[i]  = class then
				if equal( name, member_table[MEMBER_NAME][i] ) then
					add_ref( {0, member_table[MEMBER_SYM][i]} )
					SymTab[member_table[MEMBER_SYM][i]][S_USAGE] = U_READ
					SymTab[sym][S_USAGE] = U_WRITTEN
					return i
				end if
			end if
		end for		
		class = class_table[CLASS_PARENT][class]
	end while
	return 0
end function
-- end mwl
