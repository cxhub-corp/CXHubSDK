#import <Foundation/Foundation.h>

#import <CXHubCore/CXMacros.h>
#import <CXHubCore/CXConstants.h>

@class UIApplication;
@class UNNotificationResponse;
@class UNNotificationRequest;
@class UNNotification;

@protocol CXNotifyApi;
@protocol CXNotifyExtensionApi;
@protocol CXContentExtensionDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines first child of {@link CX_LIBNOTIFY_ROOT_DATA_KEY}, that contains all notification
 * content sent from Notify API.
 * */
CX_EXTERN NSString *const CX_LIBNOTIFY_PUSH_DATA_KEY;

/**
 * Defines top level json object of notification content sent from Notify API.
 * */
CX_EXTERN NSString *const CX_LIBNOTIFY_ROOT_DATA_KEY;

/**
 * Defines top level json object of notification content sent from APNS.
 * */
CX_EXTERN NSString *const CX_LIBNOTIFY_APS_DATA_KEY;

/**
 * Defines category key of {@link CX_LIBNOTIFY_APS_DATA_KEY}, that contains category identifier sent from Notify API.
 * */
CX_EXTERN NSString *const CX_LIBNOTIFY_CATEGORY_IDENTIFIER_KEY;

@interface CXNotify : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 * Returns singleton instance of CXNotifyApi
 * */
+(nullable id<CXNotifyApi>) getInstance NS_EXTENSION_UNAVAILABLE("Use method getExtensionInstance for receiving instance.");

/**
 * Returns singleton CXNotifyExtensionApi instance. This extension api may be used from an application
 * content or service extensions to enable images in libnotify push notifications and more reliable
 * delivery confirmation logic.
 * */
+(nullable id<CXNotifyExtensionApi>) getExtensionInstance;

/**
 * Shows libnotify debug view with buttons to query instance properties.
 * */
+(void) showDebugSettings NS_EXTENSION_UNAVAILABLE("This method is available only in host application.");

/**
 * Allows an application content extension to query provided big content (image/video)
 * for a notification. In most cases all necessary content will be already downloaded by service
 * extension, so this method work very fast.
 * @param notification original notification object
 * @param delegate to be called during content retrieval process
 *
 * @returns YES - if this particular notification originated from libnotify API, valid and
 * will be processed in libnotify, otherwise - NO (in this case other libnotify internal
 * logic and threads will be not initialized).
 * */
+(BOOL) requestNotificationExtensionContent:(UNNotification *)notification
                               withDelegate:(id<CXContentExtensionDelegate>) delegate;

@end

NS_ASSUME_NONNULL_END
