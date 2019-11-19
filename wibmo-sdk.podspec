#
# Be sure to run `pod lib lint WibmoSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'wibmo-sdk'
  s.version          = '3.0.8'
  s.summary          = 'A framework for merchants to enable PayZapp IAP Transactions from their app.'

  s.description      = <<-DESC
  This pod is especially created for merchants to do the PayZapp iap transactions.
      Merchant can use various iap configurations for allowing only wallet, only cards etc for iap transactions.
      An Example app is available for viewing the usage for the pod.
                       DESC

  s.homepage         = 'https://github.com/wibmo/wibmo-iap-sdk-ios.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'akhtarkhan' => 'akthar.khan@wibmo.com' }
  s.source           = { :git => 'https://github.com/wibmo/wibmo-iap-sdk-ios.git', :tag => s.version.to_s }
  s.swift_version    = '5.0'

  s.ios.deployment_target = '10.0'

  s.vendored_frameworks = 'WibmoSDK.framework'
  s.dependency 'SwiftyJSON', '~> 5'
  s.dependency 'Alamofire', '~> 4'
  s.dependency 'WKWebViewJSBridge', '~> 1.2'
  s.dependency 'SwiftKeychainWrapper', '~> 3.4'
end
