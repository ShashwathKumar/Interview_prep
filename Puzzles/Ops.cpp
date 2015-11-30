/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ops.h"
#include <iostream>
#include<math.h>
using namespace std;
#define ANCHOR_1800 3
int DAYS_IN_MONTH[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

void calc_day()
{
    int year, month, date, odd_days;
    int i;
    cout<<"\n Please enter year, month and date : ";
    cin>>year>>month>>date;
    
    year -= 1800; //using anchor year 1800
    odd_days = ANCHOR_1800;
    cout<<"\n year : "<<year<<" odd_days : "<<odd_days;
    
    if(year > 0){
        for(i=1; i<=year; ++i)
        {
            if(i%400 == 0);
            else if(i%4 == 0 && i!=4) {odd_days += 2;} //if current year is leap year don't add extra months, its taken care in months
            else {odd_days++;}
            cout<<"\n odd days : "<<odd_days<<", i : "<<i;
        }
    }
    else {
         for(i=1; i-1>year; --i)
        {
            if(i%400 == 0);
            else if(i%4 == 0 & i!=4) odd_days -= 2;
            else odd_days--;
            cout<<"\n odd days : "<<odd_days<<", i : "<<i;
        }
    }
    
    for(i=0; i<month-1; i++)
    {
        odd_days += DAYS_IN_MONTH[i];
        if(i==1 && year%4 == 0) odd_days++; //for leap year
        cout<<"\n odd_days after month : "<<odd_days;
    }
    
    odd_days += date - 1;//Anchor date is 1 so need to subtract by one
    odd_days %= 7;
    if(odd_days<0) odd_days += 7;
    cout<<"\n odd_days after modulus : "<<odd_days;
    
    switch(odd_days)
    {
        case 0: cout<<"\n Sunday"; break;
        case 1: cout<<"\n Monday"; break;
        case 2: cout<<"\n Tuesday"; break;
        case 3: cout<<"\n Wednesday"; break;
        case 4: cout<<"\n Thursday"; break;
        case 5: cout<<"\n Friday"; break;
        case 6: cout<<"\n Saturday"; break;
        default: cout<<"\n Something went wrong..!!"; break;
    }
}

//-------------------------------------------------------------------------------------

int dropCount = 0, FloorsNum, breaking_point, interval, startingFloor;

bool drop(int floor){
    dropCount++;
    return floor >= breaking_point;
}

void collectValues(){
    cout<<"\n Enter the number of floors and breaking point : ";
    cin>>FloorsNum>>breaking_point;
}

void calcStart(){
    //x(x+1)/2 = FloorsNum;
    interval = ceil((-1 + sqrt(1 + 8*FloorsNum))/2); //this is just the formula to find square root
    startingFloor = interval;
}

void egg_drop(){
    cout<<"\n Egg Drop \n";
    
    collectValues();
    calcStart();
    int floor = startingFloor;
    int previousFloor = 0;
    
    while(!drop(floor)){
        interval--;
        previousFloor = floor;
        floor += interval;
    }
    
    floor = previousFloor + 1;
    //cout<<"\n dropCount now : "<<dropCount<<"\n";
    
    while((floor < previousFloor + interval) && !drop(floor)) {
        //cout<<"Floor : "<<floor<<" dropCount : "<<dropCount<<"\n";
        floor++;
    }
    //cout<<"\n dropCount now : "<<dropCount<<"\n";
    //if(floor == previousFloor + interval) 
    
    cout<<"\n Starting floor : "<<startingFloor;
    cout<<"\n Total drops : "<<dropCount;
    cout<<"\n Breaking point : "<<floor;
}

//-------------------------------------------------------------------------------------

int big_jug, small_jug, qty_wanted;
int qty_big_jug, qty_small_jug, step=0;

void get_inputs(){
    cout<<"\n Please enter following values : "<<endl;
    cout<<"\n big_jug, small_jug, qty_wanted : ";
    cin>>big_jug>>small_jug>>qty_wanted;
}

void fill_big_jug(){
    cout<<"\n"<<++step<<". Fill the "<<big_jug<<" litre jug";
    qty_big_jug = big_jug;
    
    cout<<"\n    "<<big_jug<<" litre jug -> "<<qty_big_jug<<" and "<<small_jug<<" litre jug -> "<<qty_small_jug<<"\n";
}

void big_to_small(){
   
    if(qty_big_jug + qty_small_jug < small_jug ){
        cout<<"\n"<<++step<<". Transfer the contents in "<<big_jug<<" litre jug to "<<small_jug<<" litre jug";
        qty_small_jug = qty_big_jug;
        qty_big_jug = 0;
    }else{
        cout<<"\n"<<++step<<". Transfer the contents in "<<big_jug<<" litre jug to "<<small_jug<<" litre jug till it fills";
        qty_big_jug -= (small_jug - qty_small_jug);
        qty_small_jug = small_jug;
    }
    
    cout<<"\n    "<<big_jug<<" litre jug -> "<<qty_big_jug<<" and "<<small_jug<<" litre jug -> "<<qty_small_jug<<"\n";    
}

void clear_small(){
    cout<<"\n"<<++step<<". Empty the "<<small_jug<<" litre jug";
    qty_small_jug = 0;
    
    cout<<"\n    "<<big_jug<<" litre jug -> "<<qty_big_jug<<" and "<<small_jug<<" litre jug -> "<<qty_small_jug<<"\n";    
}

void two_jugs(){
    cout<<"\n Two Jug problem \n";
    get_inputs();
    int catch_qty = qty_wanted;
    int twister = 0;
    if(qty_wanted > big_jug) catch_qty -= big_jug;
    
    while(qty_big_jug != catch_qty){
        if(twister == 0) { 
        twister = 1;
        fill_big_jug(); 
        if(qty_big_jug != catch_qty) big_to_small();
        }
        else { //clear_small(); 
            twister = 0;
            while(qty_small_jug == small_jug || qty_small_jug == 0){ 
                clear_small(); if(qty_big_jug == catch_qty)break; 
                big_to_small(); if(qty_big_jug == catch_qty)break;
            }
        }
        //if(qty_big_jug != catch_qty) big_to_small();
    }
    if(qty_wanted > big_jug)
    {
        clear_small();
        big_to_small();
        fill_big_jug();
        cout<<"\n The wanted quantity is in "<<big_jug<<" litre jug and "<<small_jug<<" litre jug together\n";
        return;
    }
        cout<<"\n The wanted quantity is in "<<big_jug<<" litre jug\n";
}