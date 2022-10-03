#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>

#import <CXHubNotify/CXNotifyEventsCollector.h>
#import <CXHubNotify/CXNotifyGDPRSupport.h>

/*!
 States for notifications

 - CXNotificationStateEnabled: All notifications are enabled (by default)
 - CXNotificationStateDisabled: All notifications are disabled
 - CXNotificationStateOnlyTransactions: Only notifications "on request" are enabled
 */
typedef NS_ENUM(NSInteger, CXNotificationState) {
    CXNotificationStateEnabled = 0,
    CXNotificationStateDisabled,
    CXNotificationStateOnlyTransactions
};

NS_ASSUME_NONNULL_BEGIN

@protocol CXNotifyDelegate;

/*!
 {@link CXNotifyApi} is the main libnotify interface which provides all functionality for
 application event tracking. All interface methods are designed to be maximally
 lightweight as possible and asynchronous as well. So, they can be called from an arbitrary
 application thread, including <b>MainThread</b>.
 */
@protocol CXNotifyApi <CXNotifyEventsCollector, CXNotifyGDPRSupport>

/*!
 Allows to bind some user id to a particular libnotify (application) instance, which could
 be used to send notifications.
 @param userId email, phone or other unique user id
 */
-(void) setUserId:(nullable NSString *) userId;

/*!
 Return saved user id
 */
-(NSString *) getUserId;

/*!
 Return saved user id
 */
-(void) setUserIdChangeListener:(void (^)(NSString *, NSString *)) listener;


/*!
 State of notifications
 */
@property (nonatomic, assign) CXNotificationState notificationState;

/*!
 Set delegate for libnotify.

 @param delegate Object that will handle various events from libnotify
 */
-(void) setDelegate:(nullable id<CXNotifyDelegate>)delegate;

/*!
 @deprecated
 */
-(void) setProperty:(NSString *) key withValueObject:(NSObject *) value __attribute__((deprecated("Use setInstanceProperty:withStringValue:, setInstanceProperty:withArrayValue: or setInstanceProperty:withDictionaryValue")));

/*!
 @deprecated
 */
-(void) setProperty:(NSString *) key
    withValueObject:(NSObject *) value
 withImmediateLogic:(BOOL) deliverImmediately __attribute__((deprecated("Use setInstanceProperty:withStringValue:, setInstanceProperty:withArrayValue: or setInstanceProperty:withDictionaryValue:")));

#pragma mark - Set instance property
/*!
 Sets named property for this particular instance.
 @param keyString property key
 @param valueString property string value
 */
-(void) setInstanceProperty: (NSString *) keyString
            withStringValue: (NSString *) valueString;

/*!
 Sets named property for this particular instance.
 @param keyString property key
 @param valueArray property value
 */
-(void) setInstanceProperty: (NSString *) keyString
             withArrayValue: (NSArray *) valueArray;

/*!
 Sets named property for this particular instance.
 @param keyString property key
 @param valueString property string value
 @param valueArray property value
 */
-(void) setInstanceProperty: (NSString *) keyString
            withStringValue: (nullable NSString *) valueString
             withArrayValue: (NSArray *) valueArray;

/*!
 Sets named property for this particular instance.
 @param keyString property key
 @param valueDictionary property value
 */
-(void) setInstanceProperty: (NSString *) keyString
        withDictionaryValue: (NSDictionary *) valueDictionary;

/*!
 Sets named property for this particular instance.
 @param keyString property key
 @param valueString property string value
 @param valueDictionary property value
 */
-(void) setInstanceProperty: (NSString *) keyString
            withStringValue: (nullable NSString *) valueString
        withDictionaryValue: (NSDictionary *) valueDictionary;


#pragma mark - Rest of methods
/*!
 Allows to pass device push token to libnotify API. Use unchanged value received from AppDelegate
 callback.
 @param deviceToken device push token
 */
-(void) updatePushRegistrationId:(NSData *) deviceToken;

/*!
 An application could call this method to obtain libnotify instance_id, which could be used to
 send push notifications directly to this particular instance via notify.mail.ru API.
 @returns libnotify instance_id
 */
-(NSString *) getInstanceId;

/*!
 An application could call this method to obtain push notification token, which could be used to
 send push notifications directly to this particular token via Knuff.
 @returns libnotify push_notification_token
 */
-(NSString *) getPushNotificationToken;

/*!
 Allows to clear all libnotify cached push notification content.
 */
-(void) clearCache;

// MARK: - Deprecated methods

/*!
 @deprecated after version 1.0.5
 Set the window level of presentation landing.

 Due to the landing is shown in separate window you may
 want to set the different level of this window. By default
 window level is UIWindowLevelStatusBar - 1.

 @param landingWindowLevel may be any new value or nil if you want to reset this value.
 */
-(void) setLandingWindowLevel:(nullable NSNumber *)landingWindowLevel DEPRECATED_MSG_ATTRIBUTE("use modalWindowLevel in CXAppConfig instead.");

@end

NS_ASSUME_NONNULL_END
