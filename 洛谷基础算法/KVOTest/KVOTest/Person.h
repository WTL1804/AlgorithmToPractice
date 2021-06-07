//
//  Person.h
//  KVOTest
//
//  Created by 王天亮 on 2020/10/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject
@property (nonatomic, strong) NSString *string;
//- (void)didChangeValueForKey:(NSString *)key;
//- (void)willChangeValueForKey:(NSString *)key;
@property (nonatomic, strong) NSMutableArray *array;
@end

NS_ASSUME_NONNULL_END
