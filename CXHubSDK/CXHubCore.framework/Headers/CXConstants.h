#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>

#import <CXHubCore/CXMacros.h>

NS_ASSUME_NONNULL_BEGIN

@class UNNotificationContent;

/**
 * Alias for void function with argument of type @{link UIBackgroundFetchResult}.
 * */
typedef void (^CXBackgroundFetchCallback)(UIBackgroundFetchResult);
/**
 * Alias for void function without arguments.
 * */
typedef void (^CXCallBack)(void);

/**
 * Alias for function that will handle modified content from service extension.
 * */
typedef void (^CXServiceExtensionCallback)(UNNotificationContent *);

/**
 * Alias for callback from AppDelegate
 * */
typedef void (^CXAppForegroundCallback)(UNNotificationPresentationOptions options);

/**
  The error domain for all errors from notify-core,  libnotify SDKs.
 */
CX_EXTERN NSString *const CXErrorDomain;

/**
 NS_ENUM(NSInteger, CXErrorCode)
  Error codes for CXErrorDomain.
 */
typedef NS_ENUM(NSInteger, CXErrorCode)
{
    /**
      NO ERROR.
     */
    CXEmptyErrorCode = 0,
    CXErrorArgumentErrorCode,
    CXNetworkCancelledErrorCode,
    CXNetworkClientErrorCode,
    CXNetworkGeneralErrorCode,
    CXNetworkJsonParseErrorCode,
    CXNetworkJsonSerializeErrorCode,
    CXNetworkIOErrorCode,
    CXEventsDbErrorCode,
    CXNetworkServerErrorErrorCode,
    CXNetworkNoDataToSendErrorCode,
    CXUIRenderingErrorErrorCode,
    CXLandingHandlingUnknownMessageTypeErrorCode,
    CXLandingHandlingLandingAlreadyPresentedErrorCode,
};

/*
 @method group error userInfo keys
 */

/**
  The userInfo key SDK type.

  Could have any value from {CXCoreSDKType, CXLibnotifySDKType}.
 */
CX_EXTERN NSString *const CXSDKTypeKey;

/**
  The userInfo value for key CXSDKTypeKey.

  An error has been generated by notify-core SDK.
 */
CX_EXTERN NSString *const CXCoreSDKType;

/**
  The userInfo value for key CXSDKTypeKey.

  An error has been generated by libnotify SDK.
 */
CX_EXTERN NSString *const CXLibnotifySDKType;

/**
  The userInfo key for the invalid collection for errors with CXInvalidArgumentErrorCode.

 If the invalid argument is a collection, the collection can be found with this key and the individual
 invalid item can be found with CXErrorArgumentValueKey.
 */
CX_EXTERN NSString *const CXErrorArgumentCollectionKey;

/**
  The userInfo key for the invalid argument name for errors with CXInvalidArgumentErrorCode.
 */
CX_EXTERN NSString *const CXErrorArgumentNameKey;

/**
 The userInfo key for the invalid argument value for errors with CXInvalidArgumentErrorCode.
 */
CX_EXTERN NSString *const CXErrorArgumentValueKey;

/**
  The userInfo key for the message for developers in NSErrors that originate from the SDK.
  The developer message will not be localized and is not intended to be presented within the app.
 */
CX_EXTERN NSString *const CXErrorDeveloperMessageKey;

/**
  The userInfo key describing a localized description that can be presented to the user.
 */
CX_EXTERN NSString *const CXErrorLocalizedDescriptionKey;

/**
  The userInfo key describing a localized title that can be presented to the user, used with `CXLocalizedErrorDescriptionKey`.
 */
CX_EXTERN NSString *const CXErrorLocalizedTitleKey;

/**
  The userInfo key describing an original error.
 */
CX_EXTERN NSString *const CXErrorWrappedErrorKey;

/**
  The userInfo key describing a failed request url.
 */
CX_EXTERN NSString *const CXErrorRequestUrlKey;

/**
  The userInfo key describing a http server status code.
 */
CX_EXTERN NSString *const CXErrorServerStatusCodeKey;

/**
  The userInfo key describing an original exception.
 */
CX_EXTERN NSString *const CXErrorWrappedExceptionKey;

/**
  The userInfo key describing a failed events db operation.
 */
CX_EXTERN NSString *const CXErrorEventsDbOperationKey;

/**
  The userInfo key describing a failed file operation.
 */
CX_EXTERN NSString *const CXErrorFileOperationKey;

/**
  The userInfo key describing a failed UI logic.
 */
CX_EXTERN NSString *const CXUIErrorCodeKey;

/**
  The userInfo key describing an error stacktrace if available.
 */
CX_EXTERN NSString *const CXErrorStackTraceKey;

NS_ASSUME_NONNULL_END
