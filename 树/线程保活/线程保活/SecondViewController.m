//
//  SecondViewController.m
//  线程保活
//
//  Created by 王天亮 on 2020/12/17.
//

#import "SecondViewController.h"
#import "MyThread.h"
@interface SecondViewController ()

@end

@implementation SecondViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    MyThread *thread = [[MyThread alloc] initWithTarget:self selector:@selector(doSomeThing) object:nil];
    [thread start];
}
- (void)doSomeThing {
    NSLog(@"%s", __func__);
    NSTimer *timer = [NSTimer timerWithTimeInterval:1 target:self selector:@selector(test) userInfo:nil repeats:NO];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] run];
 
    NSLog(@"ok");
}
- (void)test {
    NSLog(@"%s", __func__);
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self dismissViewControllerAnimated:YES completion:nil];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
