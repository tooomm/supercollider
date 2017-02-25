//
//  iscsynthAppDelegate.h
//  iscsynth
//
//  Created by Axel Balley on 20/10/08.
//  Copyright __MyCompanyName__ 2008. All rights reserved.
//
#ifndef ISCSYNTHAPPDELEGATE_H
#define ISCSYNTHAPPDELEGATE_H

#import <UIKit/UIKit.h>

@interface iscsynthAppDelegate : NSObject <UIApplicationDelegate> {
	UIWindow *window;
	IBOutlet UITabBarController *tabBarController;
	IBOutlet UITableViewController *tableViewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@end

#endif
