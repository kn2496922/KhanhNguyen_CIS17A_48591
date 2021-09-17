/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:
 * Author:
 * Date:
 * Purpose:
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    float value1, value2, value3, value4;
    
    cin >> value1 >> value2 >> value3 >> value4;
    
    cout << "        " << value1 << "       " << fixed << setprecision(1) << value1 << "      " << setprecision(2) << value1 << endl;
    cout << "        " << setprecision(0) << value2 << "       "  << setprecision(1) << value2 << "      " << setprecision(2) << value2 << endl;
    cout << "        " << setprecision(0) << value3 << "       "  << setprecision(1) << value3 << "      " << setprecision(2) << value3 << endl;
    cout << "        " << setprecision(0) << value4 << "       "  << setprecision(1) << value4 << "      " << setprecision(2) << value4;
    
    //Exit stage left
    return 0;
}