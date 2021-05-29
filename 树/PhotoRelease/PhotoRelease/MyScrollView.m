//
//  MyScrollView.m
//  PhotoRelease
//
//  Created by 王天亮 on 2020/12/17.
//

#import "MyScrollView.h"
#import "TiledImageViewNoSlipView.h"
@interface MyScrollView () <UIScrollViewDelegate>
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) CGFloat imageScale;
@property (nonatomic, strong) TiledImageViewNoSlipView * frontTiledView;
@end
@implementation MyScrollView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
- (id)initWithFrame:(CGRect)frame image:(UIImage *)img {
    if((self = [super initWithFrame:frame])) {
            // Set up the UIScrollView
            self.showsVerticalScrollIndicator = NO;
            self.showsHorizontalScrollIndicator = NO;
            self.bouncesZoom = YES;
            self.decelerationRate = UIScrollViewDecelerationRateFast;
            self.delegate = self;
        self.backgroundColor = [UIColor colorWithRed:0.4f green:0.2f blue:0.2f alpha:1.0f];

            // 根据图片实际尺寸和屏幕尺寸计算图片视图的尺寸
            self.image = img;
            CGRect imageRect = CGRectMake(
                    0.0f,
                    0.0f,
                    CGImageGetWidth(_image.CGImage),
                    CGImageGetHeight(_image.CGImage));
            _imageScale = self.frame.size.width/imageRect.size.width;
        //_imageScale = 手机屏幕宽度/图片宽度 图片缩放倍数 比如缩放了 0.5,_imageScale = 0.5,那么图片宽度是手机宽度的俩倍。
        //image大小 * _imageScal得到屏幕大小。

            NSLog(@"imageScale: %f",_imageScale);
            imageRect.size = CGSizeMake(
                    imageRect.size.width * _imageScale,
                    imageRect.size.height * _imageScale);

            //根据图片的缩放计算scrollview的缩放级别
            //图片相对于视图放大了1/imageScale倍，所以用log2(1/imageScale)得出缩放次数，
    
        //根据_imageScale来算扩大或缩小了多少倍
        //假如_imageScale是0.25，图片是手机宽度的4倍
        //level是为了计算最大缩放倍数，此时我们设置最大放大到原图比例。
        //那level = ceil(log2(1 / _imageScale))是 2
        //然后最大倍数zoomInLevels = pow(2, level) =  4；
        
            // 然后通过pow得出缩放倍数，至于为什么要加1，
            //是希望图片在放大到原图比例时，还可以继续放大一次（即2倍），可以看的更清晰
             int level = ceil(log2(1 / _imageScale)) + 1;
            CGFloat zoomOutLevels = 1;
            CGFloat zoomInLevels = pow(2, level);

            self.maximumZoomScale = zoomInLevels;
            self.minimumZoomScale = zoomOutLevels;

            _frontTiledView = [[TiledImageViewNoSlipView alloc] initWithFrame:frame image:_image scale:_imageScale];
            [self addSubview:_frontTiledView];
        }
        return self;
}
- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView {
    return self.frontTiledView;
}
@end
