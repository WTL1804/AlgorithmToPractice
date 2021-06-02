//
//  main.m
//  block捕获
//
//  Created by 王天亮 on 2021/6/1.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <malloc/malloc.h>
int a = 0;
static int b = 0;
int main(int argc, const char * argv[]) {
//    NSObject *obj = [[NSObject alloc] init];
//    NSLog(@"%ld", (long)CFGetRetainCount((__bridge CFTypeRef)obj));
//    NSObject *__weak obj2 = obj;
//    NSLog(@"objc对象实际需要的内存大小: %zd", class_getInstanceSize([obj class]));
//    NSLog(@"objc对象实际分配的内存大小: %zd", malloc_size((__bridge const void *)(obj)));
//    __weak void(^blk)(void) = ^{
//        NSLog(@"%@", obj2);
//        NSLog(@"%ld", CFGetRetainCount((__bridge CFTypeRef)obj2));
    {
        NSObject *obj = [[NSObject alloc] init];
        obj = [[NSObject alloc] init];
    }
//    };
//    blk();
    return 0;
}
