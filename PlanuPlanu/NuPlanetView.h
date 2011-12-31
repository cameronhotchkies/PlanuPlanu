//
//  NuPlanetView.h
//  PlanuPlanu
//
//  Created by Cameron Hotchkies on 12/29/11.
//  Copyright 2011 Roboboogie Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <PlanuKit/PlanuKit.h>

@interface NuPlanetView : NSView
{
    NuPlanet* planet;
    NuPlayer* player;
}

@property (nonatomic, retain) NuPlanet* planet;
@property (nonatomic, retain) NuPlayer* player;

- (id)initWithPlanet:(NuPlanet*)planet;

@end