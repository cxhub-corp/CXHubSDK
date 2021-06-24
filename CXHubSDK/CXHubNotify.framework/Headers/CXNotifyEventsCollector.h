#import <Foundation/Foundation.h>

typedef NSDictionary<NSString *, NSObject<NSCoding> *> * CXEventProperties;

NS_ASSUME_NONNULL_BEGIN

@protocol CXNotifyEventsCollector <NSObject>

/*!
 This method collects single event with a key, value and properties dictionary.
 Key has NSString type.

 Value my be instance of any class but instances of NSString and NSNumber are preferred. Instances of other classes will be
 substituted by their description (NSString value).

 !!! This behaviour will be removed soon and events will be rejected if their value are instances of other classes. !!!

 Keys of properties dictionary should be instance of NSString and values should be whether NSString or NSNumber.
 Libnotify will accumulate all identical events and pass them into libnotify API as an aggregated value according to next rules:

 For NSNumber values:
 @code
 CXNotificationApi.collectEvent(@"test", @(1));
 CXNotificationApi.collectEvent(@"test", @(2));
 CXNotificationApi.collectEvent(@"test", @(3));
 @endcode

 The call sequence above will result in libnotify call with something like:
 @code
 {
 "name" : "test",
 "count" : 3,
 "first_timestamp" : 123123123,
 "last_timestamp" : 2131231231,
 "max" : 3,
 "min" : 1,
 "sum" : 6
 }
 @endcode

 This is really useful if you want to use some time or performance metrics to segment
 your application auditory into slices.

 For NSString values:
 @code
 CXNotificationApi.collectEvent(@"test", @"some");
 CXNotificationApi.collectEvent(@"test", @"some");
 CXNotificationApi.collectEvent(@"test", @"some");
 @endcode

 The call sequence above will result in libnotify call with something like:

 @code
 {
 "name" : "test",
 "value" : "some"
 "count" : 3,
 "first_timestamp" : 123123123,
 "last_timestamp" : 2131231231
 }
 @endcode

 Thus, libnotify uses internal logic for gluing events that has been produced originated
 in some short period of time, which allows decrease client to server traffic
 and increase server throughput.

 Below there are few helper methods. All of them calls this method.

 @param key event key
 @param value event value
 @param properties is a dictionary with keys as NSString and values as NSString or NSNumber.
 @param deliverImmediately says to send event asap
 */
-(void)collectEvent:(NSString *)key
          withValue:(nullable NSObject *)value
     withProperties:(nullable CXEventProperties)properties
 withImmediateLogic:(BOOL)deliverImmediately;

-(void)collectEvent:(NSString *)key;

-(void)collectEvent:(NSString *)key
     withProperties:(nullable CXEventProperties)properties;

-(void)collectEvent:(NSString *)key
 withImmediateLogic:(BOOL)deliverImmediately;

-(void)collectEvent:(NSString *)key
     withProperties:(nullable CXEventProperties)properties
 withImmediateLogic:(BOOL)deliverImmediately;

-(void)collectEvent:(NSString *)key
          withValue:(nullable NSObject *)value
     withProperties:(nullable CXEventProperties)properties;

/*!
 Collects multiple events in a single method call. It is preferable way to deliver several
 events with some values to libnotify SDK.
 @param mapping between event name and it's value
 */
-(void)collectEventMap:(NSDictionary<NSString *, NSObject *> *)mapping;

/*!
 Works as method {@link CXNotificationApi#collectEvent(NSDictionary)}, but allows to
 an application deliver collected events as soon as possible.
 @param mapping between event name and it's value
 @param deliverImmediately YES - if an application wishes to deliver this event as soon as possible,
 NO - otherwise
 */
-(void)collectEventMap:(NSDictionary<NSString *, NSObject *> *)mapping
    withImmediateLogic:(BOOL)deliverImmediately;

// MARK: - Deprecated methods

/**
 Next methods will be removed in the nearest version of the library.
 */

/*!
 @param key - The key of event
 @param value - Object that will be sent as a value.
 */
-(void)collectEvent:(NSString *)key
    withValueObject:(nullable NSObject *)value;

/*!
 @param key - The key of event
 @param value - Object that will be sent as a value
 @param deliverImmediately - Flag to say that event should be sent asap
 */
-(void)collectEvent:(NSString *)key
    withValueObject:(nullable NSObject *)value
 withImmediateLogic:(BOOL)deliverImmediately;

-(void)collectEvent:(NSString *)key
          withValue:(nullable NSString *)value;

-(void)  collectEvent:(NSString *)key
            withValue:(nullable NSString *)value
   withImmediateLogic:(BOOL)deliverImmediately;

@end

NS_ASSUME_NONNULL_END
