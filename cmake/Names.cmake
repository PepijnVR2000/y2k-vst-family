# ---------------------------------------------------------------------------
# The ONLY place where family, company and plugin names live.
#
# Everything here is a neutral code name: brand and product names are not final.
# Renaming the family or a plugin = edit this file, reconfigure, rebuild.
#
# Careful with the *_CODE / *_ID values: hosts (FL Studio included) identify a
# plugin by manufacturer code + plugin code (VST3) and by CLAP id. Changing
# them after users have saved projects makes those projects lose the plugin.
# Display names (LP_*_PRODUCT_NAME, LP_COMPANY_NAME) can change freely until a
# public release; ids should be frozen before the first public build.
# ---------------------------------------------------------------------------

# Family / vendor ----------------------------------------------------------
set(LP_FAMILY_NAME        "LP")
set(LP_COMPANY_NAME       "LP Dev")
set(LP_COMPANY_WEBSITE    "")
set(LP_BUNDLE_ID_PREFIX   "dev.lp")        # reverse-DNS prefix for bundle / CLAP ids
set(LP_MANUFACTURER_CODE  "Lpdv")          # 4 chars, at least one upper case

# Disc 1: mono instrument shell --------------------------------------------
set(LP_DISC1_TARGET        "lp_disc1")
set(LP_DISC1_PRODUCT_NAME  "LP Disc 1 (dev)")
set(LP_DISC1_PLUGIN_CODE   "Ld01")         # 4 chars, unique within the family
set(LP_DISC1_ID_SUFFIX     "disc1")        # -> dev.lp.disc1
set(LP_DISC1_DESCRIPTION   "LP family instrument shell (development build)")
