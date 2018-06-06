//
//  WSLoadingView.h
//  WibmoSDK
//
//  Created by Wibmo on 20/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <UIKit/UIKit.h>


@interface WSLoadingView : UIView

@property (nonatomic, assign) UIActivityIndicatorViewStyle style;
@property (nonatomic, retain) UIColor *textColor;

- (id)initWithFrame:(CGRect)iFrame message:(NSString *)iMessage;
- (void)startLoading;

@end
