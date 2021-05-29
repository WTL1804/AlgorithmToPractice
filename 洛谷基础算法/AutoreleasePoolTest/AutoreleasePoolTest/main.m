//
//  main.m
//  AutoreleasePoolTest
//
//  Created by 王天亮 on 2020/11/23.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Person+MRCfile.h"
#import <objc/runtime.h>
#import <malloc/malloc.h>
@interface Student : NSObject {
    int _age;
}

@end

@implementation Student
@end

@interface People : Student {
    int _number;
}

@end

@implementation People
@end
extern int _objc_autoreleasePoolPrint(void);
int main(int argc, const char * argv[]) {
    People *people = [[People alloc] init];
    NSLog(@"123");
    return 0;
    
}
