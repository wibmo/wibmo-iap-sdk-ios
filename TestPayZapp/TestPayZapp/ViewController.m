//
//  ViewController.m
//  TestPayZapp
//
//  Created by WIBMO on 20/08/15.
//  Copyright (c) 2015 WIBMO. All rights reserved.
//


#import "ViewController.h"
#import <WibmoSDK/WibmoSDK.h>
#import <WibmoSDK/WSConstant.h>
#import <WibmoSDK/WSUrlInfo.h>
//#import "NSObject+SBJson.h"

#define SCREEN_WIDTH            [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT           [UIScreen mainScreen].bounds.size.height


#define PAY_TAG     43211
#define CHECK_STATUS_TAG   43212

#define ENCODE_STRING(kString)      (NSString *)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(NULL, (CFStringRef)kString, NULL, (CFStringRef)@"_.-!*'\"();:@&=+$,/?%#[]% ",kCFStringEncodingUTF8))

//#define BASE_URL                        @"https://www.pcqa.enstage-sas.com/"    // QA
#define BASE_URL                       @"https://wallet.pc.enstage-sas.com/"   // Staging
//#define BASE_URL                      @"https://www.wibmo.com/"               // Production
//#define BASE_URL                       @"https://wallet.pcdev.enstage-sas.com/"   // Dev


#define GET_MSG_HASH                    @"sampleMerchant/iap/generateInitReqMessageHash.jsp?txnAmount=%@&merAppData=%@&merDyn=false&txnAmountKnown=%@&chargeLater=%@&txnType=WPay&version=%ld"
#define GET_MSG_HASH_W2FA               @"sampleMerchant/iap/generateInitReqMessageHash.jsp?txnAmount=%@&merAppData=%@&merDyn=false&txnAmountKnown=%@&chargeLater=%@&txnType=W2fa&version=%ld"

#define STATUS_CHECK_WPAY               @"sampleMerchant/iap/statusCheckv2.jsp?merTxnId=%@&txnAmount=%@&txnDate=%@&chargeUser=%@&txnType=WPay&wibmoTxnId=%@"
#define STATUS_CHECK_W2FA               @"sampleMerchant/iap/statusCheckv2.jsp?merTxnId=%@&txnAmount=%@&txnDate=%@&chargeUser=%@&txnType=W2fa&wibmoTxnId=%@"

//#define GET_MSG_HASH                    @"testMerchant/generatewPayMessageHash.jsp?txnAmount=%@&merAppData=%@&merDyn=false"

//#define GET_MSG_HASH_W2FA                @"testMerchant/generatew2faMessageHash.jsp?txnAmount=%@&merAppData=%@&merDyn=false"

@interface ViewController () <WibmoSDKDelegate, UIActionSheetDelegate, UITextFieldDelegate>

@property (nonatomic, retain) NSString *urlString;
@property (nonatomic, retain) NSMutableData *responseData;
@property (nonatomic, retain) NSURLConnection *urlConnection;

@property (nonatomic, retain) NSString *messageHash;
@property (nonatomic, retain) NSString *merchantTransactionID;
@property (nonatomic, retain) NSString *merchantTxndate;

@property (nonatomic, assign) BOOL isWPayEnabled;
@property (nonatomic, retain) NSString *aPaymentTypevisaCard;
@property (nonatomic, retain) NSString *aPaymentTypemastercardCard;
@property (nonatomic, retain) NSString *aPaymentTypeWibmoWallet;
@property (nonatomic, retain) NSString *aPaymentTypeNone;
@property (nonatomic, retain) NSDictionary *aPaymentDetails;
@property (nonatomic, retain) NSString *anAmountValue;
@property (nonatomic, retain) UIToolbar *toolbar;
@property (nonatomic, assign) UITextField *activeTextField;

@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.activeTextField = nil;
    NSString *aVersion = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"];
    
    NSString *aTitle = [NSString stringWithFormat:@"TestPayZapp %@", aVersion];
    
    CGFloat aTitleX = 80;
    CGFloat aTitleY = SCREEN_HEIGHT - 40;
    CGFloat aTitleHeight = 30;
    CGFloat aTitleWidth = (SCREEN_WIDTH - (2 * aTitleX));
    CGRect aTitleFrame = CGRectMake(aTitleX, aTitleY, aTitleWidth, aTitleHeight);
    
    UILabel *aTitleLabel = [[UILabel alloc] initWithFrame:aTitleFrame];
    [aTitleLabel setTextColor:[UIColor blueColor]];
    [aTitleLabel setBackgroundColor:[UIColor clearColor]];
    [aTitleLabel setTextAlignment:NSTextAlignmentCenter];
    [aTitleLabel setFont:[UIFont fontWithName:@"HelveticaNeue-Medium" size:18]];
    [self.view addSubview:aTitleLabel];
    [aTitleLabel setText:aTitle];
    
    
    self.aMobileNumber.text = @"1122334466";
    self.anAmount.text = @"100";
    self.anAmountValue = @"100";
    [self.anAmountKnown setTitle:@"true" forState:UIControlStateNormal];
    [self.aChargeLater setTitle:@"false" forState:UIControlStateNormal];
    self.aChargeLater.enabled = NO;
    [self.aStatusCheck setTitle:@"false" forState:UIControlStateNormal];
    
    self.toolbar = [[UIToolbar alloc] initWithFrame:CGRectMake(0, 0, SCREEN_WIDTH, 40)];
    [self.toolbar setBarTintColor:[UIColor whiteColor]];
    
    UIBarButtonItem *aDoneBar = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemDone target:self action:@selector(dismissInput)];
    UIBarButtonItem *aPaddingBar = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace
                                                                                 target:nil action:nil];
    UIBarButtonItem *aSpace = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace
                                                                            target:nil action:NULL];
    
    aPaddingBar.width = 10;
    
    [self.toolbar setItems:@[aPaddingBar, aSpace, aDoneBar, aPaddingBar]];
    [self.aMobileNumber setInputAccessoryView:self.toolbar];
    [self.anAmount setInputAccessoryView:self.toolbar];
    [self.anMessageHashAmount setInputAccessoryView:self.toolbar];
}

- (void)viewDidAppear:(BOOL)iAnimated {
    [super viewDidAppear:iAnimated];
    
}


#pragma mark - NSURLConnectionDelegate Methods

- (void)connection:(NSURLConnection *)iConnection didReceiveData:(NSData *)iData {
    [self.responseData appendData:iData];
}


- (void)connectionDidFinishLoading:(NSURLConnection *)iConnection {
    NSError *anError;
    NSDictionary* aJSONValue = [NSJSONSerialization JSONObjectWithData:self.responseData options:kNilOptions error:&anError];
    if (aJSONValue) {
        if (self.aCheckStatus.tag == 444) {
            NSString *aMessage = nil;//[aJSONValue JSONRepresentation];
            [[[UIAlertView alloc] initWithTitle:@"Response" message:aMessage delegate:nil
                              cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        } else {
            NSLog(@"aJSONValue: %@", aJSONValue);
            NSString *aMerTxnId = [aJSONValue valueForKey:@"merTxnId"];
            NSString *aMsgHash = [aJSONValue valueForKey:@"msgHash"];
            NSString *aMerTxnDate = [aJSONValue valueForKey:@"txnDate"];
            
            if (aMerTxnId && aMsgHash) {
                [self setMerchantTransactionID:aMerTxnId];
                [self setMerchantTxndate:aMerTxnDate];
                [self setMessageHash:aMsgHash];
                [self initializePayment];
            }
        }
    } else {
        NSString *aResponseString = [[NSString alloc] initWithData:self.responseData encoding:NSUTF8StringEncoding];
        NSLog(@"aResponseString: %@", aResponseString);
    }
}

- (void)connection:(NSURLConnection *)iConnection didFailWithError:(NSError *)iError {
    NSLog(@"Error: %@", iError);
}


#pragma mark - UIAlertViewDelegate

- (void)alertView:(UIAlertView *)iAlertView clickedButtonAtIndex:(NSInteger)iButtonIndex {
    
    if (iButtonIndex > 0) {
        if (iAlertView.tag == PAY_TAG) {
            if (iButtonIndex == 1) {
                self.isWPayEnabled = YES;
            } else {
                self.isWPayEnabled = NO;
            }
            [self generateMessageHash];
        } else if (iAlertView.tag == CHECK_STATUS_TAG) {
            if (iButtonIndex == 1) {
                [[iAlertView textFieldAtIndex:0] resignFirstResponder];
                NSString *aValue = [[iAlertView textFieldAtIndex:0] text];
                self.anAmountValue = aValue;
                [self callCheckStatus];
            }
        }
        
    }
}


#pragma mark - Private
- (IBAction)changeApiVersion:(UIButton *)sender {
    if (self.apiVersion.selectedSegmentIndex == 0) {
        [self.aChargeLater setTitle:@"false" forState:UIControlStateNormal];
        [self.aChargeLater setEnabled:NO];
    } else {
        [self.aChargeLater setTitle:@"false" forState:UIControlStateNormal];
        [self.aChargeLater setEnabled:YES];
    }
}

- (IBAction)payWithPayZapp:(id)iSender {
    //[self generateMessageHash];
    if (self.aMobileNumber.text.length > 0 && self.anAmount.text.length  > 0) {
        self.aCheckStatus.tag = 4444;
        UIAlertView *anAlert = [[UIAlertView alloc] initWithTitle:@"Pay using" message:nil delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"WPay", @"W2fa", nil];
        [anAlert setTag:PAY_TAG];
        [anAlert show];
    } else {
        [[[UIAlertView alloc] initWithTitle:@"Alert!" message:@"Please enter MobileNumber/Amount" delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
    }
}

- (IBAction)amountKnown:(UIButton *)iSender {
    self.anAmountKnown.tag = 111;
    self.aChargeLater.tag = 2222;
    self.aStatusCheck.tag = 3333;
    NSLog(@"%@",iSender.currentTitle);
    UIActionSheet *anActionSheet = [[UIActionSheet alloc] initWithTitle:@"AmountKnown" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:nil];
    [anActionSheet addButtonWithTitle:@"true"];
    [anActionSheet addButtonWithTitle:@"false"];
    [anActionSheet showInView:self.view];
}


- (IBAction)chageLater:(UIButton *)iSender {
    self.anAmountKnown.tag = 1111;
    self.aChargeLater.tag = 222;
    self.aStatusCheck.tag = 3333;
    NSLog(@"%@",iSender.currentTitle);
    UIActionSheet *anActionSheet = [[UIActionSheet alloc] initWithTitle:@"ChargeLater" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:nil];
    [anActionSheet addButtonWithTitle:@"true"];
    [anActionSheet addButtonWithTitle:@"false"];
    [anActionSheet showInView:self.view];
}

- (IBAction)statusCheck:(UIButton *)iSender {
    self.anAmountKnown.tag = 1111;
    self.aChargeLater.tag = 2222;
    self.aStatusCheck.tag = 333;
    NSLog(@"%@",iSender.currentTitle);
    UIActionSheet *anActionSheet = [[UIActionSheet alloc] initWithTitle:@"StatusCheck" delegate:self cancelButtonTitle:@"Cancel" destructiveButtonTitle:nil otherButtonTitles:nil];
    [anActionSheet addButtonWithTitle:@"true"];
    [anActionSheet addButtonWithTitle:@"false"];
    [anActionSheet showInView:self.view];
}

- (IBAction)checkStatus:(UIButton *)sender {
    NSString *aMerTxnId = self.merchantTransactionID;
    NSString *anAmount = self.anAmountValue;
    if (aMerTxnId && aMerTxnId.length > 0) {
        if ([self.anAmountKnown.currentTitle isEqualToString:@"true"]) {
            [self callCheckStatus];
        } else {
            NSString *aTitle = [NSString stringWithFormat:@"Enter amount to change(in implied decimals)"];
            UIAlertView *anAlertView = [[UIAlertView alloc] initWithTitle:@"Amount" message:aTitle delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"Ok", nil];
            [anAlertView setAlertViewStyle:UIAlertViewStylePlainTextInput];
            [anAlertView setTag:CHECK_STATUS_TAG];
            
            UITextField *aTextField = [anAlertView textFieldAtIndex:0];
            if (anAmount) {
                [aTextField setText:anAmount];
            }
            [aTextField setKeyboardType:UIKeyboardTypeDecimalPad];
            [aTextField setTag:CHECK_STATUS_TAG];
            [aTextField setDelegate:self];
            [anAlertView show];
        }
    } else {
        NSString *aMessage = @"Your txn should be started; before you can do status check!";
        [[[UIAlertView alloc] initWithTitle:@"Alert" message:aMessage delegate:nil
                          cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
    }
}

- (void)callCheckStatus {
    self.aCheckStatus.tag = 444;
    NSString *aMerTxnId = self.merchantTransactionID;
    NSString *anAmount = self.anAmountValue;
    NSDate *aNewDate = [NSDate date];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc]init];
    [dateFormatter setDateFormat:@"yyyyMMdd"];
    NSLocale *inLocale1 = [[NSLocale alloc] initWithLocaleIdentifier:@"en_IN"];
    [dateFormatter setLocale:inLocale1];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
    [dateFormatter setTimeZone:[NSTimeZone systemTimeZone]];
    NSString *aMerTxnDate = [dateFormatter stringFromDate:aNewDate];
    NSString *aWibmoTxnId = [self.aPaymentDetails valueForKey:@"wibmoTxnId"];
    NSString *aChargeUser = self.aStatusCheck.currentTitle;
    NSString *anEndPoint;
    if (self.isWPayEnabled){
        anEndPoint = [NSString stringWithFormat:STATUS_CHECK_WPAY, aMerTxnId, anAmount, aMerTxnDate, aChargeUser,aWibmoTxnId];
    } else {
        anEndPoint = [NSString stringWithFormat:STATUS_CHECK_W2FA, aMerTxnId, anAmount, aMerTxnDate, aChargeUser,aWibmoTxnId];
        
    }
    NSString *aHashAPI = [NSString stringWithFormat:@"%@%@", BASE_URL, anEndPoint];
    NSLog(@"HashAPI: %@", aHashAPI);
    
    NSURL *anURL = [NSURL URLWithString:aHashAPI];
    NSURLRequest *anURLRequest=[NSURLRequest requestWithURL:anURL cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:30.0];
    
    NSLog(@"URL: %@", anURL);
    self.responseData = [[NSMutableData alloc] init];
    self.urlConnection =[[NSURLConnection alloc] initWithRequest:anURLRequest delegate:self startImmediately:YES];
}

- (void)generateMessageHash {
    self.anAmountValue = self.anAmount.text;
    NSString *anAppData = @"AppDATA";
    NSString *anAmount = self.anAmountValue;
    NSString *messageHashAmount = self.anMessageHashAmount.text;
    NSString *anAmountKnown = self.anAmountKnown.titleLabel.text;
    NSString *aChargeLater = self.aChargeLater.titleLabel.text;
    NSString *anEndPoint;
    if (self.isWPayEnabled){
        anEndPoint = [NSString stringWithFormat:GET_MSG_HASH, messageHashAmount, ENCODE_STRING(anAppData), anAmountKnown, aChargeLater, self.apiVersion.selectedSegmentIndex+1];
    } else {
        anEndPoint = [NSString stringWithFormat:GET_MSG_HASH_W2FA, messageHashAmount, ENCODE_STRING(anAppData), anAmountKnown, aChargeLater, self.apiVersion.selectedSegmentIndex+1];
    }
    NSString *aHashAPI = [NSString stringWithFormat:@"%@%@", BASE_URL, anEndPoint];
    NSLog(@"HashAPI: %@", aHashAPI);
    
    NSURL *anURL = [NSURL URLWithString:aHashAPI];
    NSURLRequest *anURLRequest=[NSURLRequest requestWithURL:anURL cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:30.0];
    
    NSLog(@"URL: %@", anURL);
    self.responseData = [[NSMutableData alloc] init];
    self.urlConnection =[[NSURLConnection alloc] initWithRequest:anURLRequest delegate:self startImmediately:YES];
}


- (void)initializePayment {
    WSMerchantInfo *aMerchantInfo = [[WSMerchantInfo alloc] init];
    aMerchantInfo.merchantCountryCode = @"IN";
    aMerchantInfo.merchantName = @"MerchantName";
    
    // PRODUCTION
    //aMerchantInfo.merchantID = @"5344117557917234438";
    //aMerchantInfo.merchantAppID = @"7016";
    
    // STAGING
    aMerchantInfo.merchantID = @"81516121";
    aMerchantInfo.merchantAppID = @"1";
    
    WSTransactionInfo *aTransactionInfo = [[WSTransactionInfo alloc] init];
    aTransactionInfo.transactionCurrency = @"356";
    aTransactionInfo.transactionAmount = self.anAmountValue;
    aTransactionInfo.merchantAppData = @"AppDATA";
    aTransactionInfo.transactionDescription = @"Transaction from sample merchant for amount 1";
    aTransactionInfo.txnAmtKnownvalue = self.anAmountKnown.currentTitle;
    aTransactionInfo.chargeLatervalue = self.aChargeLater.currentTitle;
    
    aTransactionInfo.messageHash = self.messageHash;
    aTransactionInfo.merchantTransactionId = self.merchantTransactionID;
    aTransactionInfo.transactionDate = self.merchantTxndate;
    aTransactionInfo.merchantData = @"merData";
    
    WSCustomerInfo *aCustomerInfo = [[WSCustomerInfo alloc] init];
    aCustomerInfo.customerEmail = @"someone@enstage.com";
    aCustomerInfo.customerMobile = self.aMobileNumber.text;
    aCustomerInfo.customerName = @"Preetham Hegde";
    aCustomerInfo.customerDateOfBirth = @"20010101";
    
    WibmoSDK *aWibmoSDK = [[WibmoSDK alloc] initWithTransactionInfo:aTransactionInfo merchanInfo:aMerchantInfo customerInfo:aCustomerInfo withDelegate:self isProductionBuild:NO];
    [self.navigationController presentViewController:aWibmoSDK animated:YES completion:^{
        aWibmoSDK.isBillingAddress = self.swBillingAddress.on;
        aWibmoSDK.isShippingAddress = self.swShippingAddress.on;
        aWibmoSDK.isCollectEmail = self.swShippingAddress.on;

        if (self.isWPayEnabled) {
            aTransactionInfo.supportedPaymentType = @[PAYMENT_TYPE_ALL];
            aTransactionInfo.restrictedPaymentType = @[PAYMENT_TYPE_NONE];
            [aWibmoSDK initializePayment];
        } else {
            aTransactionInfo.supportedPaymentType = @[PAYMENT_TYPE_ALL];
            aTransactionInfo.restrictedPaymentType = @[PAYMENT_TYPE_NONE];
            [aWibmoSDK initializeW2FAPayment];
        }
    }];
}


#pragma mark - UIActionSheetDelegate

- (void)actionSheet:(UIActionSheet *)iActionSheet clickedButtonAtIndex:(NSInteger)iButtonIndex {
    if (iButtonIndex > 0) {
        NSString *anActionSheetValue = [iActionSheet buttonTitleAtIndex:iButtonIndex];
        if (self.anAmountKnown.tag == 111) {
            [self.anAmountKnown setTitle:anActionSheetValue forState:UIControlStateNormal];
        } else if (self.aChargeLater.tag == 222) {
            [self.aChargeLater setTitle:anActionSheetValue forState:UIControlStateNormal];
        } else if (self.aStatusCheck.tag == 333) {
            [self.aStatusCheck setTitle:anActionSheetValue forState:UIControlStateNormal];
        }
    }
}

#pragma mark - WibmoSDKDelegate

- (void)paymentSuccessfulWithTranscation:(NSDictionary *)iTransaction {
    NSString *aTransactionID = [iTransaction valueForKey:@"wibmoTxnId"];
    self.aPaymentDetails = iTransaction;
    [self.navigationController dismissViewControllerAnimated:YES completion:^{
        NSString *aMessage = [NSString stringWithFormat:@"Your payment was made successfully.\n\nTransaction ID: %@", aTransactionID];
        if ([aTransactionID isKindOfClass:[NSNull class]]) {
            aMessage = [NSString stringWithFormat:@"Your payment was made successfully."];
        }
        if ([iTransaction valueForKey:@"dataPickUpCode"]) {
            aMessage = [aMessage stringByAppendingFormat:@"\n\nPickUp Code: %@", [iTransaction valueForKey:@"dataPickUpCode"]];
        }
        
        [[[UIAlertView alloc] initWithTitle:@"Congratulations!" message:aMessage delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
    }];
}


- (void)paymentFailedWithError:(NSError *)iError {
    [self.navigationController dismissViewControllerAnimated:NO completion:^{
        self.merchantTransactionID = nil;
        if ([iError isKindOfClass:[NSDictionary class]]) {
            NSDictionary *aErrorDetails = [iError mutableCopy];
            if ([[aErrorDetails allKeys] containsObject:@"resDesc"]) {
                NSString *aMessage = [iError valueForKey:@"resDesc"];
                [[[UIAlertView alloc] initWithTitle:@"Sorry!" message:aMessage delegate:self
                                  cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
            } else {
                NSString *aMessage = @"Something went wrong. Please try again.";
                [[[UIAlertView alloc] initWithTitle:@"Sorry!" message:aMessage delegate:self
                                  cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
            }
        } else if ([iError.userInfo valueForKey:@"Message"]) {
            NSString *aMessage = [iError.userInfo valueForKey:@"Message"];
            [[[UIAlertView alloc] initWithTitle:@"Failed!" message:aMessage delegate:self
                              cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        } else if ([iError.userInfo valueForKey:@"NSLocalizedDescription"]) {
            NSString *aMessage = @"There seems to be some issue with the connection. Please check your network and try again later.";
            [[[UIAlertView alloc] initWithTitle:@"Sorry!" message:aMessage delegate:self
                              cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
        }
        
    }];
}


- (void)paymentCancelled {
    [self.navigationController dismissViewControllerAnimated:YES completion:^{
        self.merchantTransactionID = nil;
        NSString *aMessage = [NSString stringWithFormat:@"Your payment was cancelled."];
        [[[UIAlertView alloc] initWithTitle:@"Failed!" message:aMessage delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
    }];
}


- (void)paymentTimedOut {
    [self.navigationController dismissViewControllerAnimated:YES completion:^{
        self.merchantTransactionID = nil;
        NSString *aMessage = [NSString stringWithFormat:@"Your payment was timed out."];
        [[[UIAlertView alloc] initWithTitle:@"Sorry!" message:aMessage delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil] show];
    }];
}


#pragma mark - touch
-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}

-(void)dismissInput {
    [self.activeTextField resignFirstResponder];
    self.activeTextField = nil;
}

#pragma mark - UITextFieldDelegate

- (void)textFieldDidBeginEditing:(UITextField *)textField {
    self.activeTextField = textField;
}
- (void)textFieldDidEndEditing:(UITextField *)textField {
    [self.activeTextField resignFirstResponder];
    self.activeTextField = nil;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    self.activeTextField = nil;
    return true;
}


@end



// Bypass SSL Domain Errors.

@implementation NSURLRequest(DataController)

+ (BOOL)allowsAnyHTTPSCertificateForHost:(NSString *)host {
    return YES;
}



@end
