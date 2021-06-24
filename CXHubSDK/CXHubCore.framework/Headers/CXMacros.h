#import <Foundation/Foundation.h>

#ifdef __cplusplus
#define CX_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define CX_EXTERN extern __attribute__((visibility ("default")))
#endif

#define CX_PROF_BEGIN   { NSDate *startTime = [NSDate date];
#define CX_PROF_END   NSLog(@"Time: %f", -[startTime timeIntervalSinceNow]); }

#define CX_PROF_BEGIN_AVR(NUM)  { NSTimeInterval averageTime = 0; for (int i = 0; i < NUM; i++) { NSDate *startTime = [NSDate date];
#define CX_PROF_END_AVR(NUM)   averageTime += -[startTime timeIntervalSinceNow]; } averageTime /= NUM; NSLog(@"Time(avr): %f", averageTime); }

// Macros CX_STRINGIZE allows use values of other macros (like __LINE__, __COUNTER__, e.t.c.) in #define.
#define CX_STRINGIZE_DETAIL(x) #x
#define CX_STRINGIZE(x) CX_STRINGIZE_DETAIL(x)

// objswitch
#define STR(x) #x
#define Suppressed(s) _Pragma(STR(clang diagnostic push)) \
_Pragma(STR(clang diagnostic ignored "-Wobjc-string-compare")) \
s \
_Pragma(CX_STRINGIZE_DETAIL(clang diagnostic pop))

#define Switch(s)                 for (typeof(s) _s_ = (s), __s__ = (s);_s_ != nil; _s_ = nil)

// Uses ==
#define Case(str)                    Suppressed(if (__s__ == str))
#define Case2(str1,str2)             Suppressed(if (__s__ == str1 || __s__ == str2))
#define Case3(str1,str2,str3)        Suppressed(if (__s__ == str1 || __s__ == str2 || __s__ == str3))
#define Case4(str1,str2,str3,str4)   Suppressed(if (__s__ == str1 || __s__ == str2 || __s__ == str3 || __s__ == str4))
#define Case8(str1,str2,str3,str4,str5,str6,str7,str8)   Suppressed(if (__s__ == str1 || __s__ == str2 || __s__ == str3 || __s__ == str4 || __s__ == str5 || __s__ == str6 || __s__ == str7 || __s__ == str8))

// Uses isEqualToString:
#define ECase(str)                   Suppressed(if ([__s__ isEqualTo:str]))
#define ECase2(str1,str2)            Suppressed(if ([__s__ isEqualTo:str1] || [__s__ isEqualTo:str2]))
#define ECase3(str1,str2,str3)       Suppressed(if ([__s__ isEqualTo:str1] || [__s__ isEqualTo:str2] || [__s__ isEqualTo:str3]))
#define ECase4(str1,str2,str3,str4)  Suppressed(if ([__s__ isEqualTo:str1] || [__s__ isEqualTo:str2] || [__s__ isEqualTo:str3] || [__s__ isEqualTo:str4]))

// Uses isEqualToString:
#define ESCase(str)                   Suppressed(if ([__s__ isEqualToString:str]))
#define ESCase2(str1,str2)            Suppressed(if ([__s__ isEqualToString:str1] || [__s__ isEqualToString:str2]))
#define ESCase3(str1,str2,str3)       Suppressed(if ([__s__ isEqualToString:str1] || [__s__ isEqualToString:str2] || [__s__ isEqualToString:str3]))
#define ESCase4(str1,str2,str3,str4)  Suppressed(if ([__s__ isEqualToString:str1] || [__s__ isEqualToString:str2] || [__s__ isEqualToString:str3] || [__s__ isEqualToString:str4]))

#define Default
