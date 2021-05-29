//
//  ViewController.m
//  响应者链
//
//  Created by 王天亮 on 2020/10/9.
//

#import "ViewController.h"
#import "BlueView.h"
#import "GreenView.h"
#import "UIView+Test.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor redColor];
    
    BlueView *blueView = [[BlueView alloc] initWithFrame:CGRectMake(100, 100, 200, 200)];
    [self.view addSubview:blueView];
    blueView.backgroundColor = [UIColor blueColor];
    
    GreenView *greenView = [[GreenView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    [blueView addSubview:greenView];
    greenView.backgroundColor = [UIColor greenColor];

}


@end
