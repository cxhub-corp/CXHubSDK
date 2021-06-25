#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CXNotifyActivityColorSettings : NSObject <NSCopying>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 Says whether library should handling dark mode or not.
 */
@property (nonatomic, assign) bool darkModeSupported;


/**
 Background color for light-mode.
 Default value is white color
 */
@property (nonatomic, null_resettable, strong) UIColor * backgroundColor;

/**
Text color for light-mode. This color is used as a color of title text and body text.
Default value is black color
*/
@property (nonatomic, null_resettable, strong) UIColor * textColor;

/**
Accent color for light-mode. This color is used as a color of links and buttons.
Default value is #0A83FF
*/
@property (nonatomic, null_resettable, strong) UIColor * accentColor;

/**
Close button color for light-mode.
Default value is white color
*/
@property (nonatomic, null_resettable, strong) UIColor * closeButtonColor;

/**
Button text color for light-mode.
Default value is white color
*/
@property (nonatomic, null_resettable, strong) UIColor * buttonTextColor;

/**
 Background color for dark mode.
 By default it is black color in iOS 13. Before iOS 13 this color is the same as background color for light-mode.
 */
@property (nonatomic, null_resettable, strong) UIColor * darkModeBackgroundColor;

/**
Text color for dark mode.
By default it is white color in iOS 13. Before iOS 13 this color is the same as text color for light-mode.
*/
@property (nonatomic, null_resettable, strong) UIColor * darkModeTextColor;

/**
Accent color for dark mode.
By default it is #0A83FF in iOS 13. Before iOS 13 this color is the same as accent color for light-mode.
*/
@property (nonatomic, null_resettable, strong) UIColor * darkModeAccentColor;

/**
Close button color for dark mode.
By default it is white color in iOS 13. Before iOS 13 this color is the same as close button color for light-mode.
*/
@property (nonatomic, null_resettable, strong) UIColor * darkModeCloseButtonColor;

/**
Button text color for dark mode.
By default it is white color in iOS 13. Before iOS 13 this color is the same as button text color for light-mode.
*/
@property (nonatomic, null_resettable, strong) UIColor * darkModeButtonTextColor;

@end

NS_ASSUME_NONNULL_END
