/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 3, 2021, 1:24 PM
 * Purpose: Store company sale of each division
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

struct Sales {
    int fstQtr;
    int sndQtr;
    int thdQtr;
    int frthQtr;
    float ttlSale;
    float aQtrSale;
};

int main(int argc, char** argv) {

    //creating structure for north branch
    Sales north;
    cout << "North" << endl;
    cout << "Enter first-quarter sales:" << endl;

    cout << "Enter second-quarter sales:" << endl;

    cout << "Enter third-quarter sales:" << endl;

    cout << "Enter fourth-quarter sales:" << endl;

    cin >> north.fstQtr >> north.sndQtr >> north.thdQtr >> north.frthQtr;

    north.ttlSale = (north.fstQtr + north.sndQtr + north.thdQtr + north.frthQtr);
    north.aQtrSale = north.ttlSale / 4.0;
    cout << fixed << setprecision(2);
    cout << "Total Annual sales:$" << north.ttlSale << endl;
    cout << "Average Quarterly Sales:$" << north.aQtrSale << endl;


    //creating structure for west branch
    Sales west;
    cout << "West" << endl;
    cout << "Enter first-quarter sales:" << endl;

    cout << "Enter second-quarter sales:" << endl;

    cout << "Enter third-quarter sales:" << endl;

    cout << "Enter fourth-quarter sales:" << endl;

    cin >> west.fstQtr >> west.sndQtr >> west.thdQtr >> west.frthQtr;

    west.ttlSale = (west.fstQtr + west.sndQtr + west.thdQtr + west.frthQtr);
    west.aQtrSale = west.ttlSale / 4.0;
    cout << fixed << setprecision(2);
    cout << "Total Annual sales:$" << west.ttlSale << endl;
    cout << "Average Quarterly Sales:$" << west.aQtrSale << endl;

    //creating structure for east branch
    Sales east;
    cout << "East" << endl;
    cout << "Enter first-quarter sales:" << endl;

    cout << "Enter second-quarter sales:" << endl;

    cout << "Enter third-quarter sales:" << endl;

    cout << "Enter fourth-quarter sales:" << endl;

    cin >> east.fstQtr >> east.sndQtr >> east.thdQtr >> east.frthQtr;

    east.ttlSale = (east.fstQtr + east.sndQtr + east.thdQtr + east.frthQtr);
    east.aQtrSale = east.ttlSale / 4.0;
    cout << fixed << setprecision(2);
    cout << "Total Annual sales:$" << east.ttlSale << endl;
    cout << "Average Quarterly Sales:$" << east.aQtrSale << endl;


    //creating structure for south branch
    Sales south;
    cout << "South" << endl;
    cout << "Enter first-quarter sales:" << endl;

    cout << "Enter second-quarter sales:" << endl;

    cout << "Enter third-quarter sales:" << endl;

    cout << "Enter fourth-quarter sales:" << endl;

    cin >> south.fstQtr >> south.sndQtr >> south.thdQtr >> south.frthQtr;

    south.ttlSale = (south.fstQtr + south.sndQtr + south.thdQtr + south.frthQtr);
    south.aQtrSale = south.ttlSale / 4.0;
    cout << fixed << setprecision(2);
    cout << "Total Annual sales:$" << south.ttlSale << endl;
    cout << "Average Quarterly Sales:$" << south.aQtrSale << endl;




    return 0;
}

