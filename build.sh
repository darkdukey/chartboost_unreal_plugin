#!/bin/bash

UE_PATH="/Users/Shared/UnrealEngine/4.13/Engine/"
UAT_PATH="Build/BatchFiles/"

CURR_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

${UE_PATH}${UAT_PATH}RunUAT.sh BuildPlugin -Plugin="${CURR_PATH}/Plugins/SDKBOX/chartboost/SdkboxChartboost.uplugin" -TargetPlatforms=Mac+IOS+Android -Package="${CURR_PATH}/output"