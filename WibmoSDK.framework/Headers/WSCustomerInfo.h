//
//  WSCustomerInfo.h
//  WibmoSDK
//
//  Created by Wibmo on 19/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>


@interface WSCustomerInfo : NSObject

@property (nonatomic, retain) NSString *customerName;
@property (nonatomic, retain) NSString *customerEmail;
@property (nonatomic, retain) NSString *customerMobile;
@property (nonatomic, retain) NSString *customerDateOfBirth;

- (NSDictionary *)customerInformation;

@end
