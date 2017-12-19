//
//  WSUrlInfo.h
//  TestPayZappStaging
//
//  Created by WIBMO on 29/02/16.
//  Copyright © 2016 WIBMO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSUrlInfo : NSObject

@property (nonatomic, retain) NSString *baseUrl;

- (NSDictionary *)urlsInformation;

@end
