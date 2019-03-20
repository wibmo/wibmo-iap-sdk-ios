#
# Be sure to run `pod lib lint WibmoSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'wibmo-sdk'
  s.version          = '3.0.0'
  s.summary          = 'A framework for merchants to enable PayZapp IAP Transactions from their app.'

  s.description      = <<-DESC
  This pod is especially created for merchants to do the PayZapp iap transactions.
      Merchant can use various iap configurations for allowing only wallet, only cards etc for iap transactions.
      An Example app is available for viewing the usage for the pod.
                       DESC

  s.homepage         = 'https://github.com/wibmo/wibmo-iap-sdk-ios.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'akhtarraza' => 'akthar.khan@wibmo.com' }
  s.source           = { :git => 'https://git.enstage-sas.com/wibmo-core-client/wibmo-iap-sdk-ios-swift.git', :tag => s.version.to_s }
  s.swift_version    = '4.2'

  s.ios.deployment_target = '9.0'

  s.vendored_frameworks = 'WibmoSDK.framework'
  s.dependency 'wibmo-analytics', '~> 2.1'
  s.dependency 'SwiftyJSON', '~> 4.2'
  s.dependency 'Alamofire', '~> 4'
  s.dependency 'WKWebViewJSBridge', '~> 1.2'
  s.dependency 'SwiftKeychainWrapper', '~> 3.2'
end
