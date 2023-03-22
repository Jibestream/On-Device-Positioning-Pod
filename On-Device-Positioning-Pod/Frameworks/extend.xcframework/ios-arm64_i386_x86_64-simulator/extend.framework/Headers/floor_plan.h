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

/// The FloorPlan class defines the information for a floor plan.
@interface FloorPlan : NSObject <TDJSONSerializable>

///  floor plan image file name
@property (strong, nonatomic) NSString * file;
/// human readable name of floor
@property (strong, nonatomic) NSString * name;
///  X coordinate of image left (meters)
@property (nonatomic) float xMin;
/// X coordinate of image right (meters)
@property (nonatomic) float xMax;
/// Y coordinate of image bottom (meters)
@property (nonatomic) float yMin;
/// Y coordinate of image top (meters)
@property (nonatomic) float yMax;
/// floor number
@property (nonatomic) int floor;
/// elevation above ground floor (meters)
@property (nonatomic) float geoHeight;

@end
