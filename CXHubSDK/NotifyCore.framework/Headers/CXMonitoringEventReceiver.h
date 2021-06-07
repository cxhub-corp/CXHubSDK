#import <Foundation/Foundation.h>

/**
 * An application is able to provide an object implementing this protocol to receive information
 * profiling, performance and debug events in libverify/libnotify SDK internal logic.
 * This information may be reported to an arbitrary system like Google(Firebase) Analytics or Flurry as
 * a backup during integration period.
 * */
@protocol CXMonitoringEventReceiver <NSObject>

-(void) logEvent:(NSString *) key withValue:(NSString *) value;
-(void) logEvent:(NSString *) key withMapping:(NSDictionary<NSString *, NSString *> *) mapping;

@end
