# Third-party dependencies, pinned to exact commits.
#
# Each dependency is fetched shallowly by tag where possible and the checked-out
# commit is verified against the expected hash, so a moved tag fails the
# configure step instead of silently changing the build.
#
# Local override (e.g. an existing JUCE checkout):
#   cmake -DFETCHCONTENT_SOURCE_DIR_JUCE=/path/to/JUCE ...
# The commit check is skipped for overridden sources.

# Optional persistent download dir (used by CI caching). Relative paths are
# resolved against the source dir, so "-DLP_DEPS_DIR=.cache/deps" survives a
# deleted build dir.
set(LP_DEPS_DIR "" CACHE STRING "Persistent FetchContent base dir (relative to the source dir)")
if(LP_DEPS_DIR)
    cmake_path(ABSOLUTE_PATH LP_DEPS_DIR BASE_DIRECTORY "${CMAKE_SOURCE_DIR}" NORMALIZE
               OUTPUT_VARIABLE lp_deps_abs)
    set(FETCHCONTENT_BASE_DIR "${lp_deps_abs}" CACHE PATH "" FORCE)
endif()

include(FetchContent)

set(FETCHCONTENT_QUIET ON)
# Pinned commits never change, so do not hit the network on every reconfigure.
set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "" FORCE)

function(lp_verify_commit name expected)
    string(TOUPPER "${name}" upper)
    if(FETCHCONTENT_SOURCE_DIR_${upper})
        message(STATUS "${name}: using local override ${FETCHCONTENT_SOURCE_DIR_${upper}} (commit not verified)")
        return()
    endif()
    FetchContent_GetProperties(${name} SOURCE_DIR src)
    execute_process(COMMAND git rev-parse HEAD
        WORKING_DIRECTORY "${src}"
        OUTPUT_VARIABLE actual OUTPUT_STRIP_TRAILING_WHITESPACE
        RESULT_VARIABLE rv)
    if(NOT rv EQUAL 0 OR NOT actual STREQUAL expected)
        message(FATAL_ERROR "${name}: expected commit ${expected}, got '${actual}'. "
                            "The upstream tag moved or the checkout is broken.")
    endif()
    message(STATUS "${name}: verified commit ${expected}")
endfunction()

# JUCE 9.0.6 (latest stable tag on 2026-11-22) ------------------------------
set(LP_JUCE_TAG    "9.0.6")
set(LP_JUCE_COMMIT "654bdbc7a9db0dae90849b44abe91f339e9f0768")

FetchContent_Declare(JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        ${LP_JUCE_TAG}
    GIT_SHALLOW    TRUE)

# clap-juce-extensions (free-audio). Its last tag (0.26.0, 2022) predates
# JUCE 8/9 support, so it is pinned to a main commit (2026-11-16, clap 1.2.10).
set(LP_CJE_COMMIT "3837f4a6ed2ab0ba46aba69ae5b7041c7c64ce74")

FetchContent_Declare(clap-juce-extensions
    GIT_REPOSITORY https://github.com/free-audio/clap-juce-extensions.git
    GIT_TAG        ${LP_CJE_COMMIT}
    GIT_SUBMODULES_RECURSE TRUE
    EXCLUDE_FROM_ALL)

# EXCLUDE_FROM_ALL (CMake 3.28+): only build the targets we actually link.
FetchContent_MakeAvailable(JUCE clap-juce-extensions)
lp_verify_commit(JUCE ${LP_JUCE_COMMIT})
lp_verify_commit(clap-juce-extensions ${LP_CJE_COMMIT})

# Catch2 v3.9.1 (tests only) ----------------------------------------------------
if(LP_BUILD_TESTS)
    set(LP_CATCH2_TAG    "v3.9.1")
    set(LP_CATCH2_COMMIT "644821ce28cb25d7992a4d0375b1d83214392592")
    FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        ${LP_CATCH2_TAG}
        GIT_SHALLOW    TRUE
        EXCLUDE_FROM_ALL)
    FetchContent_MakeAvailable(Catch2)
    lp_verify_commit(Catch2 ${LP_CATCH2_COMMIT})
endif()
