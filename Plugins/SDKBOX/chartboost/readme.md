# SDKBox Chartboost
A plugin for Unreal Engine 4 that integrates Chartboost's SDK and makes its functionality available in blueprints.

- Supported platforms: iOS / Android
- iOS SDK Version: 6.5.1
- Android SDK Version: 6.4.2

## Setup

### Integration

There are a couple of different ways to integrate this plugin into your project. You can include it in your fork of the UE4 engine or you can include it in a single UE4 code-based project if you like.

#### In your engine

This method includes the plugin in your fork of the UE4 engine. It allows you to use the plugin in either code or blueprint-based projects that are created with your fork of the engine. It assumes you have already cloned the UE4 engine to a directory on your machine.

1. Clone this repo to a subfolder of your engine called /Engine/Plugins/Chartboost. Optionally, you can add it as a submodule.
2. Run the GenerateProjectFiles script in the Engine root.
3. Open your engine project file and build the editor.

#### In your code project

This method includes the plugin in a single code-based project. This can be done on any code-based project that is created using the Github source engine or the one provided by Epic via the launcher.

1. Clone this repo to a subfolder in your project called /Plugins/SDKBOX/Chartboost.
2. Open your project. You will be prompted to build missing modules.
3. Select Yes to rebuild now.

### Enable the Plugin

Ensure that the plugin is enabled:

1. In the editor, select Plugins from the Window menu.
2. Search for the plugin called Chartboost. It's in the SDKBOX category.
3. Check the Enabled checkbox on the plugin. You may have to restart the editor after this step.


### Add the Chartboost Start Function

Add the `Chartboost Start` blueprint function early in your game's execution. We use it in our Game Instance's Init event. You could also use it in the Application Lifecycle component's Foreground event or in your first scene's Begin Play event. The key here is to run this function before any other Chartboost function.

![EnableThePlugin](Resources/01.Set ID and Signature.png)
![EnableThePlugin](Resources/02.Add Chartboost Ads.png)

## Caching Ads

You can cache ads using the Chartboost Cache functions.

## Showing Ads

You can check if an interstitial ad is cached and ready to show by using the `Chartboost Has Interstiital` function. If one is available, you can show it using the `Chartboost Show Interstitial` function. If you run the Show function without first using the Has function, an interstitial will display when it is available.

![HasVideoShowVideo](Resources/05.Show Chartboost Ad.png)

## Responding to Events

You can respond to the callbacks that the Chartboost SDK sends by adding the Chartboost component to an actor in your scene.

![AddComponent](Resources/04.Add Events Callback.png)

```
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
```

More information:
- https://answers.chartboost.com/hc/en-us/articles/201220275
