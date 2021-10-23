/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 21, 2021, 1:54 PM
 * 
 */

//public libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath> //log10

//user libraries
#include "Banking.h"

using namespace std;

//functions
bool inValid(string);
Banking *bankAcc(string);
void prntAcc(Banking *);
void destroy(Banking *);


int main(int argc, char** argv) {
    //random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    string accNumb;
    
    bool inVal = false;
    do
    {
        cout << "Enter Account Number(5 digits):";
        getline(cin, accNumb);
        inVal = inValid(accNumb);
        if(inVal == false)
            cout << "Invalid Account Number." << endl;
    }while(inVal == false);
            
    Banking *prob1 = bankAcc(accNumb);
    
    prntAcc(prob1);
    
    destroy(prob1);
    return 0;
}

//account number input validation
bool inValid(string accNumb)
{
    
    if(accNumb.length() == 5 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

//creating the banking structure
Banking *bankAcc(string accNumb)
{
    Banking *a = new Banking;
    a->accNumb = accNumb;
    a->balance = 100 + rand()%200;
    a->newBlnc = a->balance;
    cout << "Enter the name: ";
    getline(cin, a->name);
    cout << "Enter the address: ";
    getline(cin, a->address);
    
    cout << "Balance at the beginning of the month: " << a->balance << endl;
    cout << "Enter the number of checks you wrote: ";
    cin >> a->wSize;
    a->wthdrwl = new int[a->wSize];
    
    int temp;
    
    for(int i = 0; i < a->wSize; i++)
    {
        cout << "Enter withdrawal #" << i + 1 << ":";
        cin >> temp;
        a->wthdrwl[i] = temp;
        a->newBlnc -= a->wthdrwl[i];
    }
    
    cout << "Enter the number of deposits: ";
    cin >> a->dSize;
    a->deposit = new int[a->dSize];
    
    for(int i = 0; i < a->dSize; i++)
    {
        cout << "Enter deposit #" << i + 1 << ":";
        cin >> temp;
        a->deposit[i] = temp;
        a->newBlnc += a->deposit[i];
    }
    
    cin.ignore();
    if(a->newBlnc >=0)
        a->newBlnc = a->newBlnc;
    else
    {
        cout << "You overdrawn. $25 has been deducted from your balance. " << endl;
        a->newBlnc -= 25;
    }
    return a;
}

//printing the banking structure
void prntAcc(Banking *prob1)
{
    cout << "__________________________________________"<<endl;
    cout << "Acount number: " << prob1->accNumb <<endl;
    cout << "Name: " << prob1->name << endl;
    cout << "Address: " << prob1->address << endl;
    cout << "Balance at the beginning of the month: $" << prob1->balance << endl;
    cout << "Current balance: $" << prob1->newBlnc << endl;
    cout << "__________________________________________"<<endl;
}

//delete the banking struct
void destroy(Banking *prob1)
{
    delete []prob1->deposit;
    delete []prob1->wthdrwl;
    delete prob1;
}