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
#import "location.h"
@import CoreLocation;

/// The Region class defines a logical bounding area defined by a set of vertices
@interface Region : NSObject <TDJSONSerializable>

/// unique Id for current region object
@property (nonatomic) long uid;
/// human readable name of region
@property (strong, nonatomic) NSString * name;
/// region icon image name
@property (strong, nonatomic) NSString * icon;
/// type of region
@property (strong, nonatomic) NSString * type;

//@property (strong, nonatomic) NSString * units;

//@property (strong, nonatomic) NSNumber * searchScore;

/// floor index number region lives on
@property (nonatomic) int floor;

//@property (strong, nonatomic) NSString * floorName;

/// array of locations bounding the region
@property (strong, nonatomic) NSArray * locations;
/** distance to user in meters */
@property (nonatomic) float distanceToUser;
/** true if user is on the same floor as region */
@property (nonatomic) bool userOnSameFloor;
/**
 * Compute the centroid of the region from its bounds
 *
 * @return Location of centroid
 */
- (CLLocationCoordinate2D) getCentroid;
/**
 * Computes distance in meters to the centriod location
 *
 * @param location location to compute distance
 * @return distance in meters
 */
- (double) distance: (CLLocationCoordinate2D) location;
/**
 * Determine if location and floor number are within region boundaries.
 *
 * @param location Location to check if in bounds
 * @param floor floor number to check
 * @return true if location is within region bounds
 */
- (bool) inBoundsLocation: (CLLocationCoordinate2D) location inBoundsFloor: (float) floor;
/**
 * Determine if location is within region boundaries.
 *
 * @param location Location to check if in bounds
 * @return true if location is within region bounds
 */
- (bool)inBoundsLocation:(CLLocationCoordinate2D)location;
/**
 * Computes distance in meters to the location
 *
 * @param location location to compute distance
 * @return distance in meters
 */
- (double) distanceFromLocation: (Location *) location;
/**
 * Determine if location and floor number are within region boundaries.
 *
 * @param location Location to check if in bounds
 * @param floor floor number to check
 * @return true if location is within region bounds
 */
- (bool) inBounds: (Location *) location floor: (int) floor;

/**
 * Determine if location is within region boundaries.
 *
 * @param location Location to check if in bounds
 * @param floor floor number to check
 * @return true if location is within region bounds
 */
- (bool) inBounds: (Location *) location;

/// Initializes one region object with given dictionary
/// @param dictionary Input dictionary
- (id) initWithJSONObject: (NSDictionary *) dictionary;

/// Gets JSON object
- (NSDictionary *) getJSONObject;
@end
