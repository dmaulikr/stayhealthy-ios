//
//  advancedOptionsSelect.m
//  StayHealthy
//
//  Created by Robert Saunders on 2015-03-21.
//  Copyright (c) 2015 Mark Saunders. All rights reserved.
//

#import "advancedOptionsSelect.h"
#import "FlatUIKit.h"

@implementation advancedOptionsSelect

-(void)viewDidLoad {
      NSDictionary *attrDict = [NSDictionary dictionaryWithObject: [UIFont fontWithName:@"Avenir" size:17.0] forKey:NSFontAttributeName];
    [[UIBarButtonItem appearance] setTitleTextAttributes: attrDict
                                                forState: UIControlStateDisabled];
    [[UIBarButtonItem appearance] setTitleTextAttributes: attrDict
                                                forState: UIControlStateNormal];
}

-(void)viewWillAppear:(BOOL)animated {
    self.tableView.tableFooterView = [[UIView alloc] initWithFrame:CGRectZero];
    self.title = self.titleText;
    self.navigationController.navigationBarHidden = NO;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{

    return [_arrayForTableView count];;
}


//Design and fill the tableview cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
            //Define the identifier.
        static NSString *muscleItem = @"cell";
        
        UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:muscleItem];
        
        if (cell == nil) {
            cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:muscleItem];
        }
    
    cell.textLabel.text = [_arrayForTableView objectAtIndex:indexPath.row];
    
    //Stlying the cells.
    cell.textLabel.font = [UIFont fontWithName:@"Avenir" size:17];
    cell.textLabel.textColor = [UIColor peterRiverColor];
    
    //Then the background color view.
    UIView *bgColorView = [[UIView alloc] init];
    bgColorView.backgroundColor = [UIColor cloudsColor];
    bgColorView.layer.masksToBounds = YES;
    [cell setSelectedBackgroundView:bgColorView];
    
    return cell;
}

//Controls what happens when a user presses a cell, i.e. a SIAlertview pops up.
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{

    if (self.isExerciseType == YES) {
        UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
        
        if (cell.accessoryType == UITableViewCellAccessoryCheckmark) {
            cell.accessoryType = UITableViewCellAccessoryNone;
        }
        else {
            cell.accessoryType = UITableViewCellAccessoryCheckmark;
        }
    }
    else {
        [self dismissViewControllerAnimated:YES completion:nil];
        
        [self.delegate done:[_arrayForTableView objectAtIndex:indexPath.row] num:&(_num)];
    }
    
    

    //Then deselect the row once complete touch/select.
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

- (IBAction)donePressed:(id)sender {
    if (self.isExerciseType == YES) {
        NSArray *selectedValues = [self.tableView indexPathsForSelectedRows];
        NSLog(@"%@",selectedValues);
    }
}

- (IBAction)cancelPressed:(id)sender {
    [self dismissViewControllerAnimated:YES completion:nil];

}
@end