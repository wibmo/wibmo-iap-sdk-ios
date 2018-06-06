//
//  WMMerchantInfo.h
//  WibmoSDK
//
//  Created by Wibmo on 19/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface WSMerchantInfo : NSObject

@property (nonatomic, retain) NSString *merchantID;
@property (nonatomic, retain) NSString *merchantName;
@property (nonatomic, retain) NSString *merchantAppID;
@property (nonatomic, retain) NSString *merchantCountryCode;
@property (nonatomic, retain) NSString *merchantUrlSchema;

- (NSDictionary *)merchantInformation;

@end
