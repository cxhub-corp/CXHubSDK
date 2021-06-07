#import <Foundation/Foundation.h>

/**
 * Content payload attachment type
 * */
typedef NS_ENUM(NSInteger, CXExtensionAttachmentType) {
    CXExtensionAttachmentTypeImage,
    CXExtensionAttachmentTypeVideo
};

/**
 * Represents data response from libnotify extension api request. Allows to show big image or video using
 * content extension mechanism.
 * */
@interface CXContentExtensionData : NSObject
/**
 * Notification title
 */
@property (nonatomic, readonly, copy) NSString * title;
/**
 * Main notification content
 * */
@property (nonatomic, readonly, copy) NSString * body;
/**
 * @returns YES - if this is final version of content for a particular notification,
 * NO - otherwise (for instance libnotify may start to download image/video), so content extension
 * could show some kind of progress to user.
 * */
@property (nonatomic, readonly) BOOL isFinal;
/**
 * Image/video raw data
 * */
@property (nonatomic, readonly) NSData * attachmentData;
/**
 * Describes attachment type
 * */
@property (nonatomic, readonly) CXExtensionAttachmentType type;

- (instancetype)initWithTitle:(NSString *)title
                         body:(NSString *)body
                      isFinal:(BOOL)isFinal
               attachmentData:(NSData *)attachmentData
                         type:(CXExtensionAttachmentType)type;

@end
