#
# Be sure to run `pod lib lint wibmo-sdk.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'wibmo-sdk'
  s.version          = '0.2.0'
  s.summary          = 'A pod for merchants to test iap transactions at there end.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
This pod is especially created for merchatns to check the iap transactions for success, failure. 
Merchant can use to test various iap configurations for allowing only wallet, only cards etc for iap transactions. 
An Example app would be available later for viewing the usage for the pod.
                       DESC

  s.homepage         = 'https://github.com/wibmo/wibmo-iap-sdk-ios.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'Apache License 2.0', :file => 'LICENSE' }
  s.author           = { 'manjunatha vaddhiraju' => 'manjunatha.vaddhiraju@wibmo.com' }
  s.source           = { :git => 'https://github.com/wibmo/wibmo-iap-sdk-ios.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = '*.h'
  s.vendored_libraries = '*.a'
  # s.resource_bundles = {
  #   'wibmo-sdk' => ['wibmo-sdk/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'SBJson', '5.0'
end
