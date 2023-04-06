#import <Foundation/Foundation.h>

#import <CXHubCore/CXNotifyConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface CXAppConfig : NSObject <NSCopying>

/*!
 This method generates empty config. Before use it you should fill required parameters
 and configure at least one application (libnotify).
 */
+ (nonnull instancetype)emptyConfig;

/*!
 This method reads file Notify.plist from main bundle and returns config. If file isn't exists
 this method returns nil. You can change any parameters in this config without saving to
 source file.
 */
+ (nullable instancetype)defaultConfig;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 Returns whether config loaded from file or nil if file isn't exist.
 @param pathToConfig is a path to .plist file
 */
- (nullable instancetype)initWithConfig:(NSString *)pathToConfig;

/*!
 Global settings
 */

/*!
 isEnabled returns true only if enabled is true and notifyConfig return true on isEnabled
 */
@property (nonatomic, getter=isEnabled) bool enabled;

/*!
 This flag enables or disables verbose mode. If it's enabled library will write
 detailed information in log.
 */
@property (nonatomic, getter=isDebug) bool debug;

/*!
 Identifier of one of shared groups from entitlements file.
 This parameter is required for correct work of extensions.
 */
@property (nonatomic, copy, nullable) NSString *sharedGroupId;

/*!
 Modal interfaces of libnotify are presented in separate windows.
 By default the property windowLevel of these windows has value UIWindowLevelStatusBar - 1.
 But you can change this window level and set required value.
 Now we support static level only. You cannot change this value after initialization of libraries.
 When modal windows are presented they become key window (it's essential requirement)
 therefore you need to check that you handle this case correctly.
 */
@property (nonatomic, nullable) NSNumber *modalWindowLevel;

/*!
 Config of libnotify
 */
@property (nonatomic, readonly) CXNotifyConfig *notifyConfig;

/**
 * Development team identifier (need to use shared UserDefaults between app and extensions)
 */
@property (nonatomic, copy, nullable) NSString *teamId;

@end

NS_ASSUME_NONNULL_END
