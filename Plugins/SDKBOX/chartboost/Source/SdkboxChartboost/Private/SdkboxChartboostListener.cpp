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

void USdkboxChartboostListener::onChartboostCached(const std::string& name)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogChartboost, Log, TEXT("onChartboostCached "));
#endif

    USdkboxChartboostComponent::OnChartboostCachedDelegate.Broadcast(name.c_str());
}
bool USdkboxChartboostListener::onChartboostShouldDisplay(const std::string& name)
{
    USdkboxChartboostComponent::OnChartboostShouldDisplayDelegate.Broadcast(name.c_str());
    return true;
}
void USdkboxChartboostListener::onChartboostDisplay(const std::string& name)
{
    USdkboxChartboostComponent::OnChartboostDisplayDelegate.Broadcast(name.c_str());
}
void USdkboxChartboostListener::onChartboostDismiss(const std::string& name)
{
    USdkboxChartboostComponent::OnChartboostDismissDelegate.Broadcast(name.c_str());
}
void USdkboxChartboostListener::onChartboostClose(const std::string& name)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogChartboost, Log, TEXT("onChartboostClose"));
#endif

    USdkboxChartboostComponent::OnChartboostCloseDelegate.Broadcast(name.c_str());
}
void USdkboxChartboostListener::onChartboostClick(const std::string& name)
{
    USdkboxChartboostComponent::OnChartboostClickDelegate.Broadcast(name.c_str());
}
void USdkboxChartboostListener::onChartboostReward(const std::string& name, int reward)
{
    USdkboxChartboostComponent::OnChartboostRewardDelegate.Broadcast(name.c_str(), reward);
}
void USdkboxChartboostListener::onChartboostFailedToLoad(const std::string& name, sdkbox::CB_LoadError e)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogChartboost, Log, TEXT("onChartboostFailedToLoad"));
#endif

    USdkboxChartboostComponent::OnChartboostFailedToLoadDelegate.Broadcast(name.c_str(), e);
}
void USdkboxChartboostListener::onChartboostFailToRecordClick(const std::string& name, sdkbox::CB_ClickError e)
{
    USdkboxChartboostComponent::OnChartboostFailToRecordClickDelegate.Broadcast(name.c_str(), e);
}
void USdkboxChartboostListener::onChartboostConfirmation()
{
    USdkboxChartboostComponent::OnChartboostConfirmationDelegate.Broadcast();
}
void USdkboxChartboostListener::onChartboostCompleteStore()
{
    USdkboxChartboostComponent::OnChartboostCompleteStoreDelegate.Broadcast();
}

