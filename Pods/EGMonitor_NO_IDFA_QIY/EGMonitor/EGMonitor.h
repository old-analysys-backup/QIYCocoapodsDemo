//
//  EGMonitor.h
//
//  Created by sysylana on 2015/5/22.
//  Copyright © 2015年 Analysys. All rights reserved.
//

#import <Foundation/Foundation.h>

#define EGConfigInstance [EGMonitorConfig shareInstance]

/**
 SDK配置信息，定义配置参数，如：
    EGConfigInstance.appKey = @"097ju86543728197y";
    EGConfigInstance.channelId = @"App Store";
    EGConfigInstance.debugEnable = YES;
    [EGMonitor startWithConfigure:EGConfigInstance];
 */
@interface EGMonitorConfig : NSObject

+ (instancetype)shareInstance;

/** 必填项，易观方舟平台申请 http://dev.analysys.cn/static/ */
@property (nonatomic, copy) NSString *appKey;

/** 渠道名称, 默认渠道：App Store */
@property (nonatomic, copy) NSString *channelId;

/**
 是否调试模式，默认：NO
 若为YES，调试模式，SDK将统计数据发送到回传测试服务器供查看、调试是否配置正确；同时会打开SDK日志打印功能；
 若为NO，非调试模式，SDK将统计数据发送到正式环境；同时关闭SDK日志打印功能。
 ---- 正式发布,Release模式下一定将此属性设置为非debug模式，即：NO ----
 */
@property (nonatomic, assign) BOOL debugEnable;


@end




@interface EGMonitor : NSObject

#pragma mark - 配置SDK信息
/**
 初始化易观统计

 @param configure EGMonitorConfig实例
 */
+ (void)startWithConfigure:(EGMonitorConfig *)configure;

/**
 是否调试模式，默认：NO
 若为YES，调试模式，SDK将统计数据发送到回传测试服务器供查看、调试是否配置正确；同时会打开SDK日志打印功能；
 若为NO，非调试模式，SDK将统计数据发送到正式环境；同时关闭SDK日志打印功能。
 ---- 正式发布,Release模式下一定将此属性设置为非debug模式，即：NO ----
 */
+ (void)setDebugEnable:(BOOL)debugEnable;


#pragma mark - 页面统计
/**
 页面统计

 @param name 必填项，页面唯一标识
 @param tag 内容标签
 */
+ (void)beginLogPage:(NSString *)name tag:(NSString *)tag;
+ (void)endLogPage:(NSString *)name tag:(NSString *)tag;

/**
 简易版 页面统计
*/
+ (void)beginLogPage:(NSString *)name;
+ (void)endLogPage:(NSString *)name;


#pragma mark -事件统计
/**
 自定义事件统计

 @param eventId 必填项，事件唯一标识
 @param desc 事件描述：如名称
 @param attributes 事件属性
 */
+ (void)event:(NSString *)eventId desc:(NSString *)desc attributes:(NSDictionary *)attributes;

/**
 简易版 事件统计
 */
+ (void)event:(NSString *)eventId;
+ (void)event:(NSString *)eventId desc:(NSString *)desc;
+ (void)event:(NSString *)eventId attributes:(NSDictionary *)attributes;


@end

