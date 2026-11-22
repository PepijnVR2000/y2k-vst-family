cmake_minimum_required(VERSION 3.28)

include(cmake/Names.cmake)

project(${LP_FAMILY_NAME}Family VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Windows x64 is the primary target. Use the static MSVC runtime so the plugin
# does not depend on the user's installed VC++ redistributable.
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

option(LP_BUILD_TESTS "Build the test suite" ON)
option(LP_COPY_PLUGIN_AFTER_BUILD "Copy plugins to the user plugin folders after build" OFF)

include(cmake/Dependencies.cmake)
include(cmake/LpPlugin.cmake)

add_subdirectory(libs/lp_core)
add_subdirectory(plugins/disc1)

if(LP_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
