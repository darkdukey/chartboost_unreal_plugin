#!/bin/bash

UE_PATH="/Users/Shared/UnrealEngine/4.13/Engine/"
UAT_PATH="Build/BatchFiles/"

CURR_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# chartboost
${UE_PATH}${UAT_PATH}RunUAT.sh BuildPlugin -Plugin="${CURR_PATH}/Plugins/SDKBOX/chartboost/SdkboxChartboost.uplugin" -TargetPlatforms=Mac+IOS+Android -Package="${CURR_PATH}/output/chartboost"

cp -R "${CURR_PATH}/output/chartboost/Binaries" "${CURR_PATH}/Plugins/SDKBOX/chartboost/"

# IAP
${UE_PATH}${UAT_PATH}RunUAT.sh BuildPlugin -Plugin="${CURR_PATH}/Plugins/SDKBOX/IAP/SdkboxIAP.uplugin" -TargetPlatforms=Mac+IOS+Android -Package="${CURR_PATH}/output/iapiap"

cp -R "${CURR_PATH}/output/iap/Binaries" "${CURR_PATH}/Plugins/SDKBOX/IAP/"
