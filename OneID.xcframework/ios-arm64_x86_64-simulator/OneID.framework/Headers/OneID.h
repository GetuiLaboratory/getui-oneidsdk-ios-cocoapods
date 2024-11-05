//
//  OneID.h
//  OneID
//
//  Created by ak on 2024/2/4.
//  OneID-Version: 1.0.5.0

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

/// 查询Lbs数据（获取时间间隔内的gps数据，如果超出间隔则实时获取gps数据）
/// - Parameter gpsInterval: gps有效期设置，可以设置范围为-1 或 [0, 600]，单位秒。0：实时获取gps数据。 -1：使用系统缓存的gps数据
/// - Parameter gpsTimeout: 超时设置，可以设置范围为[10, 60]，单位秒,  建议设置20
+ (void)queryLbs:(NSTimeInterval)gpsInterval gpsTimeout:(NSTimeInterval)gpsTimeout;

+ (NSString*)sdkVersion;

@end

NS_ASSUME_NONNULL_END
