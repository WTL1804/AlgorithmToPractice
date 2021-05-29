//
//  Person.h
//  AutoreleasePoolTest
//
//  Created by 王天亮 on 2020/11/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface Person : NSObject
@property (nonatomic, strong) NSString *string;
+ (id)somePerson;
+ (instancetype)sharedLeton;
@end
NS_ASSUME_NONNULL_END
