#!/bin/bash

UE_PATH="/Users/Shared/UnrealEngine/4.13/Engine/"
UAT_PATH="Build/BatchFiles/Mac/"

CURR_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

${UE_PATH}${UAT_PATH}GenerateProjectFiles.sh -project="${CURR_PATH}/SDKBOX_Chartboost.uproject" -game
