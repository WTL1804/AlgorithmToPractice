//
//  NextViewController.m
//  GCDiOS
//
//  Created by 王天亮 on 2020/9/26.
//

#import "NextViewController.h"

@interface NextViewController ()

@end

@implementation NextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view
//
//    self.view.backgroundColor = [UIColor whiteColor];
//    NextViewController *next = [[NextViewController alloc] init];
//    [self.navigationController pushViewController:next animated:YES];
//
//    self.timer = [NSTimer timerWithTimeInterval:1.0 target:self selector:@selector(timerRun) userInfo:nil repeats:YES];
//    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSDefaultRunLoopMode];
    NextViewController * __weak weakSelf = self;
    self.timer = [NSTimer scheduledTimerWithTimeInterval:1.f target:weakSelf selector:@selector(timerRun) userInfo:nil repeats:YES];
}
//- (void)viewWillDisappear:(BOOL)animated {
//    [self.timer invalidate];
//    self.timer = nil;
//}
- (void)timerRun {
    NSLog(@"%s", __func__);
}
- (void)dealloc {
        [self.timer invalidate];
        self.timer = nil;
    NSLog(@"%s", __func__);
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
