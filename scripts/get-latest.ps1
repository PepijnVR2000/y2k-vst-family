<#
.SYNOPSIS
    Download the latest successful Windows build from GitHub Actions and install
    the VST3 + CLAP plugins.

.DESCRIPTION
    1. Checks that FL Studio is not running (it locks loaded plugin DLLs).
    2. Finds the latest successful run of the "build" workflow on -Branch and
       downloads its "lp-windows-x64-<sha>" artifact with the GitHub CLI (gh).
    3. Copies *.vst3 to  C:\Program Files\Common Files\VST3
       and     *.clap to C:\Program Files\Common Files\CLAP
       (asks for administrator rights for the copy only).
    4. Prints the commit the build came from.

    Needs: GitHub CLI (https://cli.github.com), logged in once with `gh auth login`.
    Works in Windows PowerShell 5.1 and PowerShell 7.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\get-latest.ps1
.EXAMPLE
    powershell -ExecutionPolicy Bypass -File scripts\get-latest.ps1 -Branch claude/skeleton-ci
#>
[CmdletBinding()]
param(
    [string]$Branch = "main",
    [string]$Repo = "PepijnVR2000/y2k-vst-family",
    [string]$Workflow = "build.yml",
    [string]$ArtifactPrefix = "lp-windows-x64-",
    # CommonProgramW6432 = the 64-bit "C:\Program Files\Common Files", even from 32-bit PowerShell
    [string]$Vst3Dir = "$env:CommonProgramW6432\VST3",
    [string]$ClapDir = "$env:CommonProgramW6432\CLAP",
    [switch]$Force   # skip the FL Studio check
)

$ErrorActionPreference = "Stop"

function Fail($message) {
    Write-Host "ERROR: $message" -ForegroundColor Red
    exit 1
}

# 1. FL Studio must be closed ---------------------------------------------------
if (-not $Force) {
    $fl = Get-Process -ErrorAction SilentlyContinue | Where-Object { $_.ProcessName -match '^FL(64)?$|^FL Studio' }
    if ($fl) {
        Fail "FL Studio is running ($($fl[0].ProcessName)). Close it first: it locks loaded plugins. (Use -Force to skip this check.)"
    }
}

# 2. Find and download the artifact ---------------------------------------------
if (-not (Get-Command gh -ErrorAction SilentlyContinue)) {
    Fail "GitHub CLI 'gh' not found. Install it (winget install GitHub.cli), then run 'gh auth login'."
}

Write-Host "Looking for the latest successful '$Workflow' run on '$Branch' in $Repo ..."
$runJson = gh run list --repo $Repo --workflow $Workflow --branch $Branch --status success --limit 1 --json databaseId,headSha,createdAt
if ($LASTEXITCODE -ne 0) { Fail "gh run list failed (are you logged in? try 'gh auth status')." }
$runs = ($runJson -join "`n") | ConvertFrom-Json
if (-not $runs -or $runs.Count -eq 0) { Fail "No successful run found on branch '$Branch'." }
$run = $runs[0]
$shortSha = $run.headSha.Substring(0, 8)
Write-Host "Run $($run.databaseId), commit $shortSha, $($run.createdAt)"

$temp = Join-Path ([System.IO.Path]::GetTempPath()) ("lp-latest-" + [guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $temp | Out-Null

gh run download $run.databaseId --repo $Repo --name "$ArtifactPrefix$shortSha" --dir $temp
if ($LASTEXITCODE -ne 0) { Fail "Download of artifact '$ArtifactPrefix$shortSha' failed (artifacts expire after 30 days)." }

$vst3 = @(Get-ChildItem -Path (Join-Path $temp "VST3") -Filter *.vst3 -Directory -ErrorAction SilentlyContinue)
$clap = @(Get-ChildItem -Path (Join-Path $temp "CLAP") -Filter *.clap -File -ErrorAction SilentlyContinue)
if ($vst3.Count -eq 0 -and $clap.Count -eq 0) { Fail "Artifact contains no .vst3 or .clap files." }

# 3. Install (elevated copy) -----------------------------------------------------
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

# 4. Report ----------------------------------------------------------------------
foreach ($b in $vst3) { Write-Host "Installed VST3: $(Join-Path $Vst3Dir $b.Name)" -ForegroundColor Green }
foreach ($f in $clap) { Write-Host "Installed CLAP: $(Join-Path $ClapDir $f.Name)" -ForegroundColor Green }
$info = Join-Path $temp "BUILD_INFO.txt"
if (Test-Path $info) { Get-Content $info | ForEach-Object { Write-Host "  $_" } }
Write-Host "Build $shortSha installed. In FL Studio: Options > Manage plugins > Find more plugins (rescan)."

Remove-Item -LiteralPath $temp -Recurse -Force -ErrorAction SilentlyContinue
