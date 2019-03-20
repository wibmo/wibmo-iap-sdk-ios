//
//  ViewController.m
//  IAPDemoObjc
//
//  Created by Akthar Khan on 19/03/19.
//  Copyright © 2019 Wibmo Inc. All rights reserved.
//

#import "ViewControllerObjc.h"
@import WibmoSDK;

#define kTxnCurrencyCode @"356"
#define ENCODE_STRING(kString)   (NSString *)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(NULL, (CFStringRef)kString, NULL, (CFStringRef)@"_.-!*'\"();:@&=+$,/?%#[]% ",kCFStringEncodingUTF8))

#define GET_MSG_HASH    @"sampleMerchant/iap/generateInitReqMessageHash.jsp?txnAmount=%@&merAppData=%@&merDyn=false&txnAmountKnown=%@&chargeLater=%@&txnType=%@&version=2"



@interface ViewControllerObjc ()<WSPaymentDatasource, WSPaymentDelegate, UITextFieldDelegate>
{
    NSDictionary *messageHash;
    NSString *merchantAppData;
}
@property (weak, nonatomic) IBOutlet UITextField *mobileNumber;
@property (weak, nonatomic) IBOutlet UITextField *amount;
@property (weak, nonatomic) IBOutlet UISwitch *amountKnown;
@property (weak, nonatomic) IBOutlet UISwitch *chargeLater;
@property (weak, nonatomic) IBOutlet UISwitch *billingAddrRequired;
@property (weak, nonatomic) IBOutlet UISwitch *shippingAddrRequired;
@property (weak, nonatomic) IBOutlet UISwitch *emailIdRequired;
@property (weak, nonatomic) IBOutlet UISegmentedControl *paymentType;
@property (weak, nonatomic) IBOutlet UILabel *transactionStatusLabel;

@property (nonatomic, strong) WibmoSDK *paymentSdk;

@end

@implementation ViewControllerObjc

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    merchantAppData = @"Sample Merchant aap data";
}
- (IBAction)endEditing:(id)sender {
    [self.view endEditing:YES];
}

- (IBAction)payWithPayZapp:(UIButton *)sender {
    NSString *validationError = nil;
    if (self.mobileNumber.text.length != 10) {
        validationError = @"Please enter valid Mobile number and try again.";
        self.mobileNumber.text = nil;
    } else if (self.amount.text.length == 0) {
        validationError = @"Please enter transaction amount.";
        self.amount.text = nil;
    }
    
    if (validationError == nil) {
        [self generateMessageHash];
    } else {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Error" message:validationError preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
        [alert addAction:okAction];
        [self presentViewController:alert animated:YES completion:nil];
    }
}

- (IBAction)chargeNow:(UIButton *)sender {
    
}

- (IBAction)checkStatus:(UIButton *)sender {
    
}

- (void)generateMessageHash {
    NSString *amountKnown = self.amountKnown.on ? @"true" : @"false";
    NSString *chargeLater = self.chargeLater.on ? @"true" : @"false";
    NSString *txnType = self.paymentType.selectedSegmentIndex == 0 ? @"WPay" : @"W2fa";
    NSString *msgHashQuery = [NSString stringWithFormat:GET_MSG_HASH,self.amount.text,ENCODE_STRING(merchantAppData),amountKnown,chargeLater,txnType,2];
    
    NSString *msgHashApi = [NSString stringWithFormat:@"%@%@",[self baseUrl],msgHashQuery];
    NSLog(@"HashAPI: %@", msgHashApi);
    
    NSURL *msgHashUrl = [NSURL URLWithString:msgHashApi];
    NSURLRequest *msgHashRequest=[NSURLRequest requestWithURL:msgHashUrl cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:30.0];
    
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *task = [session dataTaskWithRequest:msgHashRequest
                                            completionHandler:
                                  ^(NSData *data, NSURLResponse *response, NSError *error) {
                                      if (error != nil) {
                                          // Handle error...
                                      }
                                      NSHTTPURLResponse *finalResponse = (NSHTTPURLResponse *)response;
                                      if (finalResponse.statusCode == 200 && data != nil) {
                                          NSError *parseError = nil;
                                          NSDictionary *jsonResult = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:&parseError];
                                          NSLog(@"%@", jsonResult.description);
                                          self->messageHash = jsonResult;
                                          if (parseError != nil) {
                                              // Handle error
                                              self->messageHash = nil;
                                              dispatch_async(dispatch_get_main_queue(), ^{
                                                  UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Error" message:@"Message hash generation failed" preferredStyle:UIAlertControllerStyleAlert];
                                                  UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
                                                  [alert addAction:okAction];
                                                  [self presentViewController:alert animated:YES completion:nil];
                                              });
                                          } else {
                                              dispatch_async(dispatch_get_main_queue(), ^{
                                                [self initialiseIapPayment];
                                              });
                                          }
                                      }
                                  }];
    [task resume];
}

- (NSString *)baseUrl {
    if ([self buildType] == WSBuildTypeStaging) {
        return @"https://wallet.pc.enstage-sas.com/";
    } else {
        return @"https://www.wibmo.com/";
    }
}

- (void)initialiseIapPayment {
    
//    PRODUCTION
//    merchantInfo.merchantID = @"5344117557917234438";
//    merchantInfo.merchantAppID = @"7016";
    
//    STAGING
//    merchantInfo.merchantID = @"81516121";
//    merchantInfo.merchantAppID = @"1";

    WSTransactionInfo *transactionInfo = [[WSTransactionInfo alloc] initWithMsgHash:messageHash[@"msgHash"] txnCurrency:kTxnCurrencyCode chargeLater:YES merAppData:merchantAppData merTxnId:messageHash[@"merTxnId"] restrictedPaymentType:@[WSPaymentOption.kPaymentOptionNone] txnAmtKnown:NO merDataField:@"Merchant Data" supportedPaymentType:@[WSPaymentOption.kPaymentOptionAllCards] txnDate:messageHash[@"txnDate"] txnDesc:@"Transaction from sample merchant for rupee 1" txnAmount:self.amount.text];
    self.paymentSdk = [[WibmoSDK alloc] initWithTransactionDetails:transactionInfo datasource:self delegate:self];
    [self.paymentSdk performIAPTransactionFrom:self];
}


#pragma -mark Payment DataSource
- (enum WSBuildType)buildType {
    return WSBuildTypeStaging;
}

- (enum WSIAPVersion)iapVersion {
    return WSIAPVersionV2;
}

- (WSMerchantInfo * _Nonnull)merchantInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction {
    WSMerchantInfo *merchantInfo = [[WSMerchantInfo alloc] initWithMerName:@"SampleMerchant" merCountryCode:@"IN" merId:@"81516121" merAppId:@"1" merUrlScheme:nil];
    return merchantInfo;
}

- (WSCustomerInfo * _Nonnull)customerInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction {
    WSCustomerInfo *customerInfo = [[WSCustomerInfo alloc] initWithCustName:@"Guest User" custDob:@"01/01/2000" custEmail:@"guest_user@xyz.com" custMobile:@"9000590005"];
    return customerInfo;
}

- (BOOL)isWpayTransaction {
    return self.paymentType.selectedSegmentIndex == 0;
}

- (WSCardInfo * _Nullable)cardInfoForTransaction:(WSTransactionInfo * _Nonnull)transaction  {
    return nil;
}

- (BOOL)requiresBillingAddressForTransaction:(WSTransactionInfo * _Nonnull)transaction {
    return NO;
}

- (BOOL)requiresShippingAddressForTransaction:(WSTransactionInfo * _Nonnull)transaction  {
    return NO;
}

- (BOOL)requiresEmailIdForTransaction:(WSTransactionInfo * _Nonnull)transaction {
    return NO;
}

#pragma -mark Payment Delegate
- (void)paymentFailedWithError:(NSError * _Nonnull)error {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Error" message:error.localizedDescription preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
    [alert addAction:okAction];
    [self presentViewController:alert animated:YES completion:nil];
}


- (void)paymentSuccessfullForTransaction:(NSDictionary<NSString *,id> * _Nonnull)transaction {
    NSString *message = [NSString stringWithFormat:@"Transaction completed succesfully, Wibmo Transaction Id for reference is : %@",transaction[@"wibmoTxnId"]];
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Success" message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
    [alert addAction:okAction];
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma -mark UITextFieldDelegate
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    return YES;
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
    [textField resignFirstResponder];
}

@end
