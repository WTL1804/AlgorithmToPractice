//
//  Mediation.m
//  各种定时器
//
//  Created by 王天亮 on 2021/6/6.
//

#import "Mediation.h"

@interface Mediation ()

@property (nonatomic, weak) id taget;

@end

@implementation Mediation

- (instancetype)initWithTarget:(id)target {
    self.taget = target;
    return self;
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel {
    return [self.taget methodSignatureForSelector:sel];
}

- (void)forwardInvocation:(NSInvocation *)invocation {
    SEL sel = [invocation selector];
    if ([self.taget respondsToSelector:sel]) {
        [invocation invokeWithTarget:self.taget];
    }
}
- (void)dealloc {
    NSLog(@"%s", __func__);
}

- (id)performSelector:(SEL)aSelector {
    return [self.taget performSelector:aSelector];
}

@end
