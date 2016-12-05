/****************************************************************************
 Copyright (c) 2015 SDKBOX Inc.
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#pragma once

#include "PluginChartboost.h"
#include <string>
#include "SdkboxChartboostListener.generated.h"

// UE4 HeaderTool fails to parse the namespace properly, so...
struct UListener : public sdkbox::ChartboostListener {};

UCLASS(NotBlueprintable)
class USdkboxChartboostListener
    : public UObject
    , public UListener
{
	GENERATED_BODY()

public:

    // chartboost

    // Called after an interstitial has been loaded from the Chartboost API servers and cached locally.
    void onChartboostCached(const std::string& name);

    // Called before an interstitial will be displayed on the screen.
    bool onChartboostShouldDisplay(const std::string& name);

    // Called after an interstitial has been loaded from the Chartboost API servers and cached locally.
    void onChartboostDisplay(const std::string& name);

    // Called after an interstitial has been dismissed.
    void onChartboostDismiss(const std::string& name);

    // Called after an interstitial has been closed.
    void onChartboostClose(const std::string& name);

    // Called after an interstitial has been clicked.
    void onChartboostClick(const std::string& name);

    // Called after a rewarded video has been viewed completely and user is eligible for reward.
    void onChartboostReward(const std::string& name, int reward);

    // Called after an interstitial has attempted to load from the Chartboost API servers but failed.
    void onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e);

    // Called after a click is registered
    void onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e);

    // Called if Chartboost SDK pauses click actions awaiting confirmation from the user.
    void onChartboostConfirmation();

    // Called after the App Store sheet is dismissed, when displaying the embedded app sheet.
    void onChartboostCompleteStore();
};
