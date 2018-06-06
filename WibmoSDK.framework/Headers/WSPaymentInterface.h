//
//  WSJSInterface.h
//  WibmoSDK
//
//  Created by Wibmo on 23/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol WSPaymentDelegate;


@interface WSPaymentInterface : NSObject

@property (nonatomic, retain) id<WSPaymentDelegate> delegate;

- (void)notifyAbort;
- (void)notifyCompletion;
- (void)notifySuccess:(NSString *)iResCode :(NSString *)iResdesc :(NSString *)iPickupCode :(NSString *)iTransactionID :(NSString *)iMessageHash;
- (void)recordSuccess:(NSString *)iResCode :(NSString *)iResdesc :(NSString *)iPickupCode :(NSString *)iTransactionID :(NSString *)iMessageHash;
- (void)notifyFailure:(NSString *)iResCode :(NSString *)iFailure;

@end


@protocol WSPaymentDelegate <NSObject>

- (void)paymentDidAbort;
- (void)paymentDidComplete;
- (void)paymentDidFailWithCode:(NSString *)iCode andDescription:(NSString *)iDescription;
- (void)paymentSuccessfulWithCode:(NSString *)iCode description:(NSString *)iDescription pickupCode:(NSString *)iPickupCode transactionID:(NSString *)iTransactionID andMessageHash:(NSString *)iMessageHash;
- (void)paymentRecordedWithCode:(NSString *)iCode description:(NSString *)iDescription pickupCode:(NSString *)iPickupCode transactionID:(NSString *)iTransactionID andMessageHash:(NSString *)iMessageHash;

@end