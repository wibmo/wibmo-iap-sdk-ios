//
//  WSMerchantHandler.h
//  WibmoSDK
//
//  Created by Wibmo on 20/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "WSPayInitRequest.h"
#import "WSUrlInfo.h"


@protocol WSMerchantHandlerDelegate;


@interface WSMerchantHandler : NSObject

@property (nonatomic, retain) id<WSMerchantHandlerDelegate> delegate;

@property (nonatomic, retain) WSUrlInfo *urlInfo;

- (void)generateMessageHash:(WSPayInitRequest *)iRequest;

@end


@protocol WSMerchantHandlerDelegate <NSObject>

- (void)didUpdateRequest:(WSPayInitRequest *)iRequest;

@end
