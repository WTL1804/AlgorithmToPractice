//
//  ViewController.m
//  KVC
//
//  Created by 王天亮 on 2020/11/1.
//

#import "ViewController.h"
#import "SercertViewController.h"
#import <objc/runtime.h>
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor greenColor];
    SercertViewController *vc = [[SercertViewController alloc] init];
    //[vc setValue:@"123" forKey:@"string"];
    [vc print];

   
    //[self createLoginTextField];
}
- (void)setValue:(id)value forUndefinedKey:(NSString *)key {
    NSLog(@"%@", key);
}
- (void)createLoginTextField {
    UITextField *loginTextField = [[UITextField alloc] init];
    loginTextField.frame = CGRectMake(15,(self.view.bounds.size.height-52-50)/2, self.view.bounds.size.width-60-18,52);
    loginTextField.delegate = self;
    loginTextField.font = [UIFont systemFontOfSize:14];
    loginTextField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    loginTextField.textColor = [UIColor blackColor];
    
    loginTextField.placeholder = @"用户名/邮箱";
    [loginTextField setValue:[UIFont systemFontOfSize:15] forKeyPath:@"_placeholderLabel.font"];
    [loginTextField setValue:[UIColor lightGrayColor]forKeyPath:@"_placeholderLabel.textColor"];
    
    [self.view addSubview:loginTextField];
}
- (void)printUITextFieldList {
    unsigned int count;
    
    Ivar *ivarList = class_copyIvarList([UITabBar class], &count);
    for (unsigned int i = 0; i < count; i++) {
        Ivar myIvar = ivarList[i];
        const char *ivarName = ivar_getName(myIvar);
        NSLog(@"ivar(%d) : %@", i, [NSString stringWithUTF8String:ivarName]);
    }
    
    free(ivarList);
    
    objc_property_t *propertyList = class_copyPropertyList([UITextField class], &count);
    for (unsigned int i = 0; i < count; i++) {
        const char *propertyName = property_getName(propertyList[i]);
        NSLog(@"propertyName(%d) : %@", i, [NSString stringWithUTF8String:propertyName]);
    }
    
    free(propertyList);
}


@end
