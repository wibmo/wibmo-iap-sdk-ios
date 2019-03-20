//
//  ViewController.swift
//  WibmoSDK
//
//  Created by akhtarraza on 07/16/2018.
//  Copyright (c) 2018 akhtarraza. All rights reserved.
//

import UIKit
import WibmoSDK
import Alamofire
import SwiftyJSON

enum WibmoBaseURL: String {
    case staging = "https://wallet.pc.enstage-sas.com/"
    case production = "https://www.wibmo.com/"
}

enum MessageHashApi: String {
    case wpay
    case w2fa
    
    func getMessageHashApiPath(amount: String, amountKnown:Bool, chargeLater: Bool, merchantAppData:String) -> String {
        
        let amtKnown = amountKnown ? "true" : "false"
        let chargeLater = chargeLater ? "true" : "false"
        let urlEncodedAppData = merchantAppData.addingPercentEncoding(withAllowedCharacters: .urlPathAllowed) ?? ""
        
        switch self {
        case .wpay:
            return "sampleMerchant/iap/generateInitReqMessageHash.jsp?txnAmount=\(amount)&merAppData=\(urlEncodedAppData)&merDyn=false&txnAmountKnown=\(amtKnown)&chargeLater=\(chargeLater)&txnType=WPay&version=2"
        case .w2fa:
            return "sampleMerchant/iap/generateInitReqMessageHash.jsp?txnAmount=\(amount)&merAppData=\(urlEncodedAppData)&merDyn=false&txnAmountKnown=\(amtKnown)&chargeLater=\(chargeLater)&txnType=W2fa&version=2"
        }
    }
}

class ViewController: UIViewController {

    @IBOutlet weak var mobileNumber: UITextField!
    @IBOutlet weak var amount: UITextField!
    @IBOutlet weak var msgHashAmount: UITextField!
    @IBOutlet weak var amountKnown: UISwitch!
    @IBOutlet weak var chargeLater: UISwitch!
    @IBOutlet weak var billingAddrRequired: UISwitch!
    @IBOutlet weak var shippingAddrRequired: UISwitch!
    @IBOutlet weak var emailIdRequired: UISwitch!
    @IBOutlet weak var paymentType: UISegmentedControl!
    @IBOutlet weak var transactionStatusLabel: UILabel!
    
    var wibmoPaymentSdk: WibmoSDK?
    var transactionStatus: Dictionary<String,Any>?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        self.mobileNumber.text = "9986477748"
        self.amount.text = "100"
        self.msgHashAmount.text = "100"
        transactionStatusLabel.text = nil
    }
    
    @IBAction func makePayment(_ sender: UIButton) {
        guard let mobileNumber = self.mobileNumber.text, mobileNumber.isEmpty == false, let amount = self.amount.text, amount.isEmpty == false else {
            
            let alert = UIAlertController(title: "Error", message: "Please enter valid details to proceed with the transaction.", preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
            alert.addAction(okAction)
            self.present(alert, animated: true, completion: nil)
            return
        }
        generateMsgHash()
    }
    
    @IBAction func checkPaymentStatus(_ sender: UIButton) {
        if transactionStatusLabel.text == nil {
            let alert = UIAlertController(title: "Error", message: "Please start the transaction first.", preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
            alert.addAction(okAction)
            self.present(alert, animated: true, completion: nil)
        } else{
            self.chargeTransaction(chargeNow: false)
        }
    }
    
    @IBAction func chargePayment(_ sender: UIButton) {
        if transactionStatusLabel.text == nil {
            let alert = UIAlertController(title: "Error", message: "Please start the transaction first.", preferredStyle: .alert)
            let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
            alert.addAction(okAction)
            self.present(alert, animated: true, completion: nil)
        } else{
            self.chargeTransaction(chargeNow: true)
        }
    }
    
    private func generateMsgHash() {
        guard let amount = amount.text else { return }
        
        var msgHashApiPath: String
        
        if paymentType.selectedSegmentIndex == 0 {
            msgHashApiPath = MessageHashApi.wpay.getMessageHashApiPath(amount: amount, amountKnown: amountKnown.isOn, chargeLater: chargeLater.isOn, merchantAppData: "AppDATA")
        } else {
            msgHashApiPath = MessageHashApi.w2fa.getMessageHashApiPath(amount: amount, amountKnown: amountKnown.isOn, chargeLater: chargeLater.isOn, merchantAppData: "AppDATA")
        }

        if let msgHashUrl = URL(string: "\(WibmoBaseURL.staging.rawValue)\(msgHashApiPath)") {
            let request = Alamofire.request(msgHashUrl)
                .validate(statusCode: 200...300)
                .responseData(queue: DispatchQueue.main) { [weak self] response in
                    if let data = response.result.value {
                        let jsonData = JSON(data)
                        print(jsonData)
                        if let merTxnId = jsonData["merTxnId"].string, let msgHash = jsonData["msgHash"].string, let merTxnDate = jsonData["txnDate"].string {
                            self?.initialisePayment(txnId: merTxnId, msgHash: msgHash, date: merTxnDate)
                        }
                    }
            }
            debugPrint(request)
        }
    }
    
    private func chargeTransaction(chargeNow: Bool) {
        if let transaction = transactionStatus, let wibmoTxnId = transaction["wibmoTxnId"] as? String,
            let merTxnId = transaction["merTxnId"] as? String, let txnAmount = amount.text {
            
            let dateFrmtr = DateFormatter()
            dateFrmtr.dateFormat = "yyyyMMdd"
            dateFrmtr.locale = Locale(identifier: "en_IN")
            dateFrmtr.timeZone = TimeZone.current
            let txnStatusDate = dateFrmtr.string(from: Date())
            
            var statusApiPath: String
            if paymentType.selectedSegmentIndex == 0 {
                statusApiPath = "sampleMerchant/iap/statusCheckv2.jsp?merTxnId=\(merTxnId)&txnAmount=\(txnAmount)&txnDate=\(txnStatusDate)&chargeUser=\(chargeNow)&txnType=WPay&wibmoTxnId=\(wibmoTxnId)"
            } else {
                statusApiPath = "sampleMerchant/iap/statusCheckv2.jsp?merTxnId=\(merTxnId)&txnAmount=\(txnAmount)&txnDate=\(txnStatusDate)&chargeUser=\(chargeNow)&txnType=W2fa&wibmoTxnId=\(wibmoTxnId)"
            }
                                                                                                                                                                                                                                                                                                                            
            if let statusApiUrl = URL(string: "\(WibmoBaseURL.staging.rawValue)\(statusApiPath)") {
                Alamofire.request(statusApiUrl)
                    .validate(statusCode: 200...300)
                    .responseData(queue: DispatchQueue.main) { [weak self] response in
                        if let data = response.result.value {
                            let jsonData = JSON(data)
                            if let merTxnId = jsonData["merTxnId"].string, let msgHash = jsonData["msgHash"].string, let merTxnDate = jsonData["txnDate"].string {
                                self?.initialisePayment(txnId: merTxnId, msgHash: msgHash, date: merTxnDate)
                            }
                        }
                }
            }
        }
    }
    
    private func initialisePayment(txnId: String, msgHash: String, date: String) {
        let transactionInfo = WSTransactionInfo(msgHash: msgHash, txnCurrency: "356", chargeLater: chargeLater.isOn, merAppData: "AppDATA", merTxnId: txnId, restrictedPaymentType: [WSPaymentOption.kPaymentOptionNone], txnAmtKnown: amountKnown.isOn, merDataField: "merData", supportedPaymentType: [WSPaymentOption.kPaymentOptionAllCards], txnDate: date, txnDesc: "Transaction from sample merchant for amount 1", txnAmount: amount.text!)
        wibmoPaymentSdk = WibmoSDK(transactionDetails: transactionInfo, datasource: self, delegate: self)
        wibmoPaymentSdk?.performIAPTransaction(from: self)
    }
}

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
        return .staging
    }
    
    func iapVersion() -> WSIAPVersion {
        return .v2
    }
    
    func merchantInfoFor(transaction: WSTransactionInfo) -> WSMerchantInfo {
        let merchantInfo = WSMerchantInfo(merName: "Sample Test Merchant", merCountryCode: "IN", merId: "81516121", merAppId: "1")
        
        return merchantInfo
    }
    
    func customerInfoFor(transaction: WSTransactionInfo) -> WSCustomerInfo {
        let customerInfo = WSCustomerInfo(custName: "Akhtar Raza", custDob: "19880405", custEmail: "test@enstage.com", custMobile: "9986477748")
        return customerInfo
    }
    
    func isWpayTransaction() -> Bool {
        return (paymentType.selectedSegmentIndex == 0)
    }
}

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
        let alert = UIAlertController(title: "Error", message: "Transaction failed to comeplete. Error: \(error.localizedDescription)", preferredStyle: .alert)
        let okAction = UIAlertAction(title: "OK", style: .default, handler: nil)
        alert.addAction(okAction)
        self.present(alert, animated: true, completion: nil)
        print(error.localizedDescription)
    }
}

