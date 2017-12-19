//
//  WMTransactionInfo.h
//  WibmoSDK
//
//  Created by Wibmo on 19/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface WSTransactionInfo : NSObject

@property (nonatomic, retain) NSString *messageHash;
@property (nonatomic, retain) NSString *merchantAppData;
@property (nonatomic, retain) NSString *merchantData;
@property (nonatomic, retain) NSString *transactionAmount;
@property (nonatomic, retain) NSString *transactionCurrency;
@property (nonatomic, retain) NSArray *supportedPaymentType;
@property (nonatomic, retain) NSString *merchantTransactionId;
@property (nonatomic, retain) NSString *transactionDescription;
@property (nonatomic, retain) NSString *transactionFormattedAmount;
@property (nonatomic, retain) NSArray *restrictedPaymentType;
@property (nonatomic, retain) NSString *txnAmtKnownvalue;
@property (nonatomic, retain) NSString *chargeLatervalue;
@property (nonatomic, retain) NSString *transactionDate;
- (NSDictionary *)transactionInformation;

@end
