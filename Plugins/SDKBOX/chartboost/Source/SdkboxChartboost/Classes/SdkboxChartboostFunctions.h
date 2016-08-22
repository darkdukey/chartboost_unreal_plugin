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

#include "SdkboxChartboostFunctions.generated.h"

class USdkboxChartboostListener;

UENUM(BlueprintType)
namespace ESdkboxChartboostLoadError {
    enum LoadError
    {
        CBLoadErrorInternal                             UMETA(DisplayName="Internal"),
        CBLoadErrorInternetUnavailable                  UMETA(DisplayName="Internet Unavailable"),
        CBLoadErrorTooManyConnections                   UMETA(DisplayName="Too Many Connections"),
        CBLoadErrorWrongOrientation                     UMETA(DisplayName="Wrong Orientation"),
        CBLoadErrorFirstSessionInterstitialsDisabled    UMETA(DisplayName="First Session Interstitials Disabled"),
        CBLoadErrorNetworkFailure                       UMETA(DisplayName="Network Failure"),
        CBLoadErrorNoAdFound                            UMETA(DisplayName="No Ad Found"),
        CBLoadErrorSessionNotStarted                    UMETA(DisplayName="Session Not Started"),
        CBLoadErrorUserCancellation                     UMETA(DisplayName="User Cancellation"),
        CBLoadErrorNoLocationFound                      UMETA(DisplayName="No Location Found"),
        CBLoadErrorPrefetchingIncomplete                UMETA(DisplayName="Prefetching Incomplete")
    };
}

UCLASS(NotBlueprintable)
class USdkboxChartboostFunctions
    : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
	static void ChartboostInitialize(FString jsonstring);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
	static void ChartboostShutdown();

    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static FString ChartboostJsonStringFromAdDescriptions(const TArray<FSdkboxChartboostAdDescription>& Descriptions);

    // chartboost
    /*!
     * show ad by specifying ad name.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostShow(FString name);

    /*!
     * check to see if any views are visible.
     */
     UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static bool ChartboostIsAnyViewVisible();

    /*!
     * is the specified ad available?
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static bool ChartboostIsAvailable(FString name);

    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostCache(FString name);

    /*!
     * set to enable and disable the auto cache feature (Enabled by default).
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostSetAutoCacheAds(bool shouldCache);

    /*!
     * get the current auto cache behavior (Enabled by default).
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static bool ChartboostGetAutoCacheAds();

    /*!
     * close any visible Chartboost impressions (interstitials, more apps, rewarded
     * video, etc..) and the loading view (if visible).
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostCloseImpression();

    /*!
     * set to control how the fullscreen ad units should interact with the status bar.
     * (CBStatusBarBehaviorIgnore by default).
     */
    // UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    // static void setStatusBarBehavior(CB_StatusBarBehavior behavior);

    /*!
     * confirm if an age gate passed or failed. When specified Chartboost will wait for
     * call before showing the IOS App Store.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostDidPassAgeGate(bool pass);

    /*!
     * decide if Chartboost SDK should block for an age gate.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostSetShouldPauseClickForConfirmation(bool shouldPause);

    /*!
     * opens a "deep link" URL for a Chartboost Custom Scheme.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static bool ChartboostHandleOpenURL(FString url, FString sourceApp);

    /*!
     * set a custom identifier to send in the POST body for all Chartboost API server requests.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostSetCustomID(FString customID);

    /*!
     * get the current custom identifier being sent in the POST body for all Chartboost
     * API server requests.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static FString ChartboostGetCustomID();

    /*!
     * decide if Chartboost SDK should show interstitials in the first session.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostSetShouldRequestInterstitialsInFirstSession(bool shouldRequest);

    /*!
     * decide if Chartboost SDK should show a loading view while preparing to display
     * the "more applications" UI.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostSetShouldDisplayLoadingViewForMoreApps(bool shouldDisplay);

    /*!
     * decide if Chartboost SDK will attempt to fetch videos from the Chartboost API
     * servers.
     */
    UFUNCTION(BlueprintCallable, meta = (Keywords = "SDKBOX Chartboost"), Category = "SDKBOX")
    static void ChartboostSetShouldPrefetchVideoContent(bool shouldPrefetch);

protected:

    static USdkboxChartboostListener* _ChartboostListener;
};
