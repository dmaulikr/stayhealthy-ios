//
//  CustomExerciseDataManager.h
//  StayHealthy
//
//  Created by Robert Saunders on 2016-04-19.
//  Copyright © 2016 Robert Saunders. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CustomExercise.h"
#import "SHCustomExercise.h"
#import "SHCustomExercise+CustomExercise.h"
#import "DataManagerProtocol.h"

@interface CustomExerciseDataManager : NSObject <DataManagerProtocol>

//Define the app context for the data manager to call to.
@property (nonatomic, strong) NSManagedObjectContext  *appContext;

//Fetches the recently viewed custom exercise records from persistent store.
- (id)fetchRecentlyViewedExercises;

//Fetches all of the liked custom workouts.
- (id)fetchAllLikedExercises;

//Fetches all of the liked strength custom exercise records.
- (id)fetchLikedStrengthExercises;

//Fetches all of the liked stretching custom exercise records.
- (id)fetchLikedStretchingExercises;

//Fetches all of the liked warmup custom exercise records.
- (id)fetchLikedWarmupExercises;

//Fetches a custom exercise record given the objects identifier and the exercise type.
- (id)fetchItemByIdentifierAndExerciseType:(NSString *)objectIdentifier exerciseType:(NSString*)exerciseType;

//Deletes an existing object with a passed object identifier and custom exercise type in the persistent store.
- (void)deleteItemByIdentifierAndExerciseType:(NSString *)objectIdentifier exerciseType:(NSString*)exerciseType;

@end
