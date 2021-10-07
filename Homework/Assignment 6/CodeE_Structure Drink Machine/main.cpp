/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 3, 2021, 1:24 PM
 * Purpose:Drink machine simulator
 */


#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

struct DrinkMachine
{
    string name;
    float price;
    int qty; //quantities of drink left
    float smPrice; //sum of the money made from this particular drink
};

/*
 * 
 */
int main(int argc, char** argv) {

    int const maxDrink = 5;
    DrinkMachine drink[maxDrink];
    drink[0] = {"Cola", 75, 20};
    drink[1] = {"Root Beer", 75, 20};
    drink[2] = {"Lemon-Lime", 75, 20};
    drink[3] = {"Grape Soda", 80, 20};
    drink[4] = {"Cream Soda", 80, 20};
    
    string menu;
    
    
    do
    {
        for(int i = 0; i < maxDrink; i++)
        {
            cout.width(11);
            cout  << left << drink[i].name;
            cout.width(4);
            cout << left << drink[i].price;        
            cout <<  drink[i].qty  << endl;
        }
        cout << "Quit" << endl;
        //input the item name
        getline(cin, menu);
        //loop to compare the 1st element of each structure array if it's the same
        //as item name and returns the position if true
        int itemPos{-1};
        
        for(int i = 0; i < maxDrink; i++)
        {
            if(menu.compare(drink[i].name) == 0)
            {
                itemPos = i;
            }
        }
        int change{};
        //Calculation
        if(itemPos != -1)
        {
            cin >> change;
            change -= drink[itemPos].price;
            drink[itemPos].qty -= 1;
            drink[itemPos].smPrice = (20 - drink[itemPos].qty) * 
                    drink[itemPos].price;
            cout << change << endl; 
            cin.ignore();
        }
           
            
        
        
    //loop until the 1st letter of menu is Q
    }while(tolower(menu[0]) != 'q');
    
    int sum{};
    for(int i = 0; i < maxDrink ; i++)
    {
        sum += drink[i].smPrice;
    }
    cout << sum;
    
    return 0;
}

