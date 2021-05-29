//
//  UIView+Test.m
//  响应者链
//
//  Created by 王天亮 on 2020/10/9.
//

#import "UIView+Test.h"
#import <objc/runtime.h>
@implementation UIView (Test)
+ (void)load {
    Method origin = class_getInstanceMethod([UIView class], @selector(hitTest:withEvent:));
    Method custom = class_getInstanceMethod([UIView class], @selector(wtl_hitTest:withEvent:));
    method_exchangeImplementations(origin, custom);
    
    origin = class_getInstanceMethod([UIView class], @selector(pointInside:withEvent:));
    custom = class_getInstanceMethod([UIView class], @selector(wtl_pointInside:withEvent:));
    method_exchangeImplementations(origin, custom);
}

- (BOOL)wtl_pointInside:(CGPoint)point withEvent:(UIEvent *)event {
    BOOL result = [self wtl_pointInside:point withEvent:event];
    NSLog(@"%@ point", NSStringFromClass([self class]));
    return result;
}
- (UIView *)wtl_hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    UIView *result = [self wtl_hitTest:point withEvent:event];
    NSLog(@"%@ hitTest", NSStringFromClass([self class]));
    return result;
}
@end
