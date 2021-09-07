/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Purpose: Displaying the fahrenheit to celsius table using function
 * Created on September 6, 2021, 6:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


float celsius (int&);
/*
 * 
 */
int main(int argc, char** argv) {

    //Using for loop to display the conversion of 0-20F to C
    for (int i = 0; i < 21; i++)
    {
        float cel = celsius(i);
        cout << i << "F is equal to " << fixed << setprecision(2) << cel << "C" << endl;
        
    }
    
    return 0;
}

/*
 * Function to convert F to C
 * Parameter(s): fah
 */
float celsius (int& fah)
{
    return (5/9.0) * (fah - 32);
}

