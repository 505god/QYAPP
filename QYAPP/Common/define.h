//
//  define.h
//  QYAPP
//
//  Created by 邱成西 on 2017/9/23.
//  Copyright © 2017年 邱大侠. All rights reserved.
//

#ifndef define_h
#define define_h

/**
 打印、输出
 */
#ifdef DEBUG
#define kLog(fmt, ...)   NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif

/**
 沙盒路径
 */
#define kDireDoumentPath  [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
#define kDireCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]

/**
 单列
 */
#define kAppDELEGATE ((AppDelegate *)[[UIApplication sharedApplication] delegate])

/**
 加载xib
 */
#define kLoadXib(string) [[NSClassFromString(string) alloc]initWithNibName:string bundle:nil];

/**
 屏幕宽高
 */
#define kScreenWIDTH [UIScreen mainScreen].bounds.size.width
#define kScreenHEIGHT [UIScreen mainScreen].bounds.size.height

/**
 取色值相关
 */
#define kRGB(r,g,b)          [UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:1.f]
#define lRGBA(r,g,b,a)       [UIColor colorWithRed:(r)/255.f green:(g)/255.f blue:(b)/255.f alpha:(a)]
#define kRGBOF(rgbValue)     [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

/**
 取字体相关
 */
#define kSystemFONT(A)       [UIFont systemFontOfSize:A]

/**
 计算时间
 */
#define kTICK NSDate *startTime = [NSDate date];
#define kTOCK DLog(@"Time: %f", -[startTime timeIntervalSinceNow]);

/**
 数组懒加载
 */
#define kLazyLoadArray(variable)    \
- (NSMutableArray *)variable \
{   \
if (!_##variable)  \
{   \
_##variable = [NSMutableArray array];  \
}   \
return _##variable;    \
}

/**
 字典懒加载
 */
#define kLazyLoadDictionary(variable)    \
- (NSMutableDictionary *)variable \
{   \
if (!_##variable)  \
{   \
_##variable = [NSMutableDictionary dictionary];  \
}   \
return _##variable;    \
}

/**
 iPhone、iPad判断
 */
#define kIsPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kIsPad (UI_USER_INTERFACE_IDIOM()== UIUserInterfaceIdiomPad)

/**
 iPhone、iPad判断
 */
#define kIsPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

/**
 弱引用
 */
#define kWeakSelf(type)__weak typeof(type)weak##type = type;
#define kStrongSelf(type)__strong typeof(type)type = weak##type;

/**
 屏幕方向
 */
#define kOrientationIsLandscape      UIDeviceOrientationIsLandscape([UIDevice currentDevice].orientation)
#define kOrientationIsPortrait       UIDeviceOrientationIsPortrait([UIDevice currentDevice].orientation)

/**
 自定义语言
 */
#define kLocalized(key)  [[NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@",[[NSUserDefaults standardUserDefaults] objectForKey:@"QYLanguage"]] ofType:@"lproj"]] localizedStringForKey:(key) value:nil table:@"QYLanguage"]

/**
 系统国际化
 */
#define kLocalizedTitle(key) NSLocalizedString(key, @"")

/**
 ios版本
 */
#define kPlatform [[[UIDevice currentDevice] systemVersion] floatValue]

/**
 app版本
 */
#define kAppVersion [[NSBundle mainBundle].infoDictionary objectForKey:@"CFBundleShortVersionString"]

/**
 主线程
 */
#define dispatch_main_async_safe(block)\
if ([NSThread isMainThread]) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}
#endif /* define_h */
