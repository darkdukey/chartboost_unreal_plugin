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

#include "SdkboxChartboostPrivatePCH.h"

// chartboost

USdkboxChartboostComponent::FStringDelegate USdkboxChartboostComponent::OnChartboostCachedDelegate;
USdkboxChartboostComponent::FStringDelegate USdkboxChartboostComponent::OnChartboostShouldDisplayDelegate;
USdkboxChartboostComponent::FStringDelegate USdkboxChartboostComponent::OnChartboostDisplayDelegate;

USdkboxChartboostComponent::FStringDelegate USdkboxChartboostComponent::OnChartboostDismissDelegate;
USdkboxChartboostComponent::FStringDelegate USdkboxChartboostComponent::OnChartboostCloseDelegate;
USdkboxChartboostComponent::FStringDelegate USdkboxChartboostComponent::OnChartboostClickDelegate;
USdkboxChartboostComponent::FStringIntDelegate USdkboxChartboostComponent::OnChartboostRewardDelegate;
USdkboxChartboostComponent::FStringIntDelegate USdkboxChartboostComponent::OnChartboostFailedToLoadDelegate;
USdkboxChartboostComponent::FStringIntDelegate USdkboxChartboostComponent::OnChartboostFailToRecordClickDelegate;
USdkboxChartboostComponent::FVoidDelegate USdkboxChartboostComponent::OnChartboostConfirmationDelegate;
USdkboxChartboostComponent::FVoidDelegate USdkboxChartboostComponent::OnChartboostCompleteStoreDelegate;

USdkboxChartboostComponent::USdkboxChartboostComponent(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void USdkboxChartboostComponent::OnRegister()
{
	Super::OnRegister();

// chartboost

	USdkboxChartboostComponent::OnChartboostCachedDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostCachedDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostShouldDisplayDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostShouldDisplayDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostDisplayDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostDisplayDelegate_Handler);

	USdkboxChartboostComponent::OnChartboostDismissDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostDismissDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostCloseDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostCloseDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostClickDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostClickDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostRewardDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostRewardDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostConfirmationDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostConfirmationDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostCompleteStoreDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostCompleteStoreDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostFailedToLoadDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostFailedToLoadDelegate_Handler);
	USdkboxChartboostComponent::OnChartboostFailToRecordClickDelegate.AddUObject(this, &USdkboxChartboostComponent::OnChartboostFailToRecordClickDelegate_Handler);
}

void USdkboxChartboostComponent::OnUnregister()
{
	Super::OnUnregister();

//charboost
	USdkboxChartboostComponent::OnChartboostCachedDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostShouldDisplayDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostDisplayDelegate.RemoveAll(this);

	USdkboxChartboostComponent::OnChartboostDismissDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostCloseDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostClickDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostRewardDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostConfirmationDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostCompleteStoreDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostFailedToLoadDelegate.RemoveAll(this);
	USdkboxChartboostComponent::OnChartboostFailToRecordClickDelegate.RemoveAll(this);
}

