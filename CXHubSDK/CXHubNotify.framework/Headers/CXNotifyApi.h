#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>

#import <Libnotify/CXNotifyEventsCollector.h>
#import <Libnotify/CXNotifyGDPRSupport.h>

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
 State of notifications
 */
@property (nonatomic, assign) CXNotificationState notificationState;

/*!
 Set delegate for libnotify.

 @param delegate Object that will handle various events from libnotify
 */
-(void) setDelegate:(nullable id<CXNotifyDelegate>)delegate;

/*!
 Sets named property for this particular instance. Unlike events collected using
 one of methods like {@link CXNotificationApi.collectEvent(NSString)}, notify API will keep
 track only for the last value for each property.
 @param key property key
 @param value property value
 */
-(void) setProperty:(NSString *) key withValueObject:(NSObject *) value;

/*!
 Works as method {@link CXNotificationApi#setProperty(NSString, NSObject)}, but allows to
 an application deliver set up properties with their values as soon as possible.
 @param key property key
 @param value property value
 @param deliverImmediately YES - if an application wishes to deliver this property
 as soon as possible, NO - otherwise
 */
-(void) setProperty:(NSString *) key
    withValueObject:(NSObject *) value
 withImmediateLogic:(BOOL) deliverImmediately;

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
