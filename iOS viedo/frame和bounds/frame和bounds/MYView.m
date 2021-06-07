//
//  MYView.m
//  frame和bounds
//
//  Created by 王天亮 on 2021/6/5.
//

#import "MYView.h"

@implementation MYView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    // 1.判断下自己能否接收事件
        if (self.userInteractionEnabled == NO || self.hidden == YES || self.alpha <= 0.01)
            return nil;

        // 2.判断下点在不在当前控件上
        if ([self pointInside:point withEvent:event] == NO)
            return  nil; // 点不在当前控件

        // 3.从后往前遍历自己的子控件
        int count = self.subviews.count;
        for (int i = count - 1; i >= 0; i--) {
            // 获取子控件
           UIView *childView = self.subviews[i];

            // 把当前坐标系上的点转换成子控件上的点
          CGPoint childP =  [self convertPoint:point toView:childView];

          UIView *fitView = [childView hitTest:childP withEvent:event];

            if (fitView) {
                return fitView;
            }
        }
        // 4.如果没有比自己合适的子控件,最合适的view就是自己
        return self;
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NSLog(@"%@", self);
}

@end
