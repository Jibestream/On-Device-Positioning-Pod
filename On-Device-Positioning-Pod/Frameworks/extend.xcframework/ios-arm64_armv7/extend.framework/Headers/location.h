/****************************************************************************
 *
 * Copyright (c) 2021 Inpixon, Inc. All rights reserved.
 *
 * This source is subject to the Inpixon Software License.
 * This software is protected by Copyright and the information and source code
 * contained herein is confidential. The software including the source code
 * may not be copied and the information contained herein may not be used or
 * disclosed except with the written permission of Inpixon, Inc.
 *
 * All other rights reserved.
 *
 * This code and information are provided "as is" without warranty of any
 * kind, either expressed or implied, including but not limited to the
 * implied warranties of merchantability and/or fitness for a
 * particular purpose.
 *
 ****************************************************************************/

#import <Foundation/Foundation.h>
#import "TDJSONSerializable.h"
@import CoreLocation;

/// The Location class defines a point in either geographic latitude/longitude coordinates (degrees) or local X/Y coordinates (meters)
@interface Location : NSObject <TDJSONSerializable>


/// CLLocationCoordinate2D object to save location info
@property (nonatomic) CLLocationCoordinate2D latLong;
/// latitude (degrees) or X (meters)
@property (nonatomic) double x;
/// longitude (degrees) or Y (meters)
@property (nonatomic) double y;
/// elevation (meters) or Z (meters)
@property (nonatomic) double z;
/// Description
@property (nonatomic) double altitude;
/// true if geographic (latitude/longitude/elevation), false if local (X/Y/Z)
@property (nonatomic) bool isGeo;


/// For internal use.
/// @param array Input JSON array
+ (NSArray *) fromJSONArray: (NSArray *) array;

/// For internal use.
/// @param array Input array
+ (NSArray *) toJSONArray: (NSArray *) array;

/**
 * Parameterized constructor
 *
 * @param a latitude (degrees) or X (meters)
 * @param b longitude (degrees) or Y (meters)
 * @param c elevation (meters) or Z (meters)
 * @param isGeo true if geographic (latitude/longitude/elevation), false if local (X/Y/Z)
 * @param refLat reference latitude for location
 * @param refLon reference longitude for location
 */
- (Location *) initWitha: (double) a b: (double) b c: (double) c isGeo: (bool) geo refLat: (double) refLat refLon: (double) refLon;

/**
 * Computes distance to another location
 *
 * @param location location in degrees to compute distance
 * @return distance in meters
 */
- (double) distance: (CLLocationCoordinate2D) location;

/// Get latitude value of current location object
- (double) getLatitude;

/// Get longitude value of current location object
- (double) getLongitude;

/// Set latitude value for current location object
/// @param lat Input latitude value
- (void) setLatitude: (double) lat;

/// Set longitude value for current location object
/// @param lon Input longitude value
- (void) setLongitude: (double) lon;

/// Converts current location from geographic latitude/longitude coordinates (degrees) to local coordinates (meters)
/// @param latitude Reference point's latitude
/// @param longitude Reference point's longitude
- (void) convertToLocalWithRefLat: (double) latitude refLon: (double) longitude;

@end
