//
//  ViewController.m
//  线程保活
//
//  Created by 王天亮 on 2020/12/17.
//

#import "ViewController.h"
#import "MyThread.h"
#import "SecondViewController.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    MyThread *thread = [[MyThread alloc] initWithTarget:self selector:@selector(doSomeThing) object:nil];
//    [thread start];
}
//- (void)doSomeThing {
//    NSLog(@"%s", __func__);
//    NSTimer *timer = [NSTimer timerWithTimeInterval:2 repeats:NO block:^(NSTimer * _Nonnull timer) {
//        NSLog(@"timer");
//    }];
//    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
//    [[NSRunLoop currentRunLoop] run];
//    NSLog(@"ok");
//}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    SecondViewController *sec = [[SecondViewController alloc] init];
    [self presentViewController:sec animated:YES completion:nil];
}
@end
