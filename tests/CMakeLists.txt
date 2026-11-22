# lp_tests: Catch2 suite. Links the plugins' *_common libraries, so the tests
# exercise exactly the processor code that ships, without a host.

juce_add_console_app(lp_tests PRODUCT_NAME "lp_tests")

target_sources(lp_tests PRIVATE
    main.cpp
    AllocationGuard.cpp
    DspTests.cpp
    Disc1Tests.cpp)

target_include_directories(lp_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(lp_tests
    PRIVATE
        ${LP_DISC1_TARGET}_common
        Catch2::Catch2
        juce::juce_recommended_config_flags)
# (No juce_recommended_warning_flags here: tests compare floats exactly on
# purpose, which -Wfloat-equal would flag.)

# The plugin target name is only known here through Names.cmake.
target_compile_definitions(lp_tests PRIVATE LP_PLUGIN_NAME_EXPECTED="${LP_DISC1_PRODUCT_NAME}")

include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)
catch_discover_tests(lp_tests DISCOVERY_MODE PRE_TEST)
