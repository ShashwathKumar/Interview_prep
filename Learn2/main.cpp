/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Shashwath
 *
 * Created on November 17, 2015, 10:19 PM
 */

//#include "Ops.h"
#include <iostream>
using namespace std;
#define ANCHOR_1800 3
int DAYS_IN_MONTH[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

void calc_day()
{
    int year, month, date, odd_days;
    int i;
    cout<<"Please enter year, month and date : ";
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

int main()
{
    int choice=0;
    cout<<"\n Enter the opn u wud like to perform :";
    cout<<"\n 1: Calculate day given a date : ";
    cin>>choice;
    if(choice == 1) calc_day();
    return 0;
}