//
//  NextViewController.m
//  PhotoRelease
//
//  Created by 王天亮 on 2020/12/10.
//

#import "NextViewController.h"

@interface NextViewController ()
@property (nonatomic, strong) UIImage *image;
@end

@implementation NextViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    for (int i = 0; i < 2; i++) {
        UIImageView *imageView = [[UIImageView alloc] init];
        _image = [UIImage imageNamed:@"sobig.jpg"];
//        _image = [UIImage imageWithContentsOfFile:@"/Users/wangtianliang/Desktop/AlgorithmToPractice/树/PhotoRelease/PhotoRelease/sobig.jpg"];
      // _image = [self resizeScaleImage:0.1];
        imageView.frame = CGRectMake(0, 0, self.view.frame.size.width/(i+1), self.view.frame.size.height / (i + 1));
        imageView.image = _image;
        [self.view addSubview:imageView];
    }
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self dismissViewControllerAnimated:YES completion:nil];
}
- (void)dealloc {
    NSLog(@"%s", __func__);
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
