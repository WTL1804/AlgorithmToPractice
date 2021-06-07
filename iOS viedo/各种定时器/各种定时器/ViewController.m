//
//  ViewController.m
//  各种定时器
//
//  Created by 王天亮 on 2021/6/6.
//

#import "ViewController.h"
#import "SecondViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor greenColor];
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    SecondViewController *tempVC = [[SecondViewController alloc] init];
    [self presentViewController:tempVC animated:YES completion:nil];
}


@end
