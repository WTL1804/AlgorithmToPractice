//
//  ViewController.m
//  test
//
//  Created by 王天亮 on 2020/9/10.
//  Copyright © 2020 王天亮. All rights reserved.
//

#import "ViewController.h"
@interface ViewController () 

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    //_viewB = [[ViewControllerB alloc] init];
    //_viewB.delegate = self;
    
    ViewControllerB *viewB = [[ViewControllerB alloc] init];
//    _viewB = viewB;
//    _viewB.delegate = self;
    [self.navigationController pushViewController:viewB animated:YES];
}

- (void)click {
    NSLog(@"delegateCLick");
}
@end
