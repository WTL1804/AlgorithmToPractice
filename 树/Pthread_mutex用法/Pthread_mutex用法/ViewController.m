//
//  ViewController.m
//  Pthread_mutex用法
//
//  Created by 王天亮 on 2020/11/30.
//

#import "ViewController.h"
#include <pthread.h>
#import <libkern/OSAtomic.h>
#import <os/lock.h>
@interface ViewController ()
@property (nonatomic, assign) int a;
@end

@implementation ViewController
//pthread_mutex_t lock;
pthread_mutexattr_t attr;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
OSSpinLock mySpinLock = OS_SPINLOCK_INIT;
os_unfair_lock myUnFairLock = OS_UNFAIR_LOCK_INIT;
void inits() {
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);
    pthread_mutex_init(&lock, &attr);
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor greenColor];
    _a = 5;
    
    inits();
//    [self pthreadTest];
//    [self spinLockTest];
//    [self osUnfairLockTest];
    [self barrier];
}
//同步栅栏和异步栅栏
- (void)barrier {
    dispatch_queue_t que = dispatch_queue_create("1231dada3", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(que, ^{
        os_unfair_lock_lock(&myUnFairLock);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        os_unfair_lock_unlock(&myUnFairLock);
    });
    dispatch_async(que, ^{

        os_unfair_lock_lock(&myUnFairLock);
//        sleep(20);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        os_unfair_lock_unlock(&myUnFairLock);
    });
    dispatch_async(que, ^{

        os_unfair_lock_lock(&myUnFairLock);
//        sleep(20);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        os_unfair_lock_unlock(&myUnFairLock);
    });
    dispatch_barrier_sync(que, ^{
        NSLog(@"%d", self.a);
    });
    NSLog(@"123");
}


//os_unfair_lock
- (void)osUnfairLockTest {
    dispatch_queue_t que = dispatch_queue_create("1231dada3", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(que, ^{
        os_unfair_lock_lock(&myUnFairLock);
        sleep(2000);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        os_unfair_lock_unlock(&myUnFairLock);
    });
    dispatch_async(que, ^{

        os_unfair_lock_lock(&myUnFairLock);
//        sleep(20);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        os_unfair_lock_unlock(&myUnFairLock);
    });
    dispatch_async(que, ^{

        os_unfair_lock_lock(&myUnFairLock);
//        sleep(20);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        os_unfair_lock_unlock(&myUnFairLock);
    });
    dispatch_barrier_async(que, ^{
        NSLog(@"%d", self.a);
    });
}
//pthread_mutex测试
- (void)spinLockTest {
    dispatch_queue_t que = dispatch_queue_create("12313", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(que, ^{
        OSSpinLockLock(&mySpinLock);
        sleep(20);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        OSSpinLockUnlock(&mySpinLock);
    });
    dispatch_async(que, ^{

        OSSpinLockLock(&mySpinLock);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        OSSpinLockUnlock(&mySpinLock);
    });
    dispatch_async(que, ^{

        OSSpinLockLock(&mySpinLock);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        OSSpinLockUnlock(&mySpinLock);
    });
    dispatch_barrier_async(que, ^{
        NSLog(@"%d", self.a);
    });
}
- (void)pthreadTest {
    dispatch_queue_t que = dispatch_queue_create("2", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(que, ^{
        pthread_mutex_lock(&lock);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        pthread_mutex_unlock(&lock);
    });
    dispatch_async(que, ^{
        pthread_mutex_lock(&lock);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
        pthread_mutex_unlock(&lock);
    });
    dispatch_async(que, ^{
        pthread_mutex_lock(&lock);
        NSLog(@"%@", [NSThread currentThread]);
        for (int i = 0; i < 5; i++) {
            self.a = self.a + 1;
            printf("%d\n", self.a);
        }
//        NSLog(@"3");
        pthread_mutex_unlock(&lock);
    });
    dispatch_barrier_async(que, ^{
        NSLog(@"%d", self.a);
    });
//    NSLog(@"%d", _a);
}

@end
