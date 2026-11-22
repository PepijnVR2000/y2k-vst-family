#pragma once

// Version and build identification for every plugin in the family.
// lp_core/BuildInfo.h is generated at build time by cmake/GenerateBuildInfo.cmake.

#include <lp_core/BuildInfo.h>

#include <string>

namespace lp
{
inline const char* versionString() noexcept { return build::version; }
inline const char* buildHash() noexcept { return build::gitHash; }

// "0.1.0 (abcd1234)"
inline std::string versionWithHash()
{
    return std::string (build::version) + " (" + build::gitHash + ")";
}

} // namespace lp
