#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CXNotifyGDPRSupport <NSObject>

/**
 Allows to an application control libnotify policy about hardware device identifiers tracking.
 @param enabled  true - all legal device identifiers will be tracked and sent to notify API (default value)
                false - all items listed below will be removed from all subsequent requests to notify API
                    1) IDFV (uniquely identifies a device to the app’s vendor)
                    2) WIFI access point name (SSID)
 * */
- (void)setDeviceIdTrackingEnabled:(bool)enabled;

@end

NS_ASSUME_NONNULL_END
