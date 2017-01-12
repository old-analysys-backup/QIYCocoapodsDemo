//
//  ViewController.m
//  QIYCocoapodsDemo
//
//  Created by analysys on 2017/1/10.
//  Copyright © 2017年 analysys. All rights reserved.
//

#import "ViewController.h"
#import "EGMonitor.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.title = @"首页";
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    [EGMonitor beginLogPage:NSStringFromClass([self class]) tag:self.title];
}

-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    [EGMonitor endLogPage:NSStringFromClass([self class]) tag:self.title];
}


- (IBAction)eventAction:(id)sender
{
    NSString *eventId = @"1001";
    NSString *desc = @"事件";
    NSDictionary *attributes = @{@"price":@"100.0",@"购买数量":@"2"};
    [EGMonitor event:eventId desc:desc attributes:attributes];
}



@end
