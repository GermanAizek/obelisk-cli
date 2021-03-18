cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

project(obelisk)

#include(FindPackageHandleStandardArgs.cmake)
#include(FindLua.cmake)

if(NOT DEFINED LUA_INCLUDE_DIR OR NOT DEFINED LUA_LIBRARIES)
    find_package(Lua REQUIRED)
endif()

include_directories(${LUA_INCLUDE_DIR})
add_executable(${PROJECT_NAME} main.cpp luascript.cpp luascript.h luafuncs.cpp luafuncs.h dict.h)
target_link_libraries(${PROJECT_NAME} PUBLIC ${LUA_LIBRARIES})

#include_directories("LuaBridge/Source")
# target_include_directories(LuaBridge INTERFACE .)
# target_include_directories(Lua/Lua.5.2.0/src INTERFACE .))

