//
//  NuTurn.m
//  PlanuPlanu
//
//  Created by Cameron Hotchkies on 12/23/11.
//  Copyright 2011 Roboboogie Studios. All rights reserved.
//

#import "NuTurn.h"
#import "NuPlanet.h"
#import "NuStarbase.h"

@implementation NuTurn

@synthesize planetList, gameSettings, player;

- (id)init
{
    self = [super init];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

-(BOOL)loadFromDict:(NSDictionary*)input
{
    NSDictionary* settingsDict = [input objectForKey:@"settings"];
    
    NuGameSettings* settings = [[[NuGameSettings alloc] init] autorelease];
    
    [settings loadFromDict:settingsDict];
    self.gameSettings = settings;
    
    NSMutableArray* pl = [NSMutableArray array];
    
    for (NSDictionary* planetDict in [input objectForKey:@"planets"])
    {
        NuPlanet* planet = [[NuPlanet alloc] init];
        
        [planet loadFromDict:planetDict];
        
        [pl addObject:planet];
        
        [planet release];
    }
    
    self.planetList = pl;
    
    self.player = [[[NuPlayer alloc] init] autorelease];
    [self.player loadFromDict:[input objectForKey:@"player"]];
    
    NSArray* starbases = [input objectForKey:@"starbases"];
    
    for (NSDictionary* sbDict in starbases)
    {
        NuStarbase* sb = [[[NuStarbase alloc] init] autorelease];
        
        [sb loadFromDict:sbDict];
        
        for (NuPlanet* sbp in self.planetList)
        {
            if (sb.planetId == sbp.planetId)
            {
                sbp.starbase = sb;
            }
        }
    }
    
    return NO;
}

@end