# lp_add_instrument(): one call per plugin in the family.
#
# Creates
#   <TARGET>_common  INTERFACE library with the plugin's sources + JUCE modules,
#                    linked by the plugin AND by the tests (so tests exercise the
#                    exact same processor code without going through a host);
#   <TARGET>         JUCE plugin (VST3 + Standalone) + <TARGET>_CLAP.
#
# lp_add_instrument(TARGET lp_disc1
#     PRODUCT_NAME "LP Disc 1 (dev)" PLUGIN_CODE Ld01 ID_SUFFIX disc1
#     DESCRIPTION "..." SOURCES a.cpp b.cpp
#     CLAP_FEATURES instrument synthesizer mono)

function(lp_add_instrument)
    cmake_parse_arguments(ARG "" "TARGET;PRODUCT_NAME;PLUGIN_CODE;ID_SUFFIX;DESCRIPTION"
                          "SOURCES;CLAP_FEATURES" ${ARGN})

    # File/bundle name: JUCE's VST3 post-build step does not quote paths, so
    # characters such as "(" break the build. The host-visible name
    # (PLUGIN_NAME) keeps them: "LP Disc 1 (dev)" -> file "LP Disc 1 dev.vst3".
    string(REGEX REPLACE "[][()]" "" file_name "${ARG_PRODUCT_NAME}")
    string(REGEX REPLACE " +" " " file_name "${file_name}")
    string(STRIP "${file_name}" file_name)

    set(common ${ARG_TARGET}_common)
    add_library(${common} INTERFACE)
    target_sources(${common} INTERFACE ${ARG_SOURCES})
    target_include_directories(${common} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/source)
    target_compile_definitions(${common} INTERFACE
        LP_PLUGIN_NAME="${ARG_PRODUCT_NAME}")
    target_link_libraries(${common} INTERFACE lp_core)

    juce_add_plugin(${ARG_TARGET}
        PLUGIN_NAME             "${ARG_PRODUCT_NAME}"
        PRODUCT_NAME            "${file_name}"
        COMPANY_NAME            "${LP_COMPANY_NAME}"
        COMPANY_WEBSITE         "${LP_COMPANY_WEBSITE}"
        BUNDLE_ID               "${LP_BUNDLE_ID_PREFIX}.${ARG_ID_SUFFIX}"
        DESCRIPTION             "${ARG_DESCRIPTION}"
        PLUGIN_MANUFACTURER_CODE ${LP_MANUFACTURER_CODE}
        PLUGIN_CODE             ${ARG_PLUGIN_CODE}
        VERSION                 ${PROJECT_VERSION}
        FORMATS                 VST3 Standalone
        IS_SYNTH                TRUE
        NEEDS_MIDI_INPUT        TRUE
        NEEDS_MIDI_OUTPUT       FALSE
        IS_MIDI_EFFECT          FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        VST3_CATEGORIES         Instrument Synth
        COPY_PLUGIN_AFTER_BUILD ${LP_COPY_PLUGIN_AFTER_BUILD})

    target_link_libraries(${ARG_TARGET}
        PRIVATE
            ${common}
        PUBLIC
            juce::juce_recommended_config_flags
            juce::juce_recommended_lto_flags
            juce::juce_recommended_warning_flags)

    clap_juce_extensions_plugin(TARGET ${ARG_TARGET}
        CLAP_ID       "${LP_BUNDLE_ID_PREFIX}.${ARG_ID_SUFFIX}"
        CLAP_FEATURES ${ARG_CLAP_FEATURES})
endfunction()
