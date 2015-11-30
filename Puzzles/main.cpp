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

#include "Ops.h"
#include <iostream>
using namespace std;

int main()
{
    int choice=0;
    cout<<"\n Enter the opn u wud like to perform :";
    cout<<"\n 1: Calculate day given a date : ";
    cout<<"\n 2: Egg drop problem : ";
    cout<<"\n 3: 2 jugs problem : ";
    cin>>choice;
    if(choice == 1) calc_day();
    else if(choice == 2) egg_drop();
    else if (choice == 3) two_jugs();
    return 0;
}