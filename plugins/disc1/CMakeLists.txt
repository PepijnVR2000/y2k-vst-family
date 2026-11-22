# Disc 1: first instrument shell. All names come from cmake/Names.cmake.

lp_add_instrument(
    TARGET        ${LP_DISC1_TARGET}
    PRODUCT_NAME  "${LP_DISC1_PRODUCT_NAME}"
    PLUGIN_CODE   ${LP_DISC1_PLUGIN_CODE}
    ID_SUFFIX     ${LP_DISC1_ID_SUFFIX}
    DESCRIPTION   "${LP_DISC1_DESCRIPTION}"
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/PluginProcessor.cpp
    CLAP_FEATURES instrument synthesizer mono)
