#ifndef LUASCRIPT_H
#define LUASCRIPT_H

#include <iostream>
#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class Script
{
    lua_State *lua_state;

public:
    lua_State* Create();
    void Close();
    int DoFile(std::string ScriptFileName);
    template<class T>
    void RegisterConstant(T value, char* constantname);

    void Array();

    template<class T>
    void RegisterConstantArray(T value, int index);
    void RegisterArray(char* arrayname);

    template<class T>
    void RegisterFieldGlobal(T value, std::string text);

    int GetArgumentCount();
    template<class T>
    T GetArgument(int index);
    template<class T>
    void Return(T value);
};

#endif // LUASCRIPT_H
