cmake_minimum_required(VERSION 2.6)
project(bin_game2)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

file(GLOB sources "src/controller/*.cpp",
    "src/model/*.cpp", "src/view/*.cpp", "src/util/*.cpp",
    "src/*.cpp")

file(GLOB console "src/console/*.cpp")

file(GLOB bot "src/bot/*.cpp")

file(GLOB gui "src/gui/*.cpp")

include_directories(src/console)
include_directories(src/controller)
include_directories(src/model)
include_directories(src/view)
include_directories(src/util)
include_directories(src/gui)
include_directories(src)

add_executable(bin_game_console ${sources} ${console})
target_link_libraries(bin_game_console ${QT_LIBRARIES})

set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR})
include(FindLua51)
find_package(Lua51 REQUIRED)
find_package(Luabind REQUIRED)

if (LUA51_FOUND)
    if (LUABIND_FOUND)
        add_definitions(-DLUA_COMPAT_ALL)

        include_directories(${LUA_INCLUDE_DIR})
        include_directories(${LUABIND_INCLUDE_DIRS})

        add_executable(bin_game_bot ${sources} ${bot})
        target_link_libraries(bin_game_bot
            ${LUA_LIBRARIES} ${LUABIND_LIBRARIES}
            ${QT_LIBRARIES})
        configure_file(
            ${CMAKE_CURRENT_SOURCE_DIR}/src/bot/bin_game_bot.lua
            ${CMAKE_CURRENT_BINARY_DIR}/bin_game_bot.lua)
    endif()
endif()

include_directories("${PROJECT_SOURCE_DIR}/src/gui"
    "${PROJECT_BINARY_DIR}/src/gui"
    "${PROJECT_BINARY_DIR}")

file(GLOB uis "src/gui/*.ui")
file(GLOB qheaders "src/gui/*.hpp")

QT4_WRAP_UI(UISrcs ${uis})
QT4_WRAP_CPP(MOCrcs ${qheaders})
QT4_ADD_RESOURCES(RCSrcs "src/gui/qbin_game.qrc")

add_executable(bin_game_gui ${sources} ${gui} ${UISrcs}
    ${MOCrcs} ${RCSrcs})
target_link_libraries(bin_game_gui ${QT_LIBRARIES})
