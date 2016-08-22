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

USdkboxChartboostListener* USdkboxChartboostFunctions::_ChartboostListener = nullptr;

void USdkboxChartboostFunctions::ChartboostInitialize(FString jsonstring)
{
#if PLATFORM_IOS || PLATFORM_ANDROID

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    UE_LOG(LogChartboost, Log, TEXT("ChartboostInitialize %s"), *jsonstring);
#endif

#if PLATFORM_IOS
     dispatch_async(dispatch_get_main_queue(), ^{
        sdkbox::PluginChartboost::init(TCHAR_TO_UTF8(*jsonstring));
        _ChartboostListener = NewObject<USdkboxChartboostListener>(USdkboxChartboostListener::StaticClass());
        sdkbox::PluginChartboost::setListener(_ChartboostListener);
    });
#endif

#if PLATFORM_ANDROID
    sdkbox::PluginChartboost::init(TCHAR_TO_UTF8(*jsonstring));
    _ChartboostListener = NewObject<USdkboxChartboostListener>(USdkboxChartboostListener::StaticClass());
    sdkbox::PluginChartboost::setListener(_ChartboostListener);
 #endif

#endif
}

void USdkboxChartboostFunctions::ChartboostShutdown()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    if (_ChartboostListener && _ChartboostListener->IsValidLowLevel())
    {
        _ChartboostListener->ConditionalBeginDestroy();
        _ChartboostListener = nullptr;
    }
#endif
}

FString USdkboxChartboostFunctions::ChartboostJsonStringFromAdDescriptions(const TArray<FSdkboxChartboostAdDescription>& Descriptions)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    TSharedPtr<FJsonObject> jo    =  MakeShareable(new FJsonObject);
    TSharedPtr<FJsonObject> ios[] = {MakeShareable(new FJsonObject), MakeShareable(new FJsonObject), MakeShareable(new FJsonObject)};
    TSharedPtr<FJsonObject> drd[] = {MakeShareable(new FJsonObject), MakeShareable(new FJsonObject), MakeShareable(new FJsonObject)};

    jo->SetObjectField("ios", ios[0]);
    ios[0]->SetObjectField("Chartboost", ios[1]);
    ios[1]->SetObjectField("ads", ios[2]);

    jo->SetObjectField("android", drd[0]);
    drd[0]->SetObjectField("Chartboost", drd[1]);
    drd[1]->SetObjectField("ads", drd[2]);


    // set id and signature , with setting
    const USdkboxChartboostSettings* settings = GetDefault<USdkboxChartboostSettings>();
    // ios
    ios[1]->SetStringField("id", settings->AppIDIOS);
    ios[1]->SetStringField("signature", settings->SignatureIOS);
    // android
    drd[1]->SetStringField("id", settings->AppIDAndroid);
    drd[1]->SetStringField("signature", settings->SignatureAndroid);
    // set id and signature end


    for (auto d : Descriptions)
    {
        TSharedPtr<FJsonObject> item = MakeShareable(new FJsonObject);
        item->SetStringField("type", d.Type);

        switch (d.Affinity)
        {
            case ECBAdAffinityEnum::PAE_IOS:
                ios[2]->SetObjectField(d.Name, item);
                break;
            case ECBAdAffinityEnum::PAE_ANDROID:
                drd[2]->SetObjectField(d.Name, item);
                break;
            case ECBAdAffinityEnum::PAE_ALL:
            default:
                ios[2]->SetObjectField(d.Name, item);
                drd[2]->SetObjectField(d.Name, item);
                break;
        }
    }

    FString OutputString;
    TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
    FJsonSerializer::Serialize(jo.ToSharedRef(), Writer);

    return OutputString;
#else
    return "";
#endif
}

////////////////////////////// functions /////////////////////////////////
void USdkboxChartboostFunctions::ChartboostShow(FString name)
{
#if PLATFORM_IOS
   dispatch_async(dispatch_get_main_queue(), ^{
        sdkbox::PluginChartboost::show(TCHAR_TO_UTF8(*name));
   });
#endif

#if PLATFORM_ANDROID
    sdkbox::PluginChartboost::show(TCHAR_TO_UTF8(*name));
#endif
}

bool USdkboxChartboostFunctions::ChartboostIsAnyViewVisible()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    return sdkbox::PluginChartboost::isAnyViewVisible();
#endif
    return false;
}

bool USdkboxChartboostFunctions::ChartboostIsAvailable(FString name)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    return sdkbox::PluginChartboost::isAvailable(TCHAR_TO_UTF8(*name));
#endif
    return false;
}

void USdkboxChartboostFunctions::ChartboostCache(FString name)
{
#if PLATFORM_IOS
   dispatch_async(dispatch_get_main_queue(), ^{
        sdkbox::PluginChartboost::cache(TCHAR_TO_UTF8(*name));
   });
#endif

#if PLATFORM_ANDROID
    sdkbox::PluginChartboost::cache(TCHAR_TO_UTF8(*name));
#endif
}

void USdkboxChartboostFunctions::ChartboostSetAutoCacheAds(bool shouldCache)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::setAutoCacheAds(shouldCache);
#endif
}

bool USdkboxChartboostFunctions::ChartboostGetAutoCacheAds()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    return sdkbox::PluginChartboost::getAutoCacheAds();
#endif
    return false;
}

void USdkboxChartboostFunctions::ChartboostCloseImpression()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    return sdkbox::PluginChartboost::closeImpression();
#endif
}

// void USdkboxChartboostFunctions::setStatusBarBehavior(CB_StatusBarBehavior behavior)
// {
// #if PLATFORM_IOS || PLATFORM_ANDROID
//     return sdkbox::PluginChartboost::setStatusBarBehavior();
// #endif
// }

void USdkboxChartboostFunctions::ChartboostDidPassAgeGate(bool pass)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::didPassAgeGate(pass);
#endif
}

void USdkboxChartboostFunctions::ChartboostSetShouldPauseClickForConfirmation(bool shouldPause)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::setShouldPauseClickForConfirmation(shouldPause);
#endif
}

bool USdkboxChartboostFunctions::ChartboostHandleOpenURL(FString url, FString sourceApp)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    return sdkbox::PluginChartboost::handleOpenURL(TCHAR_TO_UTF8(*url), TCHAR_TO_UTF8(*sourceApp));
#endif
    return false;
}

void USdkboxChartboostFunctions::ChartboostSetCustomID(FString customID)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::setCustomID(TCHAR_TO_UTF8(*customID));
#endif
}

FString USdkboxChartboostFunctions::ChartboostGetCustomID()
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    return FString(sdkbox::PluginChartboost::getCustomID().c_str());
#endif
    return "";
}
void USdkboxChartboostFunctions::ChartboostSetShouldRequestInterstitialsInFirstSession(bool shouldRequest)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::setShouldRequestInterstitialsInFirstSession(shouldRequest);
#endif
}

void USdkboxChartboostFunctions::ChartboostSetShouldDisplayLoadingViewForMoreApps(bool shouldDisplay)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::setShouldDisplayLoadingViewForMoreApps(shouldDisplay);
#endif
}

void USdkboxChartboostFunctions::ChartboostSetShouldPrefetchVideoContent(bool shouldPrefetch)
{
#if PLATFORM_IOS || PLATFORM_ANDROID
    sdkbox::PluginChartboost::setShouldPrefetchVideoContent(shouldPrefetch);
#endif
}

