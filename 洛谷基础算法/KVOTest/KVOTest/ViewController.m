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
    self.person = [[Person alloc] init];
    [self.person addObserver:self forKeyPath:@"array" options:NSKeyValueObservingOptionNew context:nil];
    self.person.array = [[NSMutableArray alloc] init];
    NSMutableArray *array = [self.person mutableArrayValueForKey:@"array"];
    [array addObject:@"1"];
    
 }
- (void)test {
    NSLog(@"123");
}
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    NSLog(@"do");
}
- (void)dealloc {
    
}

@end
