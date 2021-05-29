//
//  test.m
//  单例的释放
//
//  Created by 王天亮 on 2020/12/8.
//

#import "test.h"
#import "Person.h"
@implementation test
extern int _objc_autoreleasePoolPrint(void);
+(void)tests {
//    @autoreleasepool {
        
   Person *person =  [Person sharedLeton];
    _objc_autoreleasePoolPrint();
//    }
}
@end
