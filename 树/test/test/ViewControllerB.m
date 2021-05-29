//
//  ViewControllerB.m
//  test
//
//  Created by 王天亮 on 2020/9/10.
//  Copyright © 2020 王天亮. All rights reserved.
//

#import "ViewControllerB.h"
@interface ViewControllerB ()

@end

@implementation ViewControllerB

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor redColor];
    _clickButton = [UIButton buttonWithType:UIButtonTypeCustom];
    _clickButton.frame = CGRectMake(100, 100, 100, 100);
    _clickButton.backgroundColor = [UIColor whiteColor];
    [_clickButton setTitle:@"click" forState:UIControlStateNormal];
    [_clickButton addTarget:self action:@selector(back) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_clickButton];
    
    
    _viewC = [[ViewControllerC alloc] init];
    _viewC.delegate = self;
    [self.navigationController pushViewController:_viewC animated:YES];
    
}
- (void)click {
    NSLog(@"123");
}
- (void)back {
//    [self.delegate click];
    [self.navigationController popViewControllerAnimated:YES];
}
- (void)dealloc {
    NSLog(@"123");
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
