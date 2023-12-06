#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

#import <CXHubCore/CXConstants.h>
#import <CXHubCore/CXUnhandledErrorReceiver.h>
#import <CXHubCore/CXMonitoringEventReceiver.h>

typedef NS_ENUM(NSUInteger, CXWillPresentNotificationResult) {
    /**
     * Everything is OK
     */
    CXWillPresentNotificationResultSuccess,
    /**
     * It seems that push is libnotify  but we cannot handle it
     */
    CXWillPresentNotificationResultFailure,
    /**
     * It's unknown type of push
     */
    CXWillPresentNotificationResultUnknown
};

@class CXAppConfig;

NS_ASSUME_NONNULL_BEGIN

@interface CXApp : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (class, readonly) CXAppConfig *currentConfig;


/**
 * Initialize services with config Notify.config
 * @param eventsReceiver should implement either protocol CXUnhandledErrorReceiver
 * or CXMonitoringEventReceiver or both.
 */
+ (BOOL) initWithDefaultConfigAndEventsReceiver:(nullable id)eventsReceiver NS_SWIFT_NAME(initWithDefaultConfig(andEventsReceiver:)) NS_EXTENSION_UNAVAILABLE("Use method initExtensionWithDefaultConfigAndEventsReceiver: for init library in extension");

/**
 * Initialize services with custom config
 * @param config is a path to config file
 * @param eventsReceiver should implement either protocol CXUnhandledErrorReceiver
 * or CXMonitoringEventReceiver or both.
 */
+ (BOOL) initWithConfig:(CXAppConfig *)config
      withEventsReceiver:(nullable id)eventsReceiver NS_EXTENSION_UNAVAILABLE("Use method initExtensionWithConfig:withEventsReceiver: for init library in extension");

/**
 * Initialize api for extension with config Notify.config
 * @param eventsReceiver should implement either protocol CXUnhandledErrorReceiver
 * or CXMonitoringEventReceiver or both.
 */
+ (BOOL) initExtensionWithDefaultConfigAndEventsReceiver:(nullable id)eventsReceiver NS_SWIFT_NAME(initExtensionWithDefaultConfig(andEventsReceiver:));

/**
 * Initialize api for extension with custom config
 * @param config is a path to config file
 * @param eventsReceiver should implement either protocol CXUnhandledErrorReceiver
 * or CXMonitoringEventReceiver or both.
 */
+ (BOOL) initExtensionWithConfig:(CXAppConfig *)config
              withEventsReceiver:(nullable id)eventsReceiver;

@end

@interface CXApp(UIApplicationDelegate)

/**
 * Allows to an application receive information about internal libnotify thread crashes and errors.
 * This information may be sent to some crash reporting system.
 * @param receiver an application delegate to receive errors
 * */
+ (void)setUnhandledErrorReceiver:(id <CXUnhandledErrorReceiver>)receiver;

/**
 * Allows to an application receive information about internal libverify events.
 * If an application uses libnotify SDK as well, those events could be reported there.
 * @param receiver an application delegate to receive events
 * */
+ (void)setMonitoringEventReceiver:(id <CXMonitoringEventReceiver>)receiver;

/**
 * Forwards system call to libnotify
 * @param application application instance
 * */
+(void) applicationDidBecomeActive:(UIApplication *) application;

/**
 * Forwards system call to libnotify
 * @param application application instance
 * */
+(void) applicationWillResignActive:(UIApplication *) application;

/**
 * Forwards system call to libnotify
 * @param application application instance
 * */
+(void) applicationWillTerminate:(UIApplication *)application;

/**
 * Forwards system call to libnotify
 * @param application application instance
 * */
+(void) applicationSignificantTimeChange:(UIApplication *)application;

/**
 * Forwards system call to libnotify
 * @param application application instance
 * */
+(void) applicationDidEnterBackground:(UIApplication *)application;

/**
 * Forwards system call to libnotify
 * @param application application instance
 * */
+(void) applicationWillEnterForeground:(UIApplication *)application;

/**
 * Proxy method to process background push notifications (content-available=1).
 * Automatically detects whether this data has been originated from libnotify API or not.
 * In case of this is libnotify data, returns aggregated @{link CXBackgroundFetchCallback} callback,
 * which will call the system one after push precessing completion or after timeout expiration.
 * @param userInfo received push notification data
 * @param completionHandler system completion handler
 * @returns aggregated completion handler in case userInfo contains libnotify push data,
 *          otherwise the original system handler
 **/
+(CXBackgroundFetchCallback) didReceiveRemoteNotification:(NSDictionary *)userInfo
                                    fetchCompletionHandler:(CXBackgroundFetchCallback)completionHandler;


/**
 * Proxy method to run libnotify logic (update client-server state) from time to time.
 * @param completionHandler system completion handler
 * @returns aggregated completion handler
 * */
+(nullable CXBackgroundFetchCallback) performFetchWithCompletionHandler:(CXBackgroundFetchCallback) completionHandler;

/**
 * Proxy method to process push notification response from a user.
 * Automatically detects whether this data has been originated from libnotify API or not.
 * In case of this is libnotify data, returns aggregated @{link CXBackgroundFetchCallback} callback,
 * which will call the system one after push precessing completion or after timeout expiration.
 * @param response user push notification response
 * @param completionHandler system completion handler
 * @returns aggregated completion handler in case userInfo contains libnotify push data,
 *          otherwise the original system handler
 * */
+(nullable CXCallBack) didReceiveNotificationResponse:(UNNotificationResponse *)response
                                 withCompletionHandler:(CXCallBack)completionHandler;

/**
 * Proxy method to process push notification action response from a user.
 * Automatically detects whether this data has been originated from libnotify API or not.
 * In case of this is libnotify data, returns aggregated @{link CXBackgroundFetchCallback} callback,
 * which will call the system one after push precessing completion or after timeout expiration.
 * @param response user push notification response
 * @param identifier UNNotificationAction identifier
 * @param completionHandler system completion handler
 * @returns aggregated completion handler in case userInfo contains libnotify push data,
 *          otherwise the original system handler
 * */
+(nullable CXCallBack) didReceiveNotificationResponse:(UNNotificationResponse *)response
                                 withActionIdentifier:(nullable NSString *)identifier
                                withCompletionHandler:(CXCallBack)completionHandler;

/**
 * Proxy method to receive local notifications (when application is in foreground).
 * Automatically detects whether this data has been originated from libnotify API or not.
 * In case of this is libnotify data, returns aggregated @{link CXCallBack} callback,
 * which will call the system one after push precessing completion or after timeout expiration.
 * @param userInfo received push notification data
 * @param completionHandler system completion handler
 * @returns aggregated completion handler in case userInfo contains libnotify push data,
 *          otherwise the original system handler
 * */
+ (CXCallBack) didReceiveLocalNotification:(nullable NSDictionary *)userInfo
                      withCompletionHandler:(CXCallBack)completionHandler;
/**
 * Informs CXHub about push notification permissions state
 * @param notificationSettings received notification settings/permissions
 */

+ (void)didReceiveUserNotificationSettings:(UNNotificationSettings *)notificationSettings;

/**
 * Delivery new device token to all libraries.
 * @param deviceToken device token received from APNS.
 */
+ (void) applicationDidRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 Handle error received during registering push token. Sends internal notify event GcmTokenFailure.
 @param error received error.
 */
+ (void) applicationDidFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

/**
 * With this method library could control whether it should show a notification if an application
 * currently in foreground mode.
 * @param center notification center object
 * @param notification original notification object
 * @param completionHandler completion handler with result notification options
 *
 * @returns CXWillPresentNotificationResultSuccess - if this particular notification originated from libnotify API, valid and
 * will be processed in libnotify. CXWillPresentNotificationResultFailure - if this particular notification originated from
 * libnotify API but cannot be handled of originated from libverify API. CXWillPresentNotificationResultUnknown - if
 * notification was originated from unknown source.
 * */
+(CXWillPresentNotificationResult)userNotificationCenter:(UNUserNotificationCenter *)center
                                  willPresentNotification:(UNNotification *)notification
                                    withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler;

/**
 This method sends a notify internal event UnregisterGcmToken to server.
 It's an assistant method to -[UIApplication unregisterForRemoteNotifications].
 By default this method is called by internal category of UIApplication.
 You have to call this method after calling method -[UIApplication unregisterForRemoteNotifications] if you have disabled method swizzling.
 If swizzling is enabled call of this method will be ignored.
 */
+(void) unregisterForRemoteNotifications;

#pragma mark - Service extension methods

/**
 * Allows to initiate service extension logic from libnotify. It will download all necessary content
 * and send delivery confirmation to libnotify API.
 *
 * @returns YES - if this particular notification originated from libnotify API, valid and
 * will be processed in libnotify, otherwise - NO (in this case other libnotify internal
 * logic and threads will be not initialized).
 * */
+(BOOL) didReceiveExtensionNotificationRequest:(UNNotificationRequest *)request
                            withContentHandler:(CXServiceExtensionCallback)contentHandler;

/**
 * Forces libnotify to complete all content processing logic and call provided in
 * @selector(didReceiveExtensionNotificationRequest:withContentHandler:) method callback with
 * unmodified or partially modified content.
 *
 * @returns YES - if libnotify extension logic has been initialized before, otherwise - NO.
 * */

+(BOOL) serviceExtensionTimeWillExpire;

#pragma mark - Content extension methods

/**
 * Proxy method to process push notification action response from a user via ContentExtension.
 * Automatically detects whether this data has been originated from libnotify API or not.
 * In case of this is libnotify data, returns aggregated @{link CXBackgroundFetchCallback} callback,
 * which will call the system one after push precessing completion or after timeout expiration.
 * @param response user push notification response
 * @param context NSExtensionContext ContentExtension context
 * @param completionHandler system completion handler (will be run, when action processing succeed or fail
 * */

+ (void)didReceiveExtensionNotificationResponse:(UNNotificationResponse *)response
                                 inContext:(NSExtensionContext *)context
                                         completionHandler:(void (^)(UNNotificationContentExtensionResponseOption option))completionHandler;

@end

NS_ASSUME_NONNULL_END
