//
//  Person.m
//  autoreleaseAndretainTest
//
//  Created by 王天亮 on 2020/12/2.
//

#import "Person.h"

@implementation Person
+ (id)somePerson {
    Person *person = [[Person alloc] init];
    return person;
}
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    
    NSLog(@"%@", [NSThread currentThread]);
}
@end
