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

#include "SdkboxChartboostAdDescription.generated.h"

UENUM(BlueprintType)
enum class ECBAdAffinityEnum : uint8
{
    PAE_ALL     UMETA(DisplayName="All"),
    PAE_IOS     UMETA(DisplayName="iOS"),
    PAE_ANDROID UMETA(DisplayName="Android")
};

UENUM(BlueprintType)
enum class ECBAdTypeEnum : uint8
{
    PAE_INTERSTITAL     UMETA(DisplayName="Interstital"),
    PAE_REWARDEDVIDEO   UMETA(DisplayName="RewardedVideo"),
    PAE_MOREAPP         UMETA(DisplayName="MoreApp")
};

USTRUCT(BlueprintType)
struct FSdkboxChartboostAdDescription
{
    GENERATED_USTRUCT_BODY()

    // The named locations
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=General, meta=(DisplayName="Name"))
    FString Name;

    // The type of ad
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=General, meta=(DisplayName="Type"))
    ECBAdTypeEnum Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=General, meta=(DisplayName="Affinity"))
    ECBAdAffinityEnum Affinity;

};
