/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 6, 2021, 3:59 PM
 * Purpose: Convert USD to YEN and EUR
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Declare global constants yen and euro per dollar
const float yenPerDollar = 68.93;
const float eurPerDollar = 0.74;

/*
 * 
 */
int main(int argc, char** argv) {
    
    float usd {};
    //Asking the user input
    cout << "Enter the amount of USD you want to convert to Yen and Euro: ";
    cin >> usd;
    
    //Converting usd to yen
    float yen = usd * yenPerDollar;
    
    //Converting usd to euro
    float eur = usd * eurPerDollar;
    
    //Use fixed and set precision(2) to display 2 decimal points 
    cout << "It's equaled to " << fixed << setprecision(2) << yen << " YEN and " 
             << eur << " EUR." << endl;
    
    
    

    return 0;
}

