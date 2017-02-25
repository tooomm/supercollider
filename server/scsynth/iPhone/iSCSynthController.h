//
//  iSCSynthController.h
//  iscsynth
//
//  Created by Axel Balley on 21/10/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//
#ifndef ISCSYNTHCONTROLLER_H
#define ISCSYNTHCONTROLLER_H

#import <UIKit/UIKit.h>
#import "FileBrowserViewController.h"

#ifndef SC_WORLD_H
#include "SC_World.h"
#endif
#ifndef SC_HIDDENWORLD_H
#include "SC_HiddenWorld.h"
#endif
#ifndef SC_COREAUDIO_H
#include "SC_CoreAudio.h"
#endif
#ifndef SC_WORLDOPTIONS_H
#include "SC_WorldOptions.h"
#endif

@interface iSCSynthController : NSObject <UITabBarControllerDelegate> {
	WorldOptions options;
	struct World *world;
	NSTimer *timer;

	int lastNodeID;

	IBOutlet UILabel *avgCPULabel;
	IBOutlet UILabel *peakCPULabel;
	IBOutlet UILabel *synthsLabel;
	IBOutlet UILabel *ugensLabel;
	IBOutlet UISwitch *speakerSwitch;
	IBOutlet UIButton *freeAllButton;

	IBOutlet UITextView *logView;

	IBOutlet UIViewController *logViewController;
	IBOutlet FileBrowserViewController *synthdefsViewController;

}

- (IBAction) toggleState:(id)sender;
- (IBAction) toggleSpeaker:(id)sender;
- (IBAction) triggerFreeAll:(id)sender;
- (void) start;
- (void) stop;
- (void) freeAllNodes;
- (void) update:(NSTimer *)timer;
- (void) log:(NSString *)string;
- (void) selectSynthdef:(NSString *)string;

@end
#endif
