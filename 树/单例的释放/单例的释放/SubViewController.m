//
//  SubViewController.m
//  单例的释放
//
//  Created by 王天亮 on 2020/12/9.
//

#import "SubViewController.h"

@interface SubViewController ()

@end

@implementation SubViewController
- (instancetype)init
{
    self = [super init];
    if (self) {
        NSLog(@"1231%@", self.view);
    }
    return self;
}
- (void)loadView {
    [super loadView];
    NSLog(@"loadView");
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSLog(@"123");
}
- (void)cateTest {
    [super cateTest];
    //NSLog(@"sub");
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
