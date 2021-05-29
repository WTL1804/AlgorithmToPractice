//
//  Person+MRCfile.m
//  AutoreleasePoolTest
//
//  Created by 王天亮 on 2020/11/23.
//

#import "Person+MRCfile.h"

@implementation Person (MRCfile)
- (void)retainTest {
    [self retain];
}
- (unsigned int)retainCountNumber {
    return [self retainCount];
}
- (void)releaseTest {
    [self release];
}
@end
