//
//  ViewController.m
//  PhotoRelease
//
//  Created by 王天亮 on 2020/12/10.
//

#import "ViewController.h"
#import "NextViewController.h"
#import "MyScrollView.h"
@interface ViewController ()
@property (nonatomic, strong) UIImage *image;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
//    for (int i = 0; i < 2; i++) {
//        UIImageView *imageView = [[UIImageView alloc] init];
////        UIImage *image = [UIImage imageNamed:@"sobig.jpg"];
        _image = [UIImage imageWithContentsOfFile:@"/Users/wangtianliang/Desktop/AlgorithmToPractice/树/PhotoRelease/PhotoRelease/sobig.jpg"];
//      // _image = [self resizeScaleImage:0.1];
//        imageView.frame = CGRectMake(0, 0, self.view.frame.size.width/(i+1), self.view.frame.size.height/(i+1));
//        imageView.image = _image;
//        [self.view addSubview:imageView];
//        _image = nil;
//        imageView = nil;
//    }
    MyScrollView *scroller = [[MyScrollView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height) image:_image];
    [self.view addSubview:scroller];
    
}
- (UIImage *)resizeScaleImage:(CGFloat)scale {
    
    CGSize imgSize = self.image.size;
    CGSize targetSize = CGSizeMake(imgSize.width * scale, imgSize.height * scale);
    NSData *imageData = UIImageJPEGRepresentation(self.image, 1.0);
    CFDataRef data = (__bridge CFDataRef)imageData;
    
    CFStringRef optionKeys[1];
    CFTypeRef optionValues[4];
    optionKeys[0] = kCGImageSourceShouldCache;
    optionValues[0] = (CFTypeRef)kCFBooleanFalse;
    CFDictionaryRef sourceOption = CFDictionaryCreate(kCFAllocatorDefault, (const void **)optionKeys, (const void **)optionValues, 1, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData(data, sourceOption);
    CFRelease(sourceOption);
    if (!imageSource) {
        NSLog(@"imageSource is Null!");
        return nil;
    }
    //获取原图片属性
    int imageSize = (int)MAX(targetSize.height, targetSize.width);
    CFStringRef keys[5];
    CFTypeRef values[5];
    //创建缩略图等比缩放大小，会根据长宽值比较大的作为imageSize进行缩放
    keys[0] = kCGImageSourceThumbnailMaxPixelSize;
    CFNumberRef thumbnailSize = CFNumberCreate(NULL, kCFNumberIntType, &imageSize);
    values[0] = (CFTypeRef)thumbnailSize;
    keys[1] = kCGImageSourceCreateThumbnailFromImageAlways;
    values[1] = (CFTypeRef)kCFBooleanTrue;
    keys[2] = kCGImageSourceCreateThumbnailWithTransform;
    values[2] = (CFTypeRef)kCFBooleanTrue;
    keys[3] = kCGImageSourceCreateThumbnailFromImageIfAbsent;
    values[3] = (CFTypeRef)kCFBooleanTrue;
    keys[4] = kCGImageSourceShouldCacheImmediately;
    values[4] = (CFTypeRef)kCFBooleanTrue;
    
    CFDictionaryRef options = CFDictionaryCreate(kCFAllocatorDefault, (const void **)keys, (const void **)values, 4, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CGImageRef thumbnailImage = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, options);
    UIImage *resultImg = [UIImage imageWithCGImage:thumbnailImage];
    
    CFRelease(thumbnailSize);
    CFRelease(options);
    CFRelease(imageSource);
    CFRelease(thumbnailImage);
    
    return resultImg;
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    NextViewController *next =  [[NextViewController alloc]init];
    next.modalPresentationStyle = 0;
    [self presentViewController:next animated:YES completion:nil];
}
@end
