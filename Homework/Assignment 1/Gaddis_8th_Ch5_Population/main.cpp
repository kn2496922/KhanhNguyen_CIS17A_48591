/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Purpose: Determining the population growth of organisms with given numbers
 * Created on September 6, 2021, 5:16 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) {
    //Asking the user input for starting pop, growth% and days of the process.
    
    float strtPop {}; //Starting population
    int dGrPcnt {}; // daily growth percent
    int days {}; //Days of the experiment 
    float endPop {}; //Population at the end of the day
    
    do{
        cout << "Enter the starting population of the organisms (Can't be less than 2): ";
        cin >> strtPop;
    }while(strtPop < 2);
    
    do{
        cout << "Enter the daily growth %: ";
        cin >> dGrPcnt;
    }while(dGrPcnt < 0);
     
    do{
        cout << "Enter the number of days the experiment take place (can't be less than 1): ";
        cin >> days;
    }while (days < 1);
    
    
    cout << "The starting population is: " << strtPop << endl;
    //Using for loop to simulate the growth of the population after given days
    for(int i = 1; i <days ; i++)
    {
        endPop = strtPop + strtPop * (dGrPcnt / 100.0);
        //There can't be point something amount of organism (like 0.5 a dog) so 
        //setpricision is set to 0 so it only shows the whole number
        cout << "The population after " << i << " day(s) is: " << fixed << setprecision(0) << endPop << endl;
        strtPop = endPop;
    }
    
    return 0;
}

