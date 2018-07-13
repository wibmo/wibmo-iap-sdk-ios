//
//  WSURLHandler.h
//  WibmoSDK
//
//  Created by Wibmo on 20/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#import <Foundation/Foundation.h>


@protocol WSURLDelegate;


@interface WSURLHandler : NSObject

// Properties
@property (nonatomic, assign) NSInteger tag;
@property (nonatomic, retain) id<WSURLDelegate> delegate;

// Intitalization
- (id)initWithURLString:(NSString *)iURLString;

// Public Methods
- (void)sendRequest;
- (void)sendRequestWithPost:(NSDictionary *)iPost;
- (void)sendRequestWithPostBody:(NSString *)iPostBody;
- (NSData *)getResponseForPost:(NSDictionary *)iPost;
- (NSData *)getJsonResponseForIapPostBody:(NSDictionary *)iPostBody :(NSString *)iapToken;
- (NSData *)getResponseWithJSONBody:(NSDictionary *)iPostBody;
@end



@protocol WSURLDelegate <NSObject>
- (void)urlHandler:(WSURLHandler *)iHandler didFinishLoadingWithResponse:(id)iResponse;
- (void)urlHandler:(WSURLHandler *)iHandler didFailToLoadWithError:(NSError *)iError;
@optional
- (void)urlHandler:(WSURLHandler *)iHandler didReceiveResponse:(NSURLResponse *)response;
@end
