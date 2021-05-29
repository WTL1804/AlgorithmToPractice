//
//  Test.m
//  autoreleaseAndretainTest
//
//  Created by 王天亮 on 2020/12/2.
//

#import "Test.h"
#import "Person.h"
extern int _objc_autoreleasePoolPrint(void);
@implementation Test
- (void)test{
//    Person *person = [Person somePerson];
////    [person retain];
//    _objc_autoreleasePoolPrint();
    for (int i = 0; i < 1; i++) {
        NSThread *thread = [[NSThread alloc] initWithBlock:^{
            NSLog(@"%@",[NSRunLoop currentRunLoop]);
            @autoreleasepool {
                
            Person *person = [Person somePerson];
//            NSLog(@"%p", person);
            _objc_autoreleasePoolPrint();
            }
            _objc_autoreleasePoolPrint();
           
        }];
        [thread start];
    }
}
@end
