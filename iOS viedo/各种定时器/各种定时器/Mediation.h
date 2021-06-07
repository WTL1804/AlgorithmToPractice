//
//  Mediation.h
//  各种定时器
//
//  Created by 王天亮 on 2021/6/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Mediation : NSProxy

- (instancetype)initWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_END
