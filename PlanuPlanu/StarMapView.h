//
//  StarMapView.h
//  PlanuPlanu
//
//  Created by Cameron Hotchkies on 12/24/11.
//  Copyright 2011 Roboboogie Studios. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <PlanuKit/PlanuKit.h>
#import "PlanetPopoverController.h" 

@interface StarMapView : NSView
{
    NSArray *planets;
    CGPoint startOrigin;
    CGPoint startPt;
    NuPlayer* player;
    PlanetPopoverController *popover;
    NSArray *ionStorms;
    NSArray *ships;
    
    NSArray* planetViews;
    NSArray* shipViews;
    NSArray* stormViews;
    NSArray* connectionViews;
}

@property (nonatomic, retain) NSArray* planets;
@property (nonatomic, retain) NuPlayer* player;
@property (nonatomic, retain) NSArray* ionStorms;
@property (nonatomic, retain) NSArray* ships;

@property (nonatomic, retain) NSArray* planetViews;
@property (nonatomic, retain) NSArray* shipViews;
@property (nonatomic, retain) NSArray* stormViews;
@property (nonatomic, retain) NSArray* connectionViews;

- (id)initWithTurn:(NuTurn*)turn;

- (void)showPlanetPopover:(NuPlanet*)planet;
- (void)scrollToHomeWorld;

- (void)addIonStorms;
- (void)addPlanets;
- (void)addShips;
- (void)addPlanetaryConnections;

- (void)setPlanetsHidden:(BOOL)visibility;
- (void)setShipsHidden:(BOOL)visibility;
- (void)setStormsHidden:(BOOL)visibility;
- (void)setConnectionsHidden:(BOOL)visibility;

@end
