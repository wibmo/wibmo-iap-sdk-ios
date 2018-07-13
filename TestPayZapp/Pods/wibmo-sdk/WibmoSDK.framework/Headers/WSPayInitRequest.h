//
//  WSPayInitRequest.h
//  WibmoSDK
//
//  Created by Wibmo on 20/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "WSTransactionInfo.h"
#import "WS2FAInitRequest.h"
#import "WSCustomerInfo.h"
#import "WSMerchantInfo.h"
#import "WSCardInfo.h"


@interface WSPayInitRequest : NSObject

@property (nonatomic, assign) BOOL performAuthorization;
@property (nonatomic, retain) WSTransactionInfo *transactionInfo;
@property (nonatomic, retain) WSCustomerInfo *customerInfo;
@property (nonatomic, retain) WSMerchantInfo *merchantInfo;
@property (nonatomic, retain) WSCardInfo *cardInfo;
@property (nonatomic, retain) NSDictionary *deviceInfo;
@property (nonatomic, retain) NSDictionary *eventInfo;

@end
