# lp_core: code shared by every plugin in the family.
#
#   lp_core_dsp  header-only, NO JUCE dependency (unit-testable, portable):
#                include/lp_core/dsp/*.h
#   lp_core      JUCE-side helpers (parameters, placeholder editor, build info)
#                + lp_core_dsp. INTERFACE library: its sources are compiled into
#                each consumer (plugin shared code, tests).

add_library(lp_core_dsp INTERFACE)
target_include_directories(lp_core_dsp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(lp_core_dsp INTERFACE cxx_std_20)

# Build info (version + git hash), regenerated on every build ----------------
set(LP_GENERATED_DIR ${CMAKE_BINARY_DIR}/generated)
set(LP_BUILD_INFO_HEADER ${LP_GENERATED_DIR}/lp_core/BuildInfo.h)

add_custom_target(lp_build_info
    COMMAND ${CMAKE_COMMAND}
        -DSOURCE_DIR=${PROJECT_SOURCE_DIR}
        -DOUTPUT=${LP_BUILD_INFO_HEADER}
        -DVERSION=${PROJECT_VERSION}
        -P ${PROJECT_SOURCE_DIR}/cmake/GenerateBuildInfo.cmake
    BYPRODUCTS ${LP_BUILD_INFO_HEADER}
    COMMENT "Updating build info"
    VERBATIM)

add_library(lp_core INTERFACE)
add_dependencies(lp_core lp_build_info)
target_sources(lp_core INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/source/PlaceholderEditor.cpp)
target_include_directories(lp_core INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${LP_GENERATED_DIR})
target_link_libraries(lp_core INTERFACE
    lp_core_dsp
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_gui_basics)
target_compile_definitions(lp_core INTERFACE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_MODAL_LOOPS_PERMITTED=0)
