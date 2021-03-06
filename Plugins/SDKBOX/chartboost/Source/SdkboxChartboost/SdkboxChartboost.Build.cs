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

using System.IO;
using System;

namespace UnrealBuildTool.Rules
{
    public class SdkboxChartboost : ModuleRules
    {
        private string ModulePath
        {
            get { return ModuleDirectory; }
        }

        public SdkboxChartboost(TargetInfo Target)
        {
            PublicIncludePaths.AddRange(
                new string[] {
                    // ... add public include paths required here ...
                }
            );

            // PrivateIncludePaths.AddRange(
            //  new string[] {
            //      "Developer/SdkboxIAP/Private",
            //      // ... add other private include paths required here ...
            //  }
            // );

            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "Engine"
                    // ... add other public dependencies that you statically link with here ...
                }
            );

            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    // ... add private dependencies that you statically link with here ...
                }
            );

            DynamicallyLoadedModuleNames.AddRange(
                new string[]
                {
                    // ... add any modules that your module loads dynamically here ...
                }
            );

            PrivateIncludePathModuleNames.AddRange(
                new string[] {
                    "Settings"
                }
            );


            if (Target.Platform == UnrealTargetPlatform.IOS)
            {

                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../lib/iOS/PluginChartboost.a"));

                // check sdkbox IAP plugin
                if (!File.Exists(Path.Combine(ModulePath, "../../../IAP/lib/iOS/sdkbox.a"))) {
                    PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../lib/iOS/sdkbox.a"));
                }

                PublicAdditionalFrameworks.Add(
                    new UEBuildFramework(
                        "Chartboost",
                        "../../lib/iOS/Chartboost.embeddedframework.zip"
                    )
                );

                PublicFrameworks.AddRange(
                    new string[]
                    {
                        "Security",
                        "StoreKit",
                        "Foundation",
                        "CoreGraphics",
                        "UIKit",
                        "AdSupport",
                        "SystemConfiguration"
                    }
                );
            }
            else if (Target.Platform == UnrealTargetPlatform.Android)
            {
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../lib/Android/PluginChartboost.a"));

                // check sdkbox IAP plugin
                if (!File.Exists(Path.Combine(ModulePath, "../../../IAP/lib/Android/sdkbox.a")))
                {
                    PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "../../lib/Android/sdkbox.a"));
                }

                PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
                if (!File.Exists(Path.Combine(ModulePath, "../../../IAP/lib/Android/sdkbox.a")))
                {
                    AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(ModulePath, "SdkboxCore.xml")));
                }
                AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(ModulePath, "SdkboxChartboost.xml")));

            }
        }
    }
}
