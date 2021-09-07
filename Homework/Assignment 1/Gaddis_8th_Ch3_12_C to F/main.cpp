/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 6, 2021, 3:37 PM
 * Purpose: Convert Celsius to Fahrenheit
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Declare Celsius
    int cel {};
    
    cout << "Enter the Celsius you want to convert to F: ";
    cin >> cel;
    
    //Calculation to convert Celsius to Fahrenheit
    float fah = (9/5.0) * cel + 32;
    
    cout << "It's equaled to " << fah << "F" << endl;

    return 0;
}

