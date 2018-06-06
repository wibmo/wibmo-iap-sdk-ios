//
//  WSCardInfo.h
//  TestPayZappStaging
//
//  Created by Anil Kumar Reddy on 26/10/17.
//  Copyright © 2017 WIBMO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSCardInfo : NSObject

@property (nonatomic, retain) NSString *cardTokenRefNo;
@property (nonatomic, retain) NSString *cardRefTokenReq;

- (NSDictionary *)cardInformation;

@end
