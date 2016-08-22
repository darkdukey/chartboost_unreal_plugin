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

#include "SdkboxChartboostComponent.generated.h"

class USdkboxChartboostListener;

UCLASS(ClassGroup=SDKBOX, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class USdkboxChartboostComponent
    : public UActorComponent
{
	GENERATED_BODY()

public:

    USdkboxChartboostComponent(const FObjectInitializer& ObjectInitializer);

    void OnRegister() override;
    void OnUnregister() override;

    DECLARE_MULTICAST_DELEGATE(FVoidDelegate);
    DECLARE_MULTICAST_DELEGATE_OneParam(FIntDelegate, int);
    DECLARE_MULTICAST_DELEGATE_OneParam(FBoolDelegate, bool);
   	DECLARE_MULTICAST_DELEGATE_OneParam(FStringDelegate, const FString&);
    DECLARE_MULTICAST_DELEGATE_TwoParams(FIntStringDelegate, int, const FString&);
    DECLARE_MULTICAST_DELEGATE_TwoParams(FStringIntDelegate, const FString&, int);
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FVirtualCurrencyConnectorFailedDelegate, int, const FString&, const FString&);
	DECLARE_MULTICAST_DELEGATE_FourParams(FVirtualCurrencyConnectorSuccessDelegate, double, const FString&, const FString&, const FString&);


// chartboost

    static FStringDelegate OnChartboostCachedDelegate;
    static FStringDelegate OnChartboostShouldDisplayDelegate;
    static FStringDelegate OnChartboostDisplayDelegate;

    static FStringDelegate OnChartboostDismissDelegate;
    static FStringDelegate OnChartboostCloseDelegate;
    static FStringDelegate OnChartboostClickDelegate;
    static FStringIntDelegate OnChartboostRewardDelegate;
    static FStringIntDelegate OnChartboostFailedToLoadDelegate;
    static FStringIntDelegate OnChartboostFailToRecordClickDelegate;
    static FVoidDelegate OnChartboostConfirmationDelegate;
    static FVoidDelegate OnChartboostCompleteStoreDelegate;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDynVoidDelegate);
   	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynStringDelegate, const FString&, Message);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDynStringIntDelegate, const FString&, Message, int, Status);

// chartboost
    UPROPERTY(BlueprintAssignable)
    FDynStringDelegate OnChartboostCached;

    UPROPERTY(BlueprintAssignable)
    FDynStringDelegate OnChartboostShouldDisplay;

    UPROPERTY(BlueprintAssignable)
    FDynStringDelegate OnChartboostDisplay;

    UPROPERTY(BlueprintAssignable)
    FDynStringDelegate OnChartboostDismiss;

    UPROPERTY(BlueprintAssignable)
    FDynStringDelegate OnChartboostClose;

    UPROPERTY(BlueprintAssignable)
    FDynStringDelegate OnChartboostClick;

    UPROPERTY(BlueprintAssignable)
    FDynStringIntDelegate OnChartboostReward;

    UPROPERTY(BlueprintAssignable)
    FDynStringIntDelegate OnChartboostFailedToLoad;

    UPROPERTY(BlueprintAssignable)
    FDynStringIntDelegate OnChartboostFailToRecordClick;

    UPROPERTY(BlueprintAssignable)
    FDynVoidDelegate OnChartboostConfirmation;

    UPROPERTY(BlueprintAssignable)
    FDynVoidDelegate OnChartboostCompleteStore;

protected:


// chartboost
    void OnChartboostCachedDelegate_Handler(const FString& name)
    {
        OnChartboostCached.Broadcast(name);
    }
    // can not return bool
    void OnChartboostShouldDisplayDelegate_Handler(const FString& name)
    {
        OnChartboostShouldDisplay.Broadcast(name);
    }
    void OnChartboostDisplayDelegate_Handler(const FString& name)
    {
        OnChartboostDisplay.Broadcast(name);
    }
    void OnChartboostDismissDelegate_Handler(const FString& name)
    {
        OnChartboostDismiss.Broadcast(name);
    }
    void OnChartboostCloseDelegate_Handler(const FString& name)
    {
        OnChartboostClose.Broadcast(name);
    }
    void OnChartboostClickDelegate_Handler(const FString& name)
    {
        OnChartboostClick.Broadcast(name);
    }
    void OnChartboostRewardDelegate_Handler(const FString& name, int reward)
    {
        OnChartboostReward.Broadcast(name, reward);
    }
    void OnChartboostFailedToLoadDelegate_Handler(const FString& name, int errorCode)
    {
        OnChartboostFailedToLoad.Broadcast(name, errorCode);
    }
    void OnChartboostFailToRecordClickDelegate_Handler(const FString& name, int errorCode)
    {
        OnChartboostFailToRecordClick.Broadcast(name, errorCode);
    }
    void OnChartboostConfirmationDelegate_Handler()
    {
        OnChartboostConfirmation.Broadcast();
    }
    void OnChartboostCompleteStoreDelegate_Handler()
    {
        OnChartboostCompleteStore.Broadcast();
    }
};
