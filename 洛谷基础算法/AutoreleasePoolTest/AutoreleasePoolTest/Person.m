//
//  Person.m
//  AutoreleasePoolTest
//
//  Created by 王天亮 on 2020/11/23.
//

#import "Person.h"
#import "Person+MRCfile.h"

@implementation Person
static Person * manageCustom;
+ (id)somePerson {
    Person *person = [[Person alloc] init];
    return person;
}
+ (instancetype)sharedLeton {
    static dispatch_once_t onceToken;
    if (!manageCustom) {
        dispatch_once(&onceToken, ^{
            manageCustom = [[super allocWithZone:NULL] init] ;
        });
    }
    return manageCustom;
}
+(id) allocWithZone:(struct _NSZone *)zone
{
    return [Person sharedLeton] ;
}
static Person *dd = NULL;
+ (id)creat {
    static dispatch_once_t onceToken;
    if (dd == NULL) {
        dispatch_once(&onceToken, ^{
            dd = [[super alloc] init];
        });
    }
    return dd;
}
@end
