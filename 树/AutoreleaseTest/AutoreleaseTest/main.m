//
//  main.m
//  AutoreleaseTest
//
//  Created by 王天亮 on 2020/9/22.
//

#import <Foundation/Foundation.h>
extern _objc_autoreleasePoolPrint(void);

int main(int argc, const char * argv[]) {
//    @autoreleasepool {
        for (int i = 0; i < 2; i++) {
            @autoreleasepool {
                
            NSString *string = [NSString stringWithFormat:@"你好"];
        
            }
            _objc_autoreleasePoolPrint();
        }
//        _objc_autoreleasePoolPrint();
//    }
}
