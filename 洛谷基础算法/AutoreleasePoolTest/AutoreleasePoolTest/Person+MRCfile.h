//
//  Person+MRCfile.h
//  AutoreleasePoolTest
//
//  Created by 王天亮 on 2020/11/23.
//

#import "Person.h"

NS_ASSUME_NONNULL_BEGIN

@interface Person (MRCfile)
- (void)retainTest;
- (unsigned int)retainCountNumber;
- (void)releaseTest;
- (void)autoreleaseTest;
@end

NS_ASSUME_NONNULL_END
