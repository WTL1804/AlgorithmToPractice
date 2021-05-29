//
//  ViewController.m
//  GCDiOS
//
//  Created by 王天亮 on 2020/9/23.
//

#import "ViewController.h"
#import "NextViewController.h"
@interface ViewController ()

@end

@implementation ViewController

//- (void)loadView {
//    [super loadView];
//}
//+ (instancetype)alloc {
//    NSLog(@"111111");
//    return [super alloc];
//}
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor redColor];
    // Do any additional setup after loading the view

    self.view.backgroundColor = [UIColor whiteColor];
    NextViewController *next = [[NextViewController alloc] init];
    [self.navigationController pushViewController:next animated:YES];

//    self.timer = [NSTimer timerWithTimeInterval:1.0 target:self selector:@selector(timerRun) userInfo:nil repeats:YES];
//    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSDefaultRunLoopMode];

}
//- (void)timerRun {
//    NSLog(@"%s", __func__);
//}
- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
