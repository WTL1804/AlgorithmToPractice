//
//  ViewController.m
//  autoreleaseAndretainTest
//
//  Created by 王天亮 on 2020/12/2.
//

#import "ViewController.h"
#import "Test.h"
#import "Person.h"
@interface ViewController ()
@property (nonatomic, copy) NSArray *array;
@end

@implementation ViewController
extern int _objc_autoreleasePoolPrint(void);
//- (instancetype)init
//{
//    NSLog(@"%@",self.view);
//    return self;
//}
- (void)viewDidLoad {
    [super viewDidLoad];
//    Person *person = [[Person alloc] init];
//    [self addObserver:person forKeyPath:@"array" options:NSKeyValueObservingOptionNew context:nil];
//    dispatch_async(dispatch_get_global_queue(0, 0), ^{
//        NSArray *array2 = [[NSArray alloc] init];
//        self.array = array2;
//    });
//    NSArray *array2 = [[NSArray alloc] init];
//    self.array = array2;
    // Do any additional setup after loading the view.
//    Test *tese = [[Test alloc] init];
//    [tese test];
  
    
 
}


@end
