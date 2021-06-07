//
//  SecondViewController.m
//  各种定时器
//
//  Created by 王天亮 on 2021/6/6.
//

#import "SecondViewController.h"
#import "Mediation.h"

@interface SecondViewController ()

@property (nonatomic, strong) NSTimer *myTimer;
@property (nonatomic, strong) CADisplayLink *caTimer;
@property (nonatomic, strong) dispatch_source_t disTimer;
@end

@implementation SecondViewController

- (void)dealloc {
    NSLog(@"%s", __func__);
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor blueColor];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    __weak typeof(self) weakSelf = self;
    self.disTimer = dispatch_source_create(DISPATCH_SOURCE_TYPE_TIMER, 0, 0, dispatch_get_main_queue());
    dispatch_source_set_timer(self.disTimer, DISPATCH_TIME_NOW, 5 * NSEC_PER_SEC, 1 * NSEC_PER_SEC);
    dispatch_source_set_event_handler(self.disTimer, ^{
        NSLog(@"%@", self);
        [self begin];
    });
    dispatch_resume(self.disTimer);
    
}

- (void)begin {
    NSLog(@"1");
    [self dismissViewControllerAnimated:YES completion:^{
//        [self.caTimer invalidate];
        dispatch_source_cancel(self.disTimer);
    }];
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
