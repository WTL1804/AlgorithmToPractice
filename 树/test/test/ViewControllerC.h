//
//  ViewControllerC.h
//  test
//
//  Created by 王天亮 on 2020/10/27.
//  Copyright © 2020 王天亮. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol ClickDelegate <NSObject>

- (void)click;

@end
@interface ViewControllerC : UIViewController
@property (nonatomic, strong) id <ClickDelegate>delegate;
@end

NS_ASSUME_NONNULL_END
