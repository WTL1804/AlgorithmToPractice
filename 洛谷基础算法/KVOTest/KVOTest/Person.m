//
//  Person.m
//  KVOTest
//
//  Created by 王天亮 on 2020/10/25.
//

#import "Person.h"

@implementation Person

- (void)didChangeValueForKey:(NSString *)key {
    NSLog(@"did");
    [super didChangeValueForKey:key];
}
- (void)willChangeValueForKey:(NSString *)key {
    NSLog(@"will");
    [super willChangeValueForKey:key];
}
+ (BOOL)automaticallyNotifiesObserversForKey:(NSString *)key {
//    if ([key isEqualToString:@"string"]) {
//        return NO;
//    } else {
//        return  [super automaticallyNotifiesObserversForKey:key];
//    }
    return NO;
}
- (void)setString:(NSString *)string {
     
    [[NSNotificationCenter defaultCenter] postNotificationName:@"success" object:nil];
       [self willChangeValueForKey:@"string"];
    _string = string;
    [self didChangeValueForKey:@"string"];
}

@end
