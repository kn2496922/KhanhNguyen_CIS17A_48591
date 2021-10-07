/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 3, 2021, 1:24 PM
 * Purpose:  weather stats
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
    int ttlRain;
    int lowTmp;
    int highTmp;
    float avgTmp;
};

int main(int argc, char** argv) {

    //intitializing variables
    int const maxMonth = 12;
    WeatherStats month[maxMonth];
    
    for(int i = 0; i < maxMonth; i++)
    {
        cin >> month[i].month;
        cin >> month[i].ttlRain;
        
        
        cin >> month[i].lowTmp;
        //input check
        while(month[i].lowTmp > 140 || month[i].lowTmp < -100)
        {
            cout << "Invalid input!" << endl;
            cin >> month[i].lowTmp;
        }
        
        cin >> month[i].highTmp;
        //input check
        while(month[i].highTmp > 140 || month[i].highTmp < -100)
        {
            cout << "Invalid input!" << endl;
            cin >> month[i].highTmp;
        }
        
        month[i].avgTmp = (month[i].highTmp + month[i].lowTmp)/2;
    }
    
    //Calculating average rainfall
    
    float sumRain{}; // total rainfall throughout the year
    for(int i = 0; i < maxMonth; i++)
        sumRain += month[i].ttlRain;
    
    float avgRain = sumRain/ 12.0;
    
    //Finding the lowest temp and its month
    int lowPos{};
    int lowest = 140; 
    
    for(int i = 0; i < maxMonth; i++)
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
    
    for(int i = 0; i < maxMonth; i++)
    {
        if(highest < month[i].highTmp)
        {
            highest = month[i].highTmp;
            highPos = i;
        }
    }
    
    //finding the average degree of the year
    
     float sumATmp{};
   
    for(int i = 0; i < maxMonth; i++)
    {
        sumATmp+= month[i].avgTmp;
    }
    
    float avgTemp = sumATmp/12;
    
    cout << "Average Rainfall " <<fixed <<setprecision(1) << avgRain << " inches/month"
            << endl;
    cout << "Lowest  Temperature "<< month[lowPos].month << "  " << lowest <<
            " Degrees Fahrenheit" <<endl;
    cout << "Highest Temperature "<< month[highPos].month << "  " << month[highPos].highTmp <<
            " Degrees Fahrenheit" <<endl;
    cout << "Average Temperature for the year " << setprecision(0) << avgTemp << " Degrees Fahrenheit" <<endl;
    
    return 0;
}

