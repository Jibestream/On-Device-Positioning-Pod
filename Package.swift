// swift-tools-version:5.9
// Swift Package Manager distribution of the Inpixon On-Device Positioning SDK, starting at
// 2.0.0. The same git tag also serves the CocoaPods podspec
// (On-Device-Positioning-Pod.podspec) until CocoaPods is retired.
//
// Release: tag the commit with a THREE-component semantic version (e.g. `2.0.0`, no `v`
// prefix) and keep `s.version` in the podspec in step with it. The historical
// four-component tags (1.5.6.0, 1.5.7.0, 1.5.7.1, ...) are not semantic versions and
// SwiftPM ignores them outright - of the tags that exist today only `1.5.5` is visible to
// SPM at all, which is why SPM support starts at a fresh 2.0.0 rather than continuing the
// 1.5.x line.
import PackageDescription

let package = Package(
    name: "On-Device-Positioning-Pod",
    platforms: [
        // The shipped binary declares an iOS 9 floor and stays forward-compatible, so this
        // is a policy floor chosen to match the rest of the Jibestream SDK stack.
        .iOS(.v15)
    ],
    products: [
        // Named for the framework, which is what consumers write in their #import. A binary
        // target's name must match the xcframework basename, so both are `extend`.
        .library(
            name: "extend",
            targets: ["extend"]
        )
    ],
    targets: [
        // Static Objective-C framework containing no Objective-C categories, so it adds no
        // -ObjC requirement of its own. Note the CocoaPods podspec sets
        // `s.static_framework = true`, which is what makes -ObjC appear in a CocoaPods
        // consumer's generated xcconfig; that does not carry over to SPM.
        //
        // Everything it needs is auto-linked from both directions: the umbrella header
        // `@import`s CoreMotion, CoreLocation, CoreBluetooth and QuartzCore, and the archive
        // itself carries LC_LINKER_OPTION entries for 19 system frameworks. Verified by
        // building a consumer that references `Extend` and reading CoreMotion, CoreLocation
        // and CoreBluetooth back out of the resulting object file. Hence no linkerSettings.
        //
        // No shim target here. Unlike the JMap kits, these headers import nothing from
        // another package, so there is no cross-package dependency edge for one to carry.
        //
        // The framework ships no Modules/module.modulemap, so there is no Clang module and
        // Swift `import extend` fails with "Unable to resolve module dependency". Consumers
        // use it from Objective-C via `#import <extend/extend.h>`, which is verified working
        // through SPM. See README.md.
        .binaryTarget(
            name: "extend",
            path: "On-Device-Positioning-Pod/Frameworks/extend.xcframework"
        )
    ]
)
