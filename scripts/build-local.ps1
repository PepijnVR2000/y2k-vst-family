<#
.SYNOPSIS
    Build the plugins locally (Visual Studio 2022), run the tests, and install
    them for FL Studio.

.DESCRIPTION
    1. Finds CMake (PATH, or the copy that ships with Visual Studio 2022).
    2. Configures once, builds -Config, runs the Catch2 tests.
    3. Unless -NoInstall: runs scripts\install-local.ps1 (FL Studio must be
       closed; asks for administrator rights for the copy).

    The build directory defaults to %LOCALAPPDATA%\lpb, NOT <repo>\build:
    MSBuild fails on paths over 260 characters, and a repo in a deep folder
    gets there quickly. Dependencies are kept in %LOCALAPPDATA%\lpdeps so a
    deleted build directory does not download JUCE again.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\build-local.ps1
.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\build-local.ps1 -NoInstall
#>
[CmdletBinding()]
param(
    [string]$BuildDir = "$env:LOCALAPPDATA\lpb",
    [string]$DepsDir = "$env:LOCALAPPDATA\lpdeps",
    [string]$Config = "Release",
    [switch]$NoTests,
    [switch]$NoInstall
)

$ErrorActionPreference = "Stop"
$repo = Resolve-Path (Join-Path $PSScriptRoot "..")

function Fail($message) {
    Write-Host "ERROR: $message" -ForegroundColor Red
    exit 1
}

# 1. CMake ---------------------------------------------------------------------
if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    $vsPath = if (Test-Path $vswhere) {
        & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    }
    $vsCmake = if ($vsPath) { Join-Path $vsPath "Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin" }
    if (-not $vsCmake -or -not (Test-Path (Join-Path $vsCmake "cmake.exe"))) {
        Fail "CMake not found. Install Visual Studio 2022 with 'Desktop development with C++'."
    }
    $env:Path = "$vsCmake;$env:Path"
}

# 2. Configure (first time only), build, test -----------------------------------
if (-not (Test-Path (Join-Path $BuildDir "CMakeCache.txt"))) {
    Write-Host "Configuring in $BuildDir (first time: downloads JUCE, takes a few minutes) ..."
    cmake -S $repo -B $BuildDir -G "Visual Studio 17 2022" -A x64 "-DLP_DEPS_DIR=$DepsDir"
    if ($LASTEXITCODE -ne 0) { Fail "Configure failed." }
}

Write-Host "Building $Config ..."
cmake --build $BuildDir --config $Config --parallel -- /m /v:minimal /nologo
if ($LASTEXITCODE -ne 0) { Fail "Build failed." }

if (-not $NoTests) {
    ctest --test-dir $BuildDir -C $Config --output-on-failure
    if ($LASTEXITCODE -ne 0) { Fail "Tests failed; not installing." }
}

# 3. Install ---------------------------------------------------------------------
if (-not $NoInstall) {
    & (Join-Path $PSScriptRoot "install-local.ps1") -BuildDir $BuildDir -Config $Config
    if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
}
