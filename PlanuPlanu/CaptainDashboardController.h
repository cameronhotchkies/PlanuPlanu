//
//  CaptainDashboardController.h
//  PlanuPlanu
//
//  Created by Cameron Hotchkies on 12/22/11.
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

@interface CaptainDashboardController : NSWindowController <NuGameListRequestDelegate, NSTableViewDelegate, NSTableViewDataSource, NuTurnRequestDelegate>
{
    @private
    NSTextField* loginMessage;
    NSTableView* gameList;
    NSArray *games;
    NSProgressIndicator* progress;
}

@property (assign) IBOutlet NSTextField* loginMessage;
@property (assign) IBOutlet NSTableView* gameList;
@property (nonatomic, retain) NSArray* games;
@property (assign) IBOutlet NSProgressIndicator* progress;

- (IBAction)loadGame:(id)sender;
- (IBAction)loadFile:(id)sender;

@end
