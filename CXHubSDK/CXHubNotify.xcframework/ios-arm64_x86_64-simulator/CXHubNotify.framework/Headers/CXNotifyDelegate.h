#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol CXNotifyDelegate <NSObject>

/**
 This method is called when user select action open_main
 on landing. It's called in main thread.
 */
- (bool) cxOpenMainInterface;

@optional

/**
 You can implement this method in your class.
 All incoming pushes with url will be tried to open url with this method.
 If your implementation returns true handling of url will be completed else
 logic will call method -[UIApplication openUrl:].
 This method will be called in the main thread.
 */
- (bool)openURL:(NSURL *)url;

#if TARGET_OS_IPHONE
/**
 Next methods allow to configure fonts for landing with type "activity".
 These methods will be called if NotifyConfig->ActivitySettings configured with custom font type.
 In this case library expects that all next methods will be implemented else all custom fonts
 will be ignored and library will use system static fonts.
 */
// MARK: - Fonts

/// Body font. Library uses this font as a base font for activity text. According to formatting text library can
/// add various styles to this font. Like as Bold or Italic.
@property (nonatomic, readonly) UIFont * activityBodyFont;

/// Title font. This font will be used as a main font for activity title.
@property (nonatomic, readonly) UIFont * activityTitleFont;

/// Button title font. This font will be used as a font for buttons in activities.
@property (nonatomic, readonly) UIFont * activityButtonTitleFont;

#endif

@end

NS_ASSUME_NONNULL_END
