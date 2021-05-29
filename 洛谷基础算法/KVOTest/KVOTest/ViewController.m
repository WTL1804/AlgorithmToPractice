//
//  ViewController.m
//  KVOTest
//
//  Created by 王天亮 on 2020/10/25.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    _person = [[Person alloc] init];
    //_person.string = [[NSString alloc] init];
//    [_person addObserver:self forKeyPath:@"string" options:NSKeyValueObservingOptionNew context:nil];
    //_person.string = [[NSString alloc] init];
  
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(test) name:nil object:_person];
//    _person.string = @"123";
    NSMutableString *string = [NSMutableString stringWithFormat:@"name"];
    NSMutableString *copyString = [string copy];
    NSLog(@"%p, %p", string, copyString);
    [copyString appendString:@"123"];
    
 }
- (void)test {
    NSLog(@"123");
}
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    NSLog(@"do");
}
- (void)dealloc {
    [self.person removeObserver:self.person forKeyPath:@"person"];
}

@end
