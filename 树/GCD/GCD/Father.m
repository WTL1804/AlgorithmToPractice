//
//  Father.m
//  GCD
//
//  Created by 王天亮 on 2020/9/23.
//

#import "Father.h"

@implementation Father
- (void)run {
    dispatch_group_t group =  dispatch_group_create();
       
       dispatch_group_async(group, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
           // 追加任务 1
           [NSThread sleepForTimeInterval:2];              // 模拟耗时操作
           NSLog(@"1---%@",[NSThread currentThread]);      // 打印当前线程
       });
       
       dispatch_group_async(group, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
           // 追加任务 2
           [NSThread sleepForTimeInterval:2];              // 模拟耗时操作
           NSLog(@"2---%@",[NSThread currentThread]);      // 打印当前线程
       });
       
       dispatch_group_notify(group, dispatch_get_main_queue(), ^{
           // 等前面的异步任务 1、任务 2 都执行完毕后，回到主线程执行下边任务
           [NSThread sleepForTimeInterval:2];              // 模拟耗时操作
           NSLog(@"3---%@",[NSThread currentThread]);      // 打印当前线程

           NSLog(@"group---end");
       });
    NSLog(@"fsdfj");

}
@end
