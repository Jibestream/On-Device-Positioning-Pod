# On-Device-Positioning-Pod

[![CI Status](https://img.shields.io/travis/louieyuen/On-Device-Positioning-Pod.svg?style=flat)](https://travis-ci.org/louieyuen/On-Device-Positioning-Pod)
[![Version](https://img.shields.io/cocoapods/v/On-Device-Positioning-Pod.svg?style=flat)](https://cocoapods.org/pods/On-Device-Positioning-Pod)
[![License](https://img.shields.io/cocoapods/l/On-Device-Positioning-Pod.svg?style=flat)](https://cocoapods.org/pods/On-Device-Positioning-Pod)
[![Platform](https://img.shields.io/cocoapods/p/On-Device-Positioning-Pod.svg?style=flat)](https://cocoapods.org/pods/On-Device-Positioning-Pod)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

- **iOS 15.0 or later**, as of 2.0.0. Earlier releases declare an iOS 9.0 floor.
- **Xcode 15 or later** for Swift Package Manager (`Package.swift` declares
  `swift-tools-version:5.9`). CocoaPods has no additional Xcode requirement
  beyond what the binary itself needs.
- **Objective-C to reach the API.** `extend.xcframework` ships no
  `Modules/module.modulemap`, so there is no Clang module and Swift
  `import extend` fails with `Unable to resolve module dependency: 'extend'`.
  Use it from Objective-C, or from Swift through a bridging header. See
  [Usage](#usage).
- **No other dependency.** The public headers import only `Foundation` and
  `@import` CoreMotion, CoreLocation, CoreBluetooth and QuartzCore, all of
  which are auto-linked. The archive additionally carries `LC_LINKER_OPTION`
  entries for the system frameworks it needs, so no linker flags are required
  on your side. Unlike the JMap kits this package does not depend on
  JMapiOSSDK.

## Installation

On-Device-Positioning supports **both** Swift Package Manager and CocoaPods. Both are
served from this one repository and the same git tag: SPM reads `Package.swift`,
CocoaPods reads `On-Device-Positioning-Pod.podspec`, and both point at the same
XCFramework under `On-Device-Positioning-Pod/Frameworks/`. Each ignores the
other's manifest.

> **Pick one.** Adding this framework through both CocoaPods and Swift Package
> Manager in the same project links it twice and fails with duplicate symbol
> errors.

### Swift Package Manager (2.0.0 and later)

In Xcode, choose **File > Add Package Dependencies...**, enter
`https://github.com/Jibestream/On-Device-Positioning-Pod.git`, pick **Up to Next
Major Version** from `2.0.0`, and add the `extend` product to your app target.

Or, in a `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/Jibestream/On-Device-Positioning-Pod.git", from: "2.0.0")
],
targets: [
    .target(
        name: "YourTarget",
        dependencies: [.product(name: "extend", package: "On-Device-Positioning-Pod")]
    )
]
```

Swift Package Manager support is available from **2.0.0** onward.

Note the version jump from 1.5.7.1 straight to 2.0.0. SwiftPM resolves only
three-component semantic versions, so the historical four-component tags
(`1.5.6.0`, `1.5.7.0`, `1.5.7.1`, ...) are invisible to it — of the tags
predating SPM support only `1.5.5` could be resolved at all. SPM support
therefore starts on a fresh three-component line. Tag every future release with
three components.

### CocoaPods (deprecated)

CocoaPods support continues for now but will be removed in a future release;
please move to Swift Package Manager.

To install, simply add the following line to your Podfile:

```ruby
pod 'On-Device-Positioning-Pod', :git => 'https://github.com/Jibestream/On-Device-Positioning-Pod.git'
```

For installing the first time run:
```ruby
pod install
```

To get the latest version of the pod run:
```ruby
pod update
```

## Usage

From Objective-C, import the umbrella header. Both the angle-bracket and quoted
forms resolve under either package manager:

```objc
#import <extend/extend.h>

NSDictionary *versions = [Extend version];
Extend *extend = [Extend sharedExtendWithKey:key url:nil delegate:self];
[extend start];
```

From Swift, add the same import to your bridging header rather than writing
`import extend`:

```objc
// YourApp-Bridging-Header.h
#import "extend/extend.h"
```

The public API is `Extend`, the `OnExtendDelegate` protocol, and the
`Location`, `Region`, `FloorPlan` and `TDNavOutput` model types.

## Author

louieyuen, lyuen@jibestream.com

## License

On-Device-Positioning-Pod is available under the MIT license. See the LICENSE file for more info.
