<#
.SYNOPSIS
    Install the plugins from a local build into the system plugin folders.

.DESCRIPTION
    1. Checks that FL Studio is not running (it locks loaded plugin DLLs).
    2. Takes every *.vst3 bundle and *.clap file from
       <BuildDir>\plugins\*\*_artefacts\<Config>\{VST3,CLAP}.
    3. Copies them to C:\Program Files\Common Files\VST3 and \CLAP
       (asks for administrator rights for the copy only).

    Same destinations as scripts\get-latest.ps1, so a local build simply
    replaces a CI build (same plugin ids, no duplicates in FL).
    Works in Windows PowerShell 5.1 and PowerShell 7.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\install-local.ps1
.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\install-local.ps1 -Config Debug
#>
[CmdletBinding()]
param(
    # Same default as scripts\build-local.ps1 (short path, see there).
    [string]$BuildDir = "$env:LOCALAPPDATA\lpb",
    [string]$Config = "Release",
    [string]$Vst3Dir = "$env:CommonProgramW6432\VST3",
    [string]$ClapDir = "$env:CommonProgramW6432\CLAP",
    [switch]$Force   # skip the FL Studio check
)

$ErrorActionPreference = "Stop"

function Fail($message) {
    Write-Host "ERROR: $message" -ForegroundColor Red
    exit 1
}

if (-not $Force) {
    $fl = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match '^FL(64)?$|^FL Studio' }
    if ($fl) {
        Fail "FL Studio is running ($($fl[0].ProcessName)). Close it first: it locks loaded plugins. (Use -Force to skip this check.)"
    }
}

$pluginsDir = Join-Path $BuildDir "plugins"
if (-not (Test-Path $pluginsDir)) { Fail "No build found at '$pluginsDir'. Build first (see HANDOFF.md)." }

$vst3 = @()
$clap = @()
foreach ($artefacts in Get-ChildItem -Path $pluginsDir -Recurse -Directory -Filter "*_artefacts") {
    $vst3 += @(Get-ChildItem -Path (Join-Path $artefacts.FullName "$Config\VST3") -Filter *.vst3 -Directory -ErrorAction SilentlyContinue)
    $clap += @(Get-ChildItem -Path (Join-Path $artefacts.FullName "$Config\CLAP") -Filter *.clap -File -ErrorAction SilentlyContinue)
}
if ($vst3.Count -eq 0 -and $clap.Count -eq 0) { Fail "No $Config .vst3 or .clap found under '$pluginsDir'." }

$lines = @(
    '$ErrorActionPreference = "Stop"',
    "New-Item -ItemType Directory -Force -Path '$Vst3Dir' | Out-Null",
    "New-Item -ItemType Directory -Force -Path '$ClapDir' | Out-Null"
)
foreach ($b in $vst3) {
    $dest = Join-Path $Vst3Dir $b.Name
    # Remove the old bundle first; copying a folder onto an existing one nests it.
    $lines += "if (Test-Path -LiteralPath '$dest') { Remove-Item -LiteralPath '$dest' -Recurse -Force }"
    $lines += "Copy-Item -LiteralPath '$($b.FullName)' -Destination '$Vst3Dir' -Recurse -Force"
}
foreach ($f in $clap) {
    $lines += "Copy-Item -LiteralPath '$($f.FullName)' -Destination '$ClapDir' -Force"
}

$temp = Join-Path ([System.IO.Path]::GetTempPath()) ("lp-install-" + [guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $temp | Out-Null
$installScript = Join-Path $temp "install.ps1"
Set-Content -Path $installScript -Value $lines -Encoding UTF8

$isAdmin = ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole(
    [Security.Principal.WindowsBuiltInRole]::Administrator)

if ($isAdmin) {
    & $installScript
} else {
    Write-Host "Asking for administrator rights to write to Common Files ..."
    $p = Start-Process -FilePath "powershell.exe" -Verb RunAs -Wait -PassThru `
        -ArgumentList @("-NoProfile", "-ExecutionPolicy", "Bypass", "-File", "`"$installScript`"")
    if ($p.ExitCode -ne 0) { Fail "Install step failed (exit code $($p.ExitCode))." }
}
Remove-Item -LiteralPath $temp -Recurse -Force -ErrorAction SilentlyContinue

foreach ($b in $vst3) { Write-Host "Installed VST3: $(Join-Path $Vst3Dir $b.Name)" -ForegroundColor Green }
foreach ($f in $clap) { Write-Host "Installed CLAP: $(Join-Path $ClapDir $f.Name)" -ForegroundColor Green }
Write-Host "Local $Config build installed. In FL Studio: Options > Manage plugins > Find more plugins (rescan) if it is new."
