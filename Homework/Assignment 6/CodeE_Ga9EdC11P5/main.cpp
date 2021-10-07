/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 3, 2021, 1:24 PM
 * Purpose: Weather stats Enumerated
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//creating structure
struct WeatherStats
{
    string month;
    float ttlRain;
    int highTmp;
    int lowTmp;
    float avgTmp;
};

int main(int argc, char** argv) {

    //intitializing variables
    int const maxMonth = 12;
    WeatherStats month[maxMonth];
    
    enum Month {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
                    SEPTEMBER, OCTOBER, NOVEMBER,DECEMBER};
    
    for(int i = JANUARY; i < JULY; i++)
    {
        cout << "Enter the total rainfall for the month:" <<endl;
        cin >> month[i].ttlRain;
        
        cout << "Enter the high temp:" << endl;
        cin >> month[i].highTmp;
        //input check
        while(month[i].highTmp > 140 || month[i].highTmp < -100)
        {
            cout << "Invalid input!" << endl;
            cin >> month[i].highTmp;
        }
        
        cout << "Enter the low temp:" << endl;
        cin >> month[i].lowTmp;
        //input check
        while(month[i].lowTmp > 140 || month[i].lowTmp < -100)
        {
            cout << "Invalid input!" << endl;
            cin >> month[i].lowTmp;
        }
        
        
        
        month[i].avgTmp = (month[i].highTmp + month[i].lowTmp)/2;
    }
    
    //Calculating average rainfall
    
    float sumRain{}; // total rainfall throughout the year
    for(int i = JANUARY; i < JULY; i++)
        sumRain += month[i].ttlRain;
    
    float avgRain = sumRain/ 6.0;
    
    //Finding the lowest temp and its month
    int lowPos{};
    int lowest = 140; 
    
    for(int i = JANUARY; i < JULY; i++)
    {
        if(month[i].lowTmp < lowest)
        {
            lowest = month[i].lowTmp;
            lowPos = i;
        }
    }
   
    
    //Finding the highest temp and its month
    int highPos{};
    int highest = -100; 
    
    for(int i = JANUARY; i < JULY; i++)
    {
        if(highest < month[i].highTmp)
        {
            highest = month[i].highTmp;
            highPos = i;
        }
    }
    
    //finding the average degree of the year
    
     float sumATmp{};
   
    for(int i = JANUARY; i < JULY; i++)
    {
        sumATmp = sumATmp + month[i].lowTmp + month[i].highTmp;
    }
    
    float avgTemp = sumATmp/12.0;
    
    cout << "Average monthly rainfall:" << avgRain << endl;
    cout << "High Temp: "<< month[highPos].highTmp << endl;
    cout << "Low Temp:" << month[lowPos].lowTmp << endl;
    cout << "Average Temp: " << setprecision(1) << avgTemp << endl;
    
    
    
    return 0;
}
