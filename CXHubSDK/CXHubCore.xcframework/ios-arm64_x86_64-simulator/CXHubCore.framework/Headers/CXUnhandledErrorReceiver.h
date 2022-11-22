#import <Foundation/Foundation.h>

/**
 * An application is able to provide an object implementing this protocol to receive information
 * about critical failures in libnotify SDK internal logic. This information should be
 * reported to a crash handling system.
 * */
@protocol CXUnhandledErrorReceiver <NSObject>

-(void) onUnhandledException:(NSException *) exception;
-(void) onUnexpectedError:(NSError *) error;

@end
