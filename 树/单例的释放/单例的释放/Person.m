//
//  Person.m
//  单例的释放
//
//  Created by 王天亮 on 2020/12/8.
//

#import "Person.h"

@implementation Person
static Person * manageCustom;
+ (instancetype)sharedLeton {
    static dispatch_once_t onceToken;
    if (!manageCustom) {
        dispatch_once(&onceToken, ^{
            manageCustom = [[super allocWithZone:NULL] init] ;
        });
    }
    return manageCustom;
}
+(id) allocWithZone:(struct _NSZone *)zone
{
    return [Person sharedLeton] ;
}
@end
