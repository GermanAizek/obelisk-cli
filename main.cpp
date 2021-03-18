#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <vector>

#include "luascript.h"
#include "luafuncs.h"

void print_help()
{
    std::cout << "Example usage:\n obelisk main.lua\n";
}

int main(int argc, char *argv[])
{
    if (argc < 1) {
        print_help();
    }

//    std::string filename;
//    for (int i = 0; i < argc; i++) {
//        filename = argv[i];
//        int pos = filename.find(".lua");
//        if (pos < 0) {
//            print_help();
//            return 1;
//        }
//    }
    lua_State* luaState = script.Create();
    script.RegisterConstant<lua_CFunction>(createGroup,  "CreateGroup");
    script.RegisterConstant<lua_CFunction>(createAnswer,  "Answer");
    script.RegisterConstant<lua_CFunction>(printConsole, "print");
    script.DoFile("groups.lua");
    script.DoFile("group_props.lua");
    script.DoFile("extensions.lua");


    std::fstream outconf("extensions.conf");
    outconf << "";

    return 0;
}
