#!/bin/bash

UE_VERSION=$1
if [[ $# -eq 0 ]]; then
    UE_VERSION="4.13"
fi

UE_PATH="/Users/Shared/UnrealEngine/"${UE_VERSION}"/Engine/"
UAT_PATH="Build/BatchFiles/"

echo "Building Plugin for UnrealEngine " ${UE_VERSION}

CURR_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# chartboost
${UE_PATH}${UAT_PATH}RunUAT.sh BuildPlugin -Plugin="${CURR_PATH}/Plugins/SDKBOX/chartboost/SdkboxChartboost.uplugin" -TargetPlatforms=Mac+IOS+Android -Package="${CURR_PATH}/output/chartboost"

cp -R "${CURR_PATH}/output/chartboost/Binaries" "${CURR_PATH}/Plugins/SDKBOX/chartboost/"

# IAP
${UE_PATH}${UAT_PATH}RunUAT.sh BuildPlugin -Plugin="${CURR_PATH}/Plugins/SDKBOX/IAP/SdkboxIAP.uplugin" -TargetPlatforms=Mac+IOS+Android -Package="${CURR_PATH}/output/iapiap"

cp -R "${CURR_PATH}/output/iap/Binaries" "${CURR_PATH}/Plugins/SDKBOX/IAP/"
