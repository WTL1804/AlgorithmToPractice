//
//  ViewController.m
//  单例的释放
//
//  Created by 王天亮 on 2020/12/8.
//

#import "ViewController.h"
#include "Person.h"
#include "test.h"
#include "SubViewController.h"
#include "UIViewController+appear.h"
@interface ViewController ()
@property (atomic, strong) NSData *data;
@end

@implementation ViewController
extern int _objc_autoreleasePoolPrint(void);
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    dispatch_async(dispatch_get_main_queue(), ^{
//        @autoreleasepool {
//
//       Person *person =  [Person sharedLeton];
//        _objc_autoreleasePoolPrint();
//        }
//    });
//    @autoreleasepool {
//
//   Person *person =  [Person sharedLeton];
//    _objc_autoreleasePoolPrint();
//    }
//    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
//    button.frame = CGRectMake(100, 100, 200, 200);
//    button.backgroundColor = [UIColor yellowColor];
//    [self.view addSubview:button];
//    [button addTarget:self action:@selector(hello) forControlEvents:UIControlEventTouchUpInside];
//    UIImageView *imageView = [[UIImageView alloc] init];
//    imageView.frame = CGRectMake(100, 100, 200, 200);
//    imageView.backgroundColor = [UIColor redColor];
//    imageView.userInteractionEnabled = YES;
//    [self.view addSubview:imageView];
    
//    for (int i = 0; i < 10000; i++) {
//        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
//            self.data = [[NSMutableData alloc] init];
//        });
//    }
   // [self cateTest];
    SubViewController *sub = [[SubViewController alloc] init];
//    UIViewController *vc = [[UIViewController alloc] init];
//    [vc viewWillAppear:NO];
//    [vc tests];
//    [sub cateTest];
    NSLog(@"ViewdidLoad");
}
- (void)cateTest {
    NSLog(@"123");
}
- (void)viewWillAppear:(BOOL)animated {
    NSLog(@"ViewAppear");
}
- (void)viewDidAppear:(BOOL)animated {
    NSLog(@"didappear");
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//        @autoreleasepool {
//
//       Person *person =  [Person sharedLeton];
//        _objc_autoreleasePoolPrint();
//        }
}
@end
