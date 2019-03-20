# Wibmo SDK Integration (iOS)
This document describes the steps to integrate the Wibmo SDK with your iOS application, to make IAP (In App Payments) using PayZapp platform. 

### Important 
You must have a PayZapp Wallet merchant account to use the In-app Payment service.

### System Requirements
To be able to integrate PayZapp into your iOS App you will need the following
* Access to WibmoSdk
* **Merchant ID**, **Merchant App ID** and **Hash Key** from PayZapp UAT/production environment.
* This documentation and sample App.
* Latest version of sdk is 3.0.0 is available via cocoapods which is compiled using Xcode 10.1 and Swift 4.2.1 compiler.

### Adding Wibmo SDK as dependency to iOS Application

#### Cocoa pod (Recommended)
* In your project's podfile include under your app target pod 'wibmo-sdk’.
* Then pod install.

#### Then
1. Add URL scheme to your projects Info.plist file.

* Format for URLScheme: pz<Merchant ID>
* Eg: If your Merchant ID is 123456789 then URLScheme is pz123456789
* ![](images/URlScheme.png)

**Note:**
Merchant ID’s are different for different configuration environments. i.e. Its different for production and UAT environments.

2. In your target's Info.plist add
Add dictionary item LSApplicationQueriesSchemes
![](images/LSApplicationQueriesSchemes.png)

### Usage 
1. \#import WibmoSDK in your ViewController.
2. Include in your AppDelegate methods, and post appropriate notification.

```objc
- (BOOL)application:(UIApplication *)iApplication openURL:(NSURL *)iURL sourceApplication:(NSString *)iSourceApplication
         annotation:(id)iAnnotation {
    if (iURL && [[iURL scheme] isEqualToString:@"pz81516121"]) {
        [[NSNotificationCenter defaultCenter] postNotificationName:PROCESS_INAPP_PAYMENT object:[iURL absoluteString]];
    }
    return YES;
}

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)iURL {
    if (iURL && [[iURL scheme] isEqualToString:@"pz123456789"]) {
        [[NSNotificationCenter defaultCenter] postNotificationName:PROCESS_INAPP_PAYMENT object:[iURL absoluteString]];
    }
    return YES;
}
```

**Note:** 
For application supporting iOS 9 and above please use the below method. 

```objc
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    if (iURL && [[iURL scheme] isEqualToString:@"pz123456789"]) {
        [[NSNotificationCenter defaultCenter] postNotificationName:PROCESS_INAPP_PAYMENT object:[iURL absoluteString]];
    }
    return YES;
}
```

```swift
func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
        if url.scheme == "pz123456789" {
            NotificationCenter.default.post(name: Notification.Name(rawValue: kAppIAPProcessNotification), object: url.absoluteString)
        }
        return true
    }
```


3. To initiate payment do :-
	1. Generate Message Hash by capturing relevant details like transaction amount, merchantAppData, txnType(WPay/W2fa)
	2. Initialise WSMerchantInfo
	3. Initialise WibmoSDK and set delegate and datasource
	4. Invoke performIAPTransactionFrom api to initiate the transaction.

```objc
WSTransactionInfo *transactionInfo = [[WSTransactionInfo alloc] initWithMsgHash:messageHash[@"msgHash"] txnCurrency:kTxnCurrencyCode chargeLater:YES merAppData:merchantAppData merTxnId:messageHash[@"merTxnId"] restrictedPaymentType:@[WSPaymentOption.kPaymentOptionNone] txnAmtKnown:NO merDataField:@"Merchant Data" supportedPaymentType:@[WSPaymentOption.kPaymentOptionAllCards] txnDate:messageHash[@"txnDate"] txnDesc:@"Transaction from sample merchant for rupee 1" txnAmount:self.amount.text];

self.paymentSdk = [[WibmoSDK alloc] initWithTransactionDetails:transactionInfo datasource:self delegate:self];

[self.paymentSdk performIAPTransactionFrom:self];
```

```swift
let transactionInfo = WSTransactionInfo(msgHash: msgHash, txnCurrency: "356", chargeLater: chargeLater.isOn, merAppData: "AppDATA", merTxnId: txnId, restrictedPaymentType: [WSPaymentOption.kPaymentOptionNone], txnAmtKnown: amountKnown.isOn, merDataField: "merData", supportedPaymentType: [WSPaymentOption.kPaymentOptionAllCards], txnDate: date, txnDesc: "Transaction from sample merchant for amount 1", txnAmount: amount.text!)

wibmoPaymentSdk = WibmoSDK(transactionDetails: transactionInfo, datasource: self, delegate: self)

wibmoPaymentSdk?.performIAPTransaction(from: self)
```

**Note:** 
WibmoSDK can point to different url based on your environment. i.e. production or staging.
	3. Implement WibmoSDK protocols (listed below) as per your requirement.

Eg:
```objc
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
```

```swift
extension ViewController: WSPaymentDatasource {

    func requiresBillingAddressFor(transaction: WSTransactionInfo) -> Bool {
        return billingAddrRequired.isOn
    }
    
    func requiresShippingAddressFor(transaction: WSTransactionInfo) -> Bool {
        return shippingAddrRequired.isOn
    }
    
    func requiresEmailIdFor(transaction: WSTransactionInfo) -> Bool {
        return emailIdRequired.isOn
    }
    
    func cardInfoFor(transaction: WSTransactionInfo) -> WSCardInfo? {
        return nil
    }
    
    func buildType() -> WSBuildType {
        return .staging //.production
    }
    
    func iapVersion() -> WSIAPVersion {
        return .v2
    }
    
    func merchantInfoFor(transaction: WSTransactionInfo) -> WSMerchantInfo {
        let merchantInfo = WSMerchantInfo(merName: "Sample Test Merchant", merCountryCode: "IN", merId: "81516121", merAppId: "1")
        
        return merchantInfo
    }
    
    func customerInfoFor(transaction: WSTransactionInfo) -> WSCustomerInfo {
        let customerInfo = WSCustomerInfo(custName: "Guest User", custDob: "01012000", custEmail: "test@enstage.com", custMobile: "9999999999")
        return customerInfo
    }
    
    func isWpayTransaction() -> Bool {
        return (paymentType.selectedSegmentIndex == 0)
    }
}
```

```objc
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
```

```swift
extension ViewController: WSPaymentDelegate {
    func paymentSuccessfullFor(transaction: Dictionary<String, Any>) {
        let alert = UIAlertController(title: "Success", message: "Transaction compeleted succesfully.", preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
        alert.addAction(okAction)
        self.present(alert, animated: true, completion: nil)
        self.transactionStatus = transaction
        self.transactionStatusLabel.text = transaction.description
        print(transaction.description)
    }
    
    func paymentFailed(error: Error) {
        let alert = UIAlertController(title: "Error", message: "Transaction failed to complete. Error: \(error.localizedDescription)", preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
        alert.addAction(okAction)
        self.present(alert, animated: true, completion: nil)
        print(error.localizedDescription)
    }
}
```

**Note:**
Error Response Dictionary Eg: 

```javascript
{
"resCode": "000",
"resDesc": "SUCCESS",
"status": "50020",
"pgErrorCode": "0",
"pgErrorDetail": "No Error",
"pgVoidTransactionId": "50204001", "newMerchantReferenceNo": "WPAYTXN1125398084375506", "rrn": "636510123204"
}

{
"resCode": "050",
"resDesc": "FAILURE",
"status": "50021",
"pgErrorCode": "10024",
"pgErrorDetail": "Void has already been done"
}

{
"resCode": "053",
"resDesc": "Invalid client IP in void request!"
}
```

**Important:** 
_Error Codes and Description_ 


| Code  | Description | 
| ----- | ----------- |
| 053   | Merchant Txn Id/WibmotxnId not passed! |
| 053   | Bad merchantId |
| 053   | Merchant not active! |
| 053   | Invalid client IP in void request! |
| 051   | Internal Error | 
| 204   | User Abort |
| 070   | Message hash failed |
| 080   | Too Early; Re-try after some time |
| 000   | Success |
| 050   | Failure |

_Status Code and Description_ 

| Code  | Description | 
| ----- | ----------- |
| 50020 | Success|
| 50021 | Failed |

**Note:**
* You can download the Example App at the github repository [here](https://github.com/wibmo/wibmo-iap-sdk-ios/tree/master/TestPayZapp)
* Especially note in the example app that if amount and message hash amount are different then you should get a message hash failure as the response from the sdk.

   
