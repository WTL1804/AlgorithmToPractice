//
//  Person.h
//  单例的释放
//
//  Created by 王天亮 on 2020/12/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
+ (instancetype)sharedLeton;
@end

NS_ASSUME_NONNULL_END
