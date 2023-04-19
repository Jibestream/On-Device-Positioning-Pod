#
# Be sure to run `pod lib lint On-Device-Positioning-Pod.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'On-Device-Positioning-Pod'
s.version='1.5.7.1'
  s.summary          = 'Inpixon On Device PositioningPod.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = "This Cocoapod provides on device positioning capability"

  s.homepage         = 'https://github.com/jibestream/On-Device-Positioning-Pod'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Chuantao Zang' => 'chuantao.zang@inpixon.com' }
  s.source           = { :git => 'https://github.com/jibestream/On-Device-Positioning-Pod.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.static_framework = true

  s.source_files = 'On-Device-Positioning-Pod/Classes/**/*'
  s.vendored_frameworks = 'On-Device-Positioning-Pod/Frameworks/extend.xcframework'
  # s.resource_bundles = {
  #   'On-Device-Positioning-Pod' => ['On-Device-Positioning-Pod/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
