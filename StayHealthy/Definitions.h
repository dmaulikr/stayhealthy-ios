//
//  Definitions.h
//  StayHealthy
//
//  Created by Robert Saunders on 2015-07-05.
//  Copyright (c) 2015 Mark Saunders. All rights reserved.
//

#ifndef StayHealthy_Definitions_h
#define StayHealthy_Definitions_h

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Application Standards
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define APPNAME                    @"StayHealthy"
//APP NAME
#define WEBSITE                    @"stayhealthyapp.com"
//WEBSITE URL
#define IOSDEVELOPER               @"Robert Saunders"
//IOS DEVELOPER
#define ANDROIDDEVELOPER           @"Cameron Connor"
//ANDROID DEVELOPER
#define APPDELEGATE                (ZalioAppDelegate *)[[UIApplication sharedApplication] delegate]
//APP DELEGATE

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Database Constants
//////////////////////////////////////////////////////////////////////////////////////////////////////

//Database Names
#define STAYHEALTHY_DATABASE       @"StayHealthyDatabase.sqlite"
#define USER_DATABASE              @"UserDatabase.sqlite"

//StayHealthy Database Table Names
#define STRENGTH                   @"StayHealthyStrengthExercises"
#define WARMUP                     @"StayHealthyWarmupExercises"
#define STRETCHING                 @"StayHealthyStretchingExercises"
#define WORKOUTS                   @"StayHealthyWorkouts"


//////////////////////////////////////////////////////////////////////////////////////////////////////
//Screen Sizes
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define IS_IPAD                     (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define IS_IPHONE                   (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_RETINA                   ([[UIScreen mainScreen] scale] >= 2.0)

#define SCREEN_WIDTH                ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT               ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH           (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH           (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE_4_OR_LESS         (IS_IPHONE && SCREEN_MAX_LENGTH < 568.0)
//IS IPHONE 4
#define IS_IPHONE_5                 (IS_IPHONE && SCREEN_MAX_LENGTH == 568.0)
//IS IPHONE 5
#define IS_IPHONE_6                 (IS_IPHONE && SCREEN_MAX_LENGTH == 667.0)
//IS IPHONE 6
#define IS_IPHONE_6P                (IS_IPHONE && SCREEN_MAX_LENGTH == 736.0)
//IS IPHONE 6P

//////////////////////////////////////////////////////////////////////////////////////////////////////
//StayHealthy Colors
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define STAYHEALTHY_BLUE            [UIColor colorWithRed:52.0f/255.2f green:152.0f/255.2f blue:219.0f/255.2f alpha:1]
//STAYHEALTHY BLUE
#define STAYHEALTHY_DARKERBLUE      [UIColor colorWithRed:41.0f/255.2f green:128.0f/255.2f blue:185.0f/255.2f alpha:1]
//STAYHEALTHY BLUE (INTERMEDIATE COLOR)
#define STAYHEALTHY_GREEN           [UIColor colorWithRed:46.0f/255.2f green:204.0f/255.2f blue:113.0f/255.2f alpha:1]
//STAYHEALTHY GREEN (EASY COLOR)
#define STAYHEALTHY_RED             [UIColor colorWithRed:231.0f/255.2f green:76.0f/255.2f blue:60.0f/255.2f alpha:1]
//STAYHEALTHY RED (HARD COLOR)
#define STAYHEALTHY_WHITE           [UIColor colorWithRed:236.0f/255.2f green:240.0f/255.2f blue:241.0f/255.2f alpha:1]
//STAYHEALTHY WHITE

#define STAYHEALTHY_LIGHTGRAYCOLOR  [UIColor lightGrayColor]
#define STAYHEALTHY_DARKGRAYCOLOR   [UIColor darkGrayColor]

//////////////////////////////////////////////////////////////////////////////////////////////////////
//StayHealthy Fonts and Sizes
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define STAYHEALTHY_FONT             [UIFont fontWithName:STAYHEALTHY_FONTNAME size:20.0]
//STAYHEALTHY LOGO FONT

#define STAYHEALTHY_NAVBARFONT       [UIFont fontWithName:regularLightFontName size:20.0]
//FONT FOR NAVIGATION BAR
#define STAYHEALTHY_NAVBARBUTTONFONT [UIFont fontWithName:regularFontName size:17.0]
//FONT FOR NAVIGATION BAR BUTTONS

//TableView Fonts
#define tableViewTitleTextFont       [UIFont fontWithName:regularFontName size:16]
//FONT FOR TABLEVIEW TITLES
#define tableViewUnderTitleTextFont  [UIFont fontWithName:regularLightFontName size:14]
//FONT FOR TABLEVIEW TITLES UNDER TITLE
#define tableViewDetailTextFont      [UIFont fontWithName:regularLightFontName size:16]
//FONT FOR TABLEVIEW DETAIL TEXT
#define tableViewHeaderFont          [UIFont fontWithName:regularLightFontName size:15]

//AlertView Fonts
#define alertViewTitleFont           [UIFont fontWithName:regularLightFontName size:20]
//FONT FOR ALERTVIEW TITLE
#define alertViewButtonFont          [UIFont fontWithName:regularLightFontName size:18]
//FONT FOR ALERTVIEW BUTTON
#define alertViewMessageFont         [UIFont fontWithName:regularLightFontName size:16]
//FONT FOR ALERTVIEW MESSAGE

#define subtleFont                   [UIFont fontWithName:regularLightFontName size:13]
//FONT FOR SUBTLE LABELS (LIKE IN SETTINGS)

//////////////////////////////////////////////////////////////////////////////////////////////////////
//StayHealthy Fonts Names
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define STAYHEALTHY_FONTNAME         @"Arista 2.0"
//STAYHEALTHY LOGO FONT NAME

#define regularFontName              @"Avenir"
//REGULAR FONT
#define regularLightFontName         @"Avenir-Light"
//REGULAR LIGH FONT

//////////////////////////////////////////////////////////////////////////////////////////////////////
//CollectionViewCells
//////////////////////////////////////////////////////////////////////////////////////////////////////

//Exercise Cells
#define SMALLCELL                   CGSizeMake(137.f, 205.f)
#define MEDIUMCELL                  CGSizeMake(160.f, 225.f)
#define LARGECELL                   CGSizeMake(180.f, 244.f)

#define LARGEINSETS                 UIEdgeInsetsMake(18, 18, 18, 18)
#define SMALLINSETS                 UIEdgeInsetsMake(15, 15, 15, 15)

//////////////////////////////////////////////////////////////////////////////////////////////////////
//UITableView
//////////////////////////////////////////////////////////////////////////////////////////////////////

//Exercise Cells
#define UITABLEVIEWCELL_HEIGHT       60


//////////////////////////////////////////////////////////////////////////////////////////////////////
//User Defaults Keys
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define TUTORIAL_MESSAGES           @"userOptionTutorialMessages"
#define LIST_ORIENTATION            @"userPreferredListOrientation"


#endif