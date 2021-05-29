//
//  MyThread.m
//  线程保活
//
//  Created by 王天亮 on 2020/12/17.
//

#import "MyThread.h"

@implementation MyThread
- (void)dealloc {
    NSLog(@"%s", __func__);
}
@end
