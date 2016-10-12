// the actually needed header file
#include <lua.h>
#include <stdio.h>

// here is the program written in c, which shall be later called in lua
int iprinthellon(lua_State *L){
    float ret = lua_tonumber(L,-1);
    printf("Hello%lf",ret);
    
    // the following as the ret value of the lua function 
    // printhellon
    lua_pushnumber(L,12);

    // the ret value below is the number of ret values in lua!
    return 1;
}

// here register the function for future .lua program use
int luaopen_part(lua_State *L){
    // the following function means that 
    //+ when calling printhello in .lua, 
    //+ iprinthellon(L,..) is called in .c
    lua_register(L,"printhellon",iprinthellon);
    return 0;
}

// some functions need to be cared..
// push is to push to stack, to is to read from stack. pop is 
// to remove n elements from stack.
// pushvalue is to push a value of idx at top, insert is to 
// move the top element to given idx.
//
// lua_push*, lua_to*, lua_is*, luaopen_*module*, lua_open
//
// lua_isstring checks if the element in the stack can be
// turned into string, that is a number in the stack is also
// a "string", and vice-versa.
//
// another function lua_strlen()..
//
// the idx in function defs means the offset in the stack.
// -1 means the last pushed element, 1 means the first pushed  
// element.
//
// C can also get vars from lua by function lua_getglobal
// & lua_gettable, note usage of lua_gettable:
// first idx=-1 shall be the table, then push the key of 
// the element, call lua_gettable by idx=-2, then L-1 is 
// the value of the key. read and pop -1 to finish reading.
//
// using lua_pcall to call function defined in .lua
// first lua_getglobal the function name, then push 
// the arguments from right to left. then call lua_pcall
// with arguments: L, totalarg, totalret, idx of errhandler.
// if err, a errormess will be on L.
//
