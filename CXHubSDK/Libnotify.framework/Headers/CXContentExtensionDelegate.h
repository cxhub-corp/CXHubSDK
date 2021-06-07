#import <Foundation/Foundation.h>

@class CXContentExtensionData;
@class UNNotification;

/**
 * Delegate to receive notification content from libnotify
 * */
@protocol CXContentExtensionDelegate <NSObject>
/**
 * Delegate method that will be called from libnotify worker thread with result of
 * content notification request.
 * @param content result content (may be NULL)
 * @param notification original notification
 * @param error describes problems during content request
 * */
-(void) onContentUpdated:(nullable CXContentExtensionData *) content
         forNotification:(nonnull UNNotification *)notification
               withError:(nullable NSError *) error API_AVAILABLE(ios(10.0));

@end
