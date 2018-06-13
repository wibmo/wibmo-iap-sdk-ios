#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "WibmoSDK.h"
#import "WSCardInfo.h"
#import "WSCustomerInfo.h"
#import "WSMerchantInfo.h"
#import "WSTransactionInfo.h"
#import "WSUrlInfo.h"
#import "WSConstant.h"

FOUNDATION_EXPORT double WibmoSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char WibmoSDKVersionString[];

