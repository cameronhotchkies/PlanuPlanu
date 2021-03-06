//
//  Fleet Manifest.m
//  PlanuPlanu
//
//  Created by Cameron Hotchkies on 1/15/12.
//  Copyright 2012 Roboboogie Studios. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "FleetManifestWindowController.h"

@interface FleetManifestWindowController (private)

- (void)loadActivePlayerFleet;
- (void)loadAllSeenShips;

@end

@implementation FleetManifestWindowController

@synthesize fleetManifest, fleetManifestController, fleetTable, game;

- (id)initWithWindow:(NSWindow *)window
{
    self = [super initWithWindow:window];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)windowDidLoad
{
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
    [self loadActivePlayerFleet];
}

- (void)loadActivePlayerFleet
{
    NSMutableArray* fm = [NSMutableArray array];
    
    NuTurn* latestTurn = nil;
    {
        for (NuTurn* t in self.game.turns)
        {
            if (latestTurn == nil || latestTurn.settings.turnNumber < t.settings.turnNumber)
            {
                latestTurn = t;
            }
        }
    }
    
    for (NuShip* ship in latestTurn.ships)
    {
        if (ship.ownerId == latestTurn.player.playerId)
        {
            [fm addObject:ship];
        }
    }
    
    self.fleetManifest = fm;
}

- (void)loadAllSeenShips
{
    NSMutableArray *allShips = [NSMutableArray array];
        
    for (int i = 0; i < 500; i++)
    {
        NuShip* blankShip = [NuShip blankShip];
        blankShip.name = @"Unknown";
        blankShip.shipId = i+1;
        blankShip.hullId = 0;
        [allShips addObject:blankShip];
    }
    
    NuTurn* latestTurn = nil;
    {
        for (NuTurn* t in self.game.turns)
        {
            if (latestTurn == nil || latestTurn.settings.turnNumber < t.settings.turnNumber)
            {
                latestTurn = t;
            }
        }
    }
    
    NSSortDescriptor * sortByTurn =
    [[[NSSortDescriptor alloc] initWithKey:@"settings.turnNumber" ascending:NO] autorelease];
    
    NSArray* descriptors = [NSArray arrayWithObject:sortByTurn];
    NSArray* turns = [self.game.turns sortedArrayUsingDescriptors:descriptors];
    
    for (NuTurn* turn in turns)
    {
        for (NuShip* turnShip in turn.ships)
        {
            NSInteger shipIdx = turnShip.shipId - 1;
            
            if (((NuShip*)[allShips objectAtIndex:shipIdx]).hullId == 0)
            {
                [allShips replaceObjectAtIndex:turnShip.shipId - 1 withObject:turnShip];
            }
        }
    }
    
    self.fleetManifest = allShips;
}

- (IBAction)enemyFleetDisplayClicked:(id)sender
{
    // TODO: this
//    NSMutableArray* newFleet = [NSMutableArray array];
//    
//    NSLog(@"Fleet size = %ld", [fleetManifest count]);
//    
//    for (NuShip* ship in fleetManifest)
//    {
//        if (ship.shipId < 100)
//        {
//            [newFleet addObject:ship];
//        }
//    }
//    self.fleetManifest = newFleet;
    NSButton* checkbox = (NSButton*)sender;
    
    NSInteger colIdx;
    NSTableColumn* col;
    
    BOOL showEnemy = (checkbox.state == NSOnState);
    
    colIdx = [fleetTable columnWithIdentifier:@"lastseen"];
    col = [fleetTable.tableColumns objectAtIndex:colIdx];
    [col setHidden:(showEnemy == NO)];
    colIdx = [fleetTable columnWithIdentifier:@"player"];
    col = [fleetTable.tableColumns objectAtIndex:colIdx];
    [col setHidden:(showEnemy == NO)];
    
    if (showEnemy == YES)
    {
        [self loadAllSeenShips]; 
    }
    else
    {
        [self loadActivePlayerFleet];        
    }
    
}

@end
