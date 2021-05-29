//
//  ViewControllerB.h
//  test
//
//  Created by 王天亮 on 2020/9/10.
//  Copyright © 2020 王天亮. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ViewControllerC.h"
//@protocol ClickDelegate <NSObject>
//
//- (void)click;
//
//@end
@interface ViewControllerB : UIViewController<ClickDelegate>

//@property (nonatomic, strong) id <ClickDelegate>delegate;

@property (nonatomic, strong) UIButton *clickButton;
@property (nonatomic, strong) ViewControllerC *viewC;

@end

