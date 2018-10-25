//
//  WibmoSDK.h
//  WibmoSDK
//
//  Created by Wibmo on 19/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "WSTransactionInfo.h"
#import "WSCustomerInfo.h"
#import "WSMerchantInfo.h"
#import "WSCardInfo.h"
#import "WSConstant.h"

#define PROCESS_INAPP_PAYMENT   @"PROCESS_INAPP_PAYMENT"
#define CALL_INAPP_PAYMENT      @"CALL_INAPP_PAYMENT"
#define CALLBACK_TO_MERCHANT     @"CALLBACK_TO_MERCHANT"
#define WSDesignatedInitializer(__SEL__) __attribute__((unavailable("Invoke the designated initializer `" # __SEL__ "` instead.")))
@protocol WibmoSDKDelegate;

@interface WibmoSDK : UIViewController

@property (nonatomic, retain) NSDictionary *deviceinfoDictionary;
@property (nonatomic, retain) NSDictionary *urlInfoDictionary;
@property (nonatomic, retain) id<WibmoSDKDelegate> delegate;

- (instancetype)init __attribute((unavailable("Please use designated initializer initWithTransactionInfo: merchanInfo: customerInfo: withDelegate:")));
- (instancetype)initWithTransactionInfo:(WSTransactionInfo *)transactionInfo merchanInfo:(WSMerchantInfo *)merchantInfo customerInfo:(WSCustomerInfo *)customerInfo withDelegate:(id<WibmoSDKDelegate>)delegate isProductionBuild:(BOOL)productionBuild;
- (void)initializePayment;
- (void)initializeW2FAPayment;

@end

@protocol WibmoSDKDelegate <NSObject>

- (void)paymentSuccessfulWithTransaction:(NSDictionary *)iTransaction;
- (void)paymentFailedWithError:(NSError *)iError;
- (void)paymentCancelled;
- (void)paymentTimedOut;

@end
