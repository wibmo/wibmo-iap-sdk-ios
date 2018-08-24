//
//  WSHeader.h
//  WibmoSDK
//
//  Created by Wibmo on 20/08/15.
//  Copyright (c) 2015 Wibmo. All rights reserved.
//


#pragma mark - Macros

#define ENCODE_STRING(kString)      (NSString *)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(NULL, (CFStringRef)kString, NULL, (CFStringRef)@"_.-!*'\"();:@&=+$,/?%#[]% ",kCFStringEncodingUTF8))


#pragma mark - URLs

#define RESTAPI_BASE_URL_STAGING        @"https://api.pc.enstage-sas.com"     //Rest Staging
#define RESTAPI_BASE_URL_PRODUCTION     @"https://api.wibmo.com"              //Rest Production
//#define RESTAPI_BASE_URL                @"https://api.pcdev.enstage-sas.com"     //Rest Dev

//#define SSL_PUBLIC_KEY                  @"*.enstage-uat.com"                    // Staging
//#define SSL_PUBLIC_KEY                  @"*.wibmo.com"                          // Production

#define INIT_WPAY_PAYMENT               @"/v1/wPay/init"
#define INIT_W2FA_PAYMENT               @"/v1/w2fa/init"

#define ABORT_INAPP_PAYMENT             @"/v1/wPay/update"
#define ABORT_INAPP_W2FA_PAYMENT        @"/v1/w2fa/update"

#define INIT_WPAY_PAYMENT_RESTAPI       @"/v2/in/txn/iap/wpay/init"
#define INIT_W2FA_PAYMENT_RESTAPI       @"/v2/in/txn/iap/w2fa/init"

#define ABORT_INAPP_PAYMENT_RESTAPI     @"/v2/in/txn/iap/wpay/update/%@"
#define ABORT_INAPP_W2FA_RESTAPI        @"/v2/in/txn/iap/w2fa/update/%@"

#define INAPP_WPAY_STATUS_CHECK         @"/v2/in/txn/iap/wPay/status/sdk/%@"
#define INAPP_W2FA_STATUS_CHECK         @"/v2/in/txn/iap/w2fa/status/sdk/%@"

#define INAPP_GET_MASKED_CARD           @"/v2/in/txn/iap/wpay/6019/getMaskedCard"
#define INAPP_W2FA_GET_MASKED_CARD      @"/v2/in/txn/iap/w2fa/6019/getMaskedCard"

#define WIBMOSDKVERSION                 @"2.0.1"
#define MIXPANEL_TOKEN                  @"bfa033280c3775d19502eac4a9041ca3"

#define  MODEL      [[UIDevice currentDevice] model];
#define  OSVERSION  [[UIDevice currentDevice] systemVersion];
#define  DEVICEID   [[[UIDevice currentDevice] identifierForVendor] UUIDString];
#define  OSType     [[UIDevice currentDevice] systemName];
