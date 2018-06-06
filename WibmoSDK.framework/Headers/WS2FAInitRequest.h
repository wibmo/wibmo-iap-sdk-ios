//
//  WS2FAInitRequest.h
//  WibmoSDK
//
//  Created by Wibmo on 29/09/15.
//  Copyright © 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "WSTransactionInfo.h"
#import "WSCustomerInfo.h"
#import "WSMerchantInfo.h"
#import "WSCardInfo.h"


@interface WS2FAInitRequest : NSObject
@property (nonatomic, assign) BOOL performAuthorization;
@property (nonatomic, retain) WSTransactionInfo *transactionInfo;
@property (nonatomic, retain) WSCustomerInfo *customerInfo;
@property (nonatomic, retain) WSMerchantInfo *merchantInfo;
@property (nonatomic, retain) WSCardInfo *cardInfo;
@property (nonatomic, retain) NSDictionary *deviceInfo;
@property (nonatomic, retain) NSDictionary *eventInfo;

@end
