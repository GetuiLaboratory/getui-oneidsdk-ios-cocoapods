//
//  OneID.h
//  OneID
//
//  Created by ak on 2024/2/4.
//  OneID-Version: 1.0.0.0

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol OneIDDelegate <NSObject>
 
@optional
///实时获取ID的回调
- (void)OneIDFetch:(NSDictionary *)info error:(nullable NSError *)error;
@end
 
@interface OneID : NSObject
 
+ (void)startSdkWithAppId:(NSString *)appid delegate:(id<OneIDDelegate>)delegate;

+ (NSString*)sdkVersion;

@end

NS_ASSUME_NONNULL_END
