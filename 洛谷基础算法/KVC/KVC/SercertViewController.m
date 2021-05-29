//
//  SercertViewController.m
//  KVC
//
//  Created by 王天亮 on 2020/11/1.
//

#import "SercertViewController.h"

@interface SercertViewController ()
//@property (nonatomic, copy) NSString *string;
@end

@implementation SercertViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor redColor];
    _string = [[NSString alloc] init];
}
- (void)print {
    NSLog(@"%@", _string);
}
+ (BOOL)accessInstanceVariablesDirectly {
    return NO;
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
