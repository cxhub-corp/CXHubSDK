# CXHubSDK

CXHub SDK is a solution for sending push and inapp notifications

## Libraries

There is library `CXHubNotify`. This is based on a core library called `CXHubCore`. All libraries are wrapped in dynamic frameworks.

### CXHubNotify

Lets you work with push notifications and send events. Developed for integration to main application, to ServiceExtension and to ContentExtension.

## Demo app

Will be presented soon.

## Checklist

Items from this list are required for correct integration of libraries to your application:

### Common

* enable framework and library(-ies) in config
* enable Debug-mode to receive debug-information (but don't forget to disable Debug-mode in the release)

### CXHubNotify setup

* setup application identifier, and application secret in config of Notify (application name is obsoleted)
* implement CXNotifyDelegate protocol and install delegate to `[CXNotify getInstance]`
* configure activity (read 'Activity Settings')
* create service extension and add library 'Notify' to it
* create content extension and add library 'Notify' to it

## Installation

### Add libraries to project (with Cocoapods)

#### Add following lines into your project's Podfile to add Libnotify libraries support:

##### Libnotify pod

```ruby
pod 'CXHubSDK', 'x.x.x' # Please input specific version
```

##### Install library

* Run `pod install`
* Open workspace

##### Note

You need to add this libraries to all targets (for 'Notify' it's your app and service extension, and content extension)

### Add libraries to project (with Carthage)

Will be soon.

## Usage

* Create instance of `CXAppConfig`
* Initialize framework with `CXApp`
* Configure delegates
* Work with libraries

### Configuration

You can configure CXHub SDK from code or creating config file in plist format. Under the hood library works with instance of CXAppConfig.
Before initialization you can change this config.  But after initialization library reads current state and doesn't observe any changes.

#### Make config with Notify.plist

The simplest way is make file Notify.plist. This file lets configure these parts: core (common properties), notify.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
    <dict>
        <key>Enabled</key><!-- Enable or disable framework -->
        <true/>
        <key>Debug</key><!-- Enable or disable debug mode. You have to disable it in Release -->
        <true/>
        <key>LibNotify</key><!-- Configuration of Libnotify -->
        <dict>
            <key>Activity</key><!-- Configuration of activity in libnotify -->
            <dict>
                <key>Colors</key>
                <dict>
                    <key>DarkModeSupported</key><!-- Whether library should configure activity for dark mode or not -->
                    <true/>
                    <key>BackgroundColor</key>
                    <dict>
                        <key>Light</key>
                        <string>#70D05A</string>
                        <key>Dark</key>
                        <string>#70D05A</string>
                    </dict>
                    <key>TextColor</key>
                    <dict>
                        <key>Light</key>
                        <string>#70D05A</string>
                        <key>Dark</key>
                        <string>#70D05A</string>
                    </dict>
                    <key>AccentColor</key>
                    <dict>
                        <key>Light</key>
                        <string>#70D05A</string>
                        <key>Dark</key>
                        <string>#70D05A</string>
                    </dict>
                    <key>ButtonTextColor</key>
                    <dict>
                        <key>Light</key>
                        <string>#70D05A</string>
                        <key>Dark</key>
                        <string>#70D05A</string>
                    </dict>
                    <key>CloseButtonColor</key>
                    <dict>
                        <key>Light</key>
                        <string>#70D05A</string>
                        <key>Dark</key>
                        <string>#70D05A</string>
                    </dict>
                </dict>
                <!-- 
                    You can configure library to use custom fonts or dynamic fonts:
                        Static - enables default fonts and doesn't observe changes in system settings
                        Dynamic - uses default fonts as base font and changes size of font according to system settings
                        Custom - library asks fonts from host application. Library observes system settings and asks new fonts on change them.
                    Default fonts you can find in code.
                -->
                <key>FontType</key>
                <string>Static</string>
            </dict>
            <key>Landing</key><!-- Obsolete! Configuration of landing page -->
            <dict>
                <key>CloseButtonColor</key><!-- Color of button key -->
                <string>#70D05A</string>
                <key>ButtonTextColor</key><!-- Color of buttons text -->
                <string>#FFFFFF</string>
                <key>AccentColor</key><!-- Color of buttons and links -->
                <string>#70D05A</string>
                <key>TextColor</key><!-- Text color -->
                <string>#000000</string>
                <key>BackgroundColor</key><!-- Background color -->
                <string>#FFFFFF</string>
            </dict>
            <key>Enabled</key><!-- Enable or disable Libnotify -->
            <true/>
            <key>Application</key><!-- Libnotify parameters -->
            <dict>
                <key>Name</key><!-- Name of application -->
                <string>application name</string>
                <key>Id</key><!-- Identifier of application -->
                <string>application id</string>
                <key>Secret</key><!-- Secret of application -->
                <string>application secret</string>
            </dict>
        </dict>
        <key>SharedGroupId</key><!-- Shared group ID. You have to copy group identifier from Entitlements -->
        <string>shared group identifier</string>
    </dict>
</plist>
```

This configuration file must be added to the application bundle. If you have ServiceExtension or ContentExtension you have to add Notify.plist to the bundle of this extensions as well.

*You can find example* ***Notify.plist*** *in directory with pod or in archive with frameworks.*

*Some properties can be setup through code only. It was made for critical properties that are dangerous and require more attention.*

#### Other ways

* You may create empty configuration in code with string `[CXAppConfig emptyConfig]` and then setup required parameters. But take attention and read comments in API.

* At last, you can load default configuration from Notify.plist using method `[CXAppConfig defaultConfig]` and then change it.

### Initialization framework

For initialize framework you need to use class `CXApp`. Methods for initialize framework in application and extensions are different.

Method `[CXApp initWithDefaultConfigAndEventsReceiver:]` lets you initialize framework for application with configuration loaded from file `Notify.plist`.

Method `[CXApp initExtensionWithDefaultConfigAndEventsReceiver:]` lets you initialize framework for application's extensions with configuration loaded from file `Notify.plist`.

Methods `[CXApp initWithConfig:withEventsReceiver:]` and `[CXApp initExtensionWithConfig:withEventsReceiver:]` initialize framework for application and extensions accordingly with custom config.

**After initialize framework you cannot change configuration**

#### Features

##### GDRP

Libnotify supports GDPR. You can enable or disable sending VendorID and WiFi information to server. To configure GDPR you need use `-[[CXNotify getInstance] setDeviceIdTrackingEnabled:boolValue]`

#### Tips

* If you want to use few configurations you may create configuration files for each configuration, load required with `[CXAppConfig initWithConfig:]` and initialize framework with this configuration. 

* Another way is reading base configuration from file and changing it.

### Initialization Libnotify

If you configure libnotify for work in main application (not in extension) you have to configure delegate for libnotify.
`[CXNotify getInstance] setDelegate:<you implementation of protocol CXNotifyDelegate>]`.

It lets you handle some messages from libnotify including opening main interface for user. We can get corresponding request from user but we cannot predict the structure of your application.

#### Features

##### Dark-mode support

Library Notify can work with dark mode. If your application supports dark-mode you can enable property **activitySettings.colorSettings.darkModeSupported**. But please don't forget configure right colors.

##### Dynamic font support

Library allows to configure fonts in activity. You can use static fonts (by default), use dynamic fonts based on system fonts or you can configure custom fonts.
To do this you have to set property **activitySettings.fontType** to **Custom** and implement few methods in NotifyDelegate. 
After that library will asks fonts from your application. Also library observes changes in system settings and asks right fonts every time system settings changed.

#### Set instance properties

You can set property to instance, using these examples

``` ObjectiveC
// Set string-value property
[[CXNotify getInstance] setInstanceProperty:@"TestPropertyStringName"
                            withStringValue:@"TestPropertyStringValue"];

// Set array-value property (items must be enumeratable)
[[CXNotify getInstance] setInstanceProperty:@"TestPropertyArrayName"
                             withArrayValue:
                             @[@"Test", @"Property", @"Array",@"Value"]
];

// Set dictionary-value property
[[CXNotify getInstance] setInstanceProperty: @"TestPropertyDictionaryName"
                        withDictionaryValue:
                        @{@"key1": @"value1", @"key2": @"value2"}
];
```
#### Use of toast buttons (UNNotificationAction)

Library allows to use toast buttons (there is an option in Web interface to combine action with user event, which will be delivered to CXHub and so specific actions can be tracked). To use CXHubSDK with toast buttons there are several requirements:
1) Both NotificationServiceExtension and Content extension should be added to the app and properly tuned.
2) All modules (main app, service extension, content extension) have to be members of one app group.
3) Content extension Info.plist file must contain **UNNotificationExtensionCategory** key (under **NSExtensionAttributes**) with array of category identifier strings. The latter must contain
    **libnotify_default** identifier and at least 5 (better 10) other category identifiers to support categories for push notifications with toast buttons, e.g.:

<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>NSExtensionAttributes</key>
    <dict>
        <key>UNNotificationExtensionCategory</key>
        <array>
            <string>libnotify_default</string>
            <string>libnotify_button_queue_1</string>
            <string>libnotify_button_queue_2</string>
            <string>libnotify_button_queue_3</string>
            <string>libnotify_button_queue_4</string>
            <string>libnotify_button_queue_5</string>
        </array>
        <key>UNNotificationExtensionUserInteractionEnabled</key>
        <true/>
        <key>UNNotificationExtensionInitialContentSizeRatio</key>
        <real>0.85</real>
        <key>UNNotificationExtensionDefaultContentHidden</key>
        <false/>
    </dict>
    <key>NSExtensionMainStoryboard</key>
    <string>MainInterface</string>
    <key>NSExtensionPointIdentifier</key>
    <string>com.apple.usernotifications.content-extension</string>
</dict>
</plist>


        
4) All modules must contain the same CXHubSDK config file: Notification.plist (example is below), which must contain the same key and array as in content extension Info.plist:

<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>LibNotify</key>
    <dict>
        <key>UNNotificationExtensionCategory</key>
        <array>
            <string>libnotify_default</string>
            <string>libnotify_button_queue_1</string>
            <string>libnotify_button_queue_2</string>
            <string>libnotify_button_queue_3</string>
            <string>libnotify_button_queue_4</string>
            <string>libnotify_button_queue_5</string>
        </array>
        <key>Enabled</key>
        <true/>
        <key>Landing</key>
        <dict>
            <key>CloseButtonColor</key>
            <string>#70D05A</string>
            <key>ButtonTextColor</key>
            <string>#FFFFFF</string>
            <key>AccentColor</key>
            <string>#FF0000</string>
            <key>TextColor</key>
            <string>#000000</string>
            <key>BackgroundColor</key>
            <string>#FFFFFF</string>
        </dict>
        <key>Application</key>
        <dict>
            <key>Secret</key>
            <string>**CXHub secret key **</string>
            <key>Name</key>
            <string>**CXHub application name **</string>
            <key>Id</key>
            <string>**CXHub application id **</string>
        </dict>
    </dict>
    <key>SharedGroupId</key>
    <string>**app shared group id, e.g.: group.com.yourAppId **</string>
    <key>Enabled</key>
    <true/>
    <key>Debug</key>
    <true/>
</dict>
</plist>

5) CXHubSDK uses "shared" NSUserDefaults ( [[NSUserDefaults alloc] initWithSuiteName:**_your_app_group_id_**] ) to store share notification category-related data among mainApp, service extenstion and content extension. Therefore be careful if you use the same shared container and never call "reset", otherwise notification actions may work incorrectly.

### Localization

## Technical notes

### Modal interfaces

We open landing interface in libnotify and message settings interface in libverify in separate window. It helps us present required interfaces saving view controllers stack of main application. But sometimes we mark our window as key. Due to this circumstance you can get invalid behaviour if you try to find main window of your application with `keyWindow` method.

## Attention

Next recommendations will help you to avoid incorrect behaviour

1. Try to don't get access to your main window using method `[[UIApplication sharedApplication] keyWindow]`. For details look at Technical notes above.

## Requirements

iOS 12.1+

## License

LGPL
