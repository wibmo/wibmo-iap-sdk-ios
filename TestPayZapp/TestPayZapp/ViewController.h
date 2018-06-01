//
//  ViewController.h
//  TestPayZapp
//
//  Created by WIBMO on 20/08/15.
//  Copyright (c) 2015 WIBMO. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <WibmoSDK/WSConstant.h>


@interface ViewController : UIViewController

@property (retain, nonatomic) IBOutlet UITextField *aMobileNumber;
@property (retain, nonatomic) IBOutlet UITextField *anAmount;
@property (retain, nonatomic) IBOutlet UIButton *anAmountKnown;
@property (retain, nonatomic) IBOutlet UIButton *aChargeLater;
@property (retain, nonatomic) IBOutlet UIButton *aStatusCheck;
@property (retain, nonatomic) IBOutlet UIButton *aCheckStatus;
@property (retain, nonatomic) IBOutlet UIButton *aPaymentType;


- (IBAction)payWithPayZapp:(id)iSender;
- (IBAction)amountKnown:(UIButton *)iSender;
- (IBAction)chageLater:(UIButton *)iSender;
- (IBAction)statusCheck:(UIButton *)sender;
- (IBAction)checkStatus:(UIButton *)sender;
- (IBAction)paymentType:(UIButton *)sender;

@end

