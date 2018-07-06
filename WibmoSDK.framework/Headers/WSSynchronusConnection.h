//
//  WSSynchronusConnection.h
//  TestPayZappStaging
//
//  Created by Anil Kumar Reddy on 13/05/16.
//  Copyright © 2016 WIBMO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WSSynchronusConnection : NSObject

- (NSData *)sendSynchronousRequest:(NSURLRequest *)iRequest returningResponse:(NSURLResponse **)iResponse error:(NSError **)iError;

@end
