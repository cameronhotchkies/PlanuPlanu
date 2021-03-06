//
//  StarMapController.h
//  PlanuPlanu
//
//  Created by Cameron Hotchkies on 12/23/11.
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

#import <Cocoa/Cocoa.h>
#import <PlanuKit/PlanuKit.h>
#import "StarMapView.h"
#import "NuColorScheme.h"
#import "MapMuxPopoverController.h"

@interface StarMapController : NSWindowController <NSTabViewDelegate, NSTableViewDataSource, StarMapViewDelegate, NSDrawerDelegate>
{
    NuTurn* turn;
    NSScrollView* mapScroll;
    StarMapView* starMap;
    
    NSButton* planetToolBarButton;
    NSButton* shipToolBarButton;
    NSButton* stormToolBarButton;
    NSButton* connectionToolBarButton;
    NSButton* visibilityToolBarButton;
    NSButton* minefieldToolBarButton;
    NSButton* commandToolBarButton;
    
    // Color Scheme Selection
    NSWindow* colorSchemeWindow;
    NSTableView* colorSchemeTableView;
    NSPopUpButton* loadScheme;
    NSMutableArray* colorSchemes;
    NuColorScheme* activeScheme;
    
    NSPopover* muxPopover;
    MapMuxPopoverController* mmpc;
    
    NSDrawer* commandDrawer;
}

@property (nonatomic, retain) NuTurn* turn;

@property (assign) IBOutlet NSScrollView* mapScroll;
@property (assign) IBOutlet NSButton* planetToolBarButton;
@property (assign) IBOutlet NSButton* shipToolBarButton;
@property (assign) IBOutlet NSButton* stormToolBarButton;
@property (assign) IBOutlet NSButton* connectionToolBarButton;
@property (assign) IBOutlet NSButton* visibilityToolBarButton;
@property (assign) IBOutlet NSButton* minefieldToolBarButton;
@property (assign) IBOutlet NSButton* commandToolBarButton;

@property (assign) IBOutlet NSWindow* colorSchemeWindow;
@property (assign) IBOutlet NSTableView* colorSchemeTableView;
@property (assign) IBOutlet NSPopUpButton* loadScheme;
@property (nonatomic, retain) NSArray* colorSchemes;
@property (nonatomic, retain) NuColorScheme* activeScheme;

@property (nonatomic, assign) IBOutlet NSPopover* muxPopover;
@property (nonatomic, assign) IBOutlet MapMuxPopoverController* mmpc;

@property (nonatomic, assign) IBOutlet NSDrawer* commandDrawer;

- (void)initStarMapView;
- (void)initToolBar;

- (IBAction)colorToolBarClicked:(id)sender;
- (IBAction)planetToolBarClicked:(id)sender;
- (IBAction)shipToolBarClicked:(id)sender;
- (IBAction)stormToolBarClicked:(id)sender;
- (IBAction)connectionToolBarClicked:(id)sender;
- (IBAction)visibilityToolBarClicked:(id)sender;
- (IBAction)minefieldToolBarClicked:(id)sender;
- (IBAction)commandCenterClicked:(id)sender;

- (IBAction)saveColorScheme:(id)sender;

// Command Center
- (IBAction)communicationCenterClicked:(id)sender;
- (IBAction)scoreClicked:(id)sender;

- (IBAction)loadColorScheme:(id)sender;
- (void)initColorScheme;
- (IBAction)showFleetManifest:(id)sender;

- (IBAction)ppvr:(id)sender;

- (IBAction)showTurnWarnings:(id)sender;

- (void)scrollToPlanet:(NuPlanet*)planet;
- (void)scrollToShip:(NuShip*)ship;

@end
