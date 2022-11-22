#import <Foundation/Foundation.h>

#import <CXHubCore/CXNotifyActivitySettings.h>

NS_ASSUME_NONNULL_BEGIN

@interface CXNotifyConfig: NSObject <NSCopying>

/*!
 Initializer of this class is private.
 You can get instance of this class from CXAppConfig through property `notifyConfig`
 */
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 isEnabled is a calculated getter. It returns true only if instance variable _enabled = true and appName is filled (not empty)
 */
@property (nonatomic, getter=isEnabled) bool enabled;
@property (nonatomic, copy, nullable) NSString *appName;

/*!
 Fill this field if you know your application's id or remain this field empty
 Note that, in case you have this field you have to fill `appSecretKey` mandatory.
 */
@property (nonatomic, copy, nullable) NSString *appId;

/*!
 Fill this field if you know your application's secret key or remain this field empty
 Note that, in case you have this field you have to fill `appId` mandatory.
 */
@property (nonatomic, copy, nullable) NSString *appSecretKey;

/*!
 Landing properties
 */

/*!
 @deprecated in version 1.0.5
 Change level of window which is used for presentation landing.
 Default value is UIWindowLevelStatusBar - 1.
 */
@property (nonatomic, nullable) NSNumber *landingWindowLevel DEPRECATED_MSG_ATTRIBUTE("use modalWindowLevel in CXAppConfig instead.");

/*!
 Defines background color for notification activity and in-apps,
 by default it's white color.

 WARNING! This method is obsoleted. Please configure landings through activitySettings
 */
@property (nonatomic, copy, null_resettable) NSString *landingBackgroundColor;

/*!
 Defines main application color, that will be used in notification activities and in-apps
 as a default accent color (e.g. for button background and links in html).
 By default it,s #0A83FF

 WARNING! This method is obsoleted. Please configure landings through activitySettings
 */
@property (nonatomic, copy, null_resettable) NSString *landingAccentColor;

/*!
 Defines text color. By default it's black color

 WARNING! This method is obsoleted. Please configure landings through activitySettings
 */
@property (nonatomic, copy, null_resettable) NSString *landingTextColor;

/*!
 Defines button text color. By default it's white color

 WARNING! This method is obsoleted. Please configure landings through activitySettings
 */
@property (nonatomic, copy, null_resettable) NSString *landingButtonTextColor;

/*!
 Defines close button color. By default it's white color.

 WARNING! This method is obsoleted. Please configure landings through activitySettings
 */
@property (nonatomic, copy, null_resettable) NSString *landingCloseButtonColor;

/*!
    Throttle timeout defines time period between an  application first start and the first
    request execution. Allows to an application move all not vital actions away from statup process.
    Call of methods setUserId or setPushToken forces sending settings to server ignoring this property.
    By default returns 30 sec.
 */
@property (nonatomic, strong, null_resettable) NSNumber * settingsCheckThrottleTimeout;

/**
Allows to configure various params of landing with type activity. F.e. supporting dark mode and enable dynamic fonts.
 */
@property (nonatomic, readonly) CXNotifyActivitySettings * activitySettings;

@end

NS_ASSUME_NONNULL_END
