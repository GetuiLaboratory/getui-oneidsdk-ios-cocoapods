//
//  OneID.h
//  OneID
//
//  Created by ak on 2024/2/4.
//  OneID-Version: 1.0.1.0

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OneIDDelegate <NSObject>

@optional

/// 实时获取ID的回调
- (void)OneIDFetch:(NSDictionary *)info error:(nullable NSError *)error;

/// 查询Lbs数据结果回调
- (void)OneIDQueryLbs:(NSDictionary *)info error:(nullable NSError *)error;

@end


@interface OneID : NSObject

/// 启动SDK
+ (void)startSdkWithAppId:(NSString *)appid delegate:(id<OneIDDelegate>)delegate;

/// 获取缓存中的OneID
+ (NSDictionary*)oneIDFetchInfo;

/// 查询Lbs数据，通过回调- (void)OneIDQueryLbs:(NSDictionary *)info error:(nullable NSError *)error; 接收数据
+ (void)queryLbs;

+ (NSString*)sdkVersion;

@end

NS_ASSUME_NONNULL_END
