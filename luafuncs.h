#ifndef LUAFUNCS_H
#define LUAFUNCS_H

#include "luascript.h"

extern Script script;

int createGroup(lua_State* luaState);
int createAnswer(lua_State* luaState);
int printConsole(lua_State* luaState);

#endif // LUAFUNCS_H
