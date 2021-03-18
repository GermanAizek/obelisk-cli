#include "luafuncs.h"
#include "luascript.h"

#include "fstream"

Script script;

int createGroup(lua_State* luaState)
{
    script.Array();
    script.RegisterArray(script.GetArgument<char*>(1));
    return 1;
}

int createAnswer(lua_State* luaState)
{
    std::fstream outconf("extensions.conf");
    outconf << "exten => " << script.GetArgument<char*>(1) << ", 1, Answer";

    return 1;
}

int printConsole(lua_State* luaState)
{
        for (size_t i = 1; i < script.GetArgumentCount() + 1; ++i)
                std::cout << script.GetArgument<char*>(i);

        return 0;
}
