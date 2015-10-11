//
//  ExerciseDataManager.m
//  StayHealthy
//
//  Created by Robert Saunders on 2015-08-15.
//  Copyright (c) 2015 Mark Saunders. All rights reserved.
//

#import "ExerciseDataManager.h"

@implementation ExerciseDataManager 

- (id)init {
    if (self)
    {
        AppDelegate *appDelegate = APPDELEGATE;
        self.appContext = appDelegate.managedObjectContext;
    }
    return self;
}

#pragma mark - Data Manager Protocol Methods

- (void)saveItem:(id)object {
    @synchronized(self.appContext) {
        if (object != nil) {
            
            Exercise *exercise = [NSEntityDescription insertNewObjectForEntityForName:[self returnEntityName] inManagedObjectContext:self.appContext];
            
            SHExercise *SHexercise = (SHExercise *)object;
    
            [SHexercise map:exercise];
            
            NSError *error = nil;
                
            if (![exercise.managedObjectContext save:&error]) {
                LogDataError(@"Unable to save exercise to managed object context. --> saveItem @ ExerciseDataManager");
                LogDataError(@"%@, %@", error, error.localizedDescription);
            }
            else {
                LogDataSuccess(@"Exercise was saved successfully. --> saveItem @ ExerciseDataManager");
            }
        }
    }
}

- (void)updateItem:(id)object {
    NSFetchRequest *fetchRequest = [[NSFetchRequest alloc] initWithEntityName:[self returnEntityName]];
    
    SHExercise *SHexercise = (SHExercise *)object;
    
    NSError *requestError = nil;
    
    if (SHexercise != nil)
    {
        [fetchRequest setPredicate:[NSPredicate predicateWithFormat: @"exerciseIdentifier = %@", SHexercise.exerciseIdentifier]];
        
        NSArray *exercises = [_appContext executeFetchRequest:fetchRequest error:&requestError];
        
        for (Exercise *exercise in exercises) {
            
            [SHexercise map:exercise];
            
            NSError *error = nil;
                    
            if (![exercise.managedObjectContext save:&error]) {
            
                LogDataError(@"Unable to update exercise to managed object context. --> updateItem @ ExerciseDataManager");
                LogDataError(@"%@, %@", error, error.localizedDescription);
            }
            else {
                LogDataSuccess(@"Exercise has been updated successfully. --> updateItem @ ExerciseDataManager");
            }
        }
    }
}

- (id)fetchItemByIdentifier:(NSString *)objectIdentifier {
    if (objectIdentifier != nil) {
        
        NSFetchRequest *fetchRequest = [[NSFetchRequest alloc] initWithEntityName:[self returnEntityName]];
    
        NSError *requestError = nil;
        
        [fetchRequest setPredicate:[NSPredicate predicateWithFormat:@"exerciseIdentifier = %@", objectIdentifier]];
        
        NSArray *exercises = [_appContext executeFetchRequest:fetchRequest error:&requestError];
        
        if ([exercises count] > 0)
            LogDataSuccess(@"An exercise has been found in the database with the identifier: %@ --> fetchItemByIdentifier @ ExerciseManager", objectIdentifier);
            return [exercises objectAtIndex:0];
        }
    LogDataError(@"Could not find any exercise with the identifier: %@ --> fetchItemByIdentifier @ ExerciseManager", objectIdentifier);
    return nil;
}

- (NSString *)returnEntityName {
    return EXERCISE_ENTITY_NAME;
}

#pragma mark - Helper Methods

- (NSFetchRequest *) getRecentlyViewedFetchRequest
{
    NSFetchRequest *fetchRequest = [[NSFetchRequest alloc] initWithEntityName:[self returnEntityName]];
    NSSortDescriptor *sortByRecentlyViewed = [NSSortDescriptor sortDescriptorWithKey:@"lastViewed" ascending:NO];
    fetchRequest.sortDescriptors = [[NSArray alloc] initWithObjects:sortByRecentlyViewed, nil];
    return fetchRequest;
}



@end