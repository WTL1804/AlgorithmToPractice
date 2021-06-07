//
//  ViewController.m
//  frame和bounds
//
//  Created by 王天亮 on 2021/6/5.
//

#import "ViewController.h"
#import "MYView.h"

@interface ViewController ()

@property (nonatomic, strong) MYView *blueView;
@property (nonatomic, strong) MYView *redView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.blueView = [[MYView alloc] initWithFrame:CGRectMake(10, 40, 200, 400)];
    [self.view addSubview:self.blueView];
    self.blueView.backgroundColor = [UIColor blueColor];
    
    self.redView = [[MYView alloc] initWithFrame:CGRectMake(40, 40, 400, 100)];
    [self.blueView addSubview:self.redView];
    self.redView.backgroundColor = [UIColor redColor];
    
}
//- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//    [UIView animateWithDuration:4 animations:^{
//        self.blueView.bounds = CGRectMake(10, 400, 400, 400);
//    }];
//}


@end
