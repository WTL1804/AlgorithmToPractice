//
//  main.m
//  block捕获
//
//  Created by 王天亮 on 2021/6/1.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <malloc/malloc.h>
#import "Person.h"

int main(int argc, const char * argv[]) {
    __weak void(^blk)(void);
        NSObject *obj = [[NSObject alloc] init];
        blk = ^{
//            NSLog(@"%@", obj.description);
        };
//        NSLog(@"%ld", CFGetRetainCount((__bridge CFTypeRef)obj));
    return 0;
}
