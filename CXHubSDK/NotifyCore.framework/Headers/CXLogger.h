#import <Foundation/Foundation.h>

#define __CXLogPrivate(level, format, ...) if (CXLogger.logLevel >= level) { \
                                                [CXLogger logMessage:level \
                                                              message:format, ##__VA_ARGS__]; \
                                            }

#if DEBUG

#define CXLogFatal(format, ...) \
[NSString stringWithFormat:format, ##__VA_ARGS__]; \
__CXLogPrivate(CXLoggerLogLevelFatal, format, ##__VA_ARGS__)

#define CXLogError(format, ...) \
[NSString stringWithFormat:format, ##__VA_ARGS__]; \
__CXLogPrivate(CXLoggerLogLevelError, format, ##__VA_ARGS__)

#define CXLogWarn(format, ...) \
[NSString stringWithFormat:format, ##__VA_ARGS__]; \
__CXLogPrivate(CXLoggerLogLevelWarn, format, ##__VA_ARGS__)

#define CXLogInfo(format, ...) \
[NSString stringWithFormat:format, ##__VA_ARGS__]; \
__CXLogPrivate(CXLoggerLogLevelInfo, format, ##__VA_ARGS__)

#define CXLogDebug(format, ...) \
[NSString stringWithFormat:format, ##__VA_ARGS__]; \
__CXLogPrivate(CXLoggerLogLevelDebug, format, ##__VA_ARGS__)

#define CXLogTrace(format, ...) \
[NSString stringWithFormat:format, ##__VA_ARGS__]; \
__CXLogPrivate(CXLoggerLogLevelTrace, format, ##__VA_ARGS__)

#else

#define CXLogFatal(format, ...) __CXLogPrivate(CXLoggerLogLevelFatal, format, ##__VA_ARGS__)
#define CXLogError(format, ...) __CXLogPrivate(CXLoggerLogLevelError, format, ##__VA_ARGS__)
#define CXLogWarn(format, ...) __CXLogPrivate(CXLoggerLogLevelWarn, format, ##__VA_ARGS__)
#define CXLogInfo(format, ...) __CXLogPrivate(CXLoggerLogLevelInfo, format, ##__VA_ARGS__)
#define CXLogDebug(format, ...) __CXLogPrivate(CXLoggerLogLevelDebug, format, ##__VA_ARGS__)
#define CXLogTrace(format, ...) __CXLogPrivate(CXLoggerLogLevelTrace, format, ##__VA_ARGS__)

#endif


typedef NS_ENUM(NSInteger, CXLoggerLogLevel) {
    CXLoggerLogLevelNone,
    CXLoggerLogLevelFatal,
    CXLoggerLogLevelError,
    CXLoggerLogLevelWarn,
    CXLoggerLogLevelInfo,
    CXLoggerLogLevelDebug,
    CXLoggerLogLevelTrace,
    CXLoggerLogLevelAll
};

NS_ASSUME_NONNULL_BEGIN

@interface CXLogger : NSObject

+(instancetype)new NS_UNAVAILABLE;
-(instancetype)init NS_UNAVAILABLE;

+ (void)logMessage:(CXLoggerLogLevel)level
           message:(NSString *)message, ...;

@property (nonatomic, class, assign) CXLoggerLogLevel logLevel;

@end

NS_ASSUME_NONNULL_END
