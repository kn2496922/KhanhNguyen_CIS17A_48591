/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 21, 2021, 4:16 PM
 * Purpose: Calculate and write check for employees
 */

//public libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

//user libraries
#include "Check.h"

Check *crteChk(int);
void prntChk(Check *, int);
void engCvrt(int);


using namespace std;


int main(int argc, char** argv) {
    
    int numEmp;
    cout << "Enter the number of employee: ";
    cin >> numEmp;
    cin.ignore();
    
    Check *employee = crteChk(numEmp);
    //printing the check
    prntChk(employee, numEmp);
    
    delete[] employee;
    return 0;
}


//create the check struct
Check *crteChk(int size)
{
    Check *a = nullptr;
    a = new Check[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Employee #" << i+1 << endl;
        cout << "Enter Name: ";
        getline(cin, a[i].name);
        cout << "Enter the wage: ";
        cin >> a[i].wage;
        cout << "Enter hours worked: ";
        cin >> a[i].hours;
        cin.ignore();
        if(a[i].hours > 0 && a[i].hours <=40)
            a[i].payOut = 0 + a[i].wage * a[i].hours;
        else if(a[i].hours >40 && a[i].hours <=60)
            a[i].payOut = 0 + a[i].wage * 40 + a[i].wage * 2 * (a[i].hours - 40);
        else
            a[i].payOut = 0 + a[i].wage * 40 + a[i].wage * 2 * 20 
                    + a[i].wage * 3 *(a[i].hours - 60);
        
        cout << endl;
        
    }
    
    return a;
}

//print the check
void prntChk(Check *a, int size)
{
    for(int i = 0; i < size ; i++)
    {
        cout << "Company: Silkroad Ltd." <<endl;
        cout << "Address: 2314 Grove St" << endl;
        cout << "Name: " << a[i].name << setw(30) << "Amount: $"<<a[i].payOut 
                << endl;
        cout  << "Amount: ";
        engCvrt(a[i].payOut); 
        cout << "Dollars" << endl;
        cout << "Signature Line: Thomas Wayne" << endl << endl;
    }
}




//convert numerical to english numerical
void engCvrt(int a)
{
    unsigned short n2Cnvrt;
    
    //Initialize Variables
    n2Cnvrt = a;
    //Check for a valid input
    if(n2Cnvrt>=1 && n2Cnvrt<=10000){
    //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
        n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=n2Cnvrt%10;        //Remainder of division by 10
        
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s){
            
            case 10:{
                cout<<"Ten Thousands ";
                break;
            }
            case 9:{
                cout<<"Nine Thousands ";
                break;
            }
            case 8:{
                cout<<"Eight Thousands ";
                break;
            }
            case 7:{
                cout<<"Seven Thousands ";
                break;
            }
            case 6:{
                cout<<"Six Thousands ";
                break;
            }
            case 5:{
                cout<<"Five Thousands ";
                break;
            }
            case 4:{
                cout<<"Four Thousands ";
                break;
            }
            case 3:{
                cout<<"Three Thousands ";
                break;
            }
            case 2:{
                cout<<"Two Thousands ";
                break;
            }
            case 1:{
                cout<<"One Thousands ";
                break;
            }
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"Nine Hundreds ":
               n100s==8?"Eight Hundreds ":
               n100s==7?"Seven Hundreds ":
               n100s==6?"Six Hundreds ":
               n100s==5?"Five Hundreds ":
               n100s==4?"Four Hundreds ":
               n100s==3?"Three Hundreds ":
               n100s==2?"Two Hundreds ":
               n100s==1?"One Hundred ":"");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<"Ninety ";
        if(n10s==8)cout<<"Eighty ";
        if(n10s==7)cout<<"Seventy ";
        if(n10s==6)cout<<"Sixty ";
        if(n10s==5)cout<<"Fifty ";
        if(n10s==4)cout<<"Forty ";
        if(n10s==3)cout<<"Thirty ";
        if(n10s==2)cout<<"Twenty ";
        if(n10s==1)
        {
            if(n1s==9)cout<<"Nineteen";
            else if(n1s==8)cout<<"Eighteen";
            else if(n1s==7)cout<<"Seventeen";
            else if(n1s==6)cout<<"Sixteen";
            else if(n1s==5)cout<<"Fifteen";
            else if(n1s==4)cout<<"Fourteen";
            else if(n1s==3)cout<<"Thirteen";
            else if(n1s==2)cout<<"Twelve";
            else if(n1s==1)cout<<"Eleven";
        }
        //Output the number of 1's
        //Using Dependent If Statements
        else
        {
            if(n1s==9)cout<<"And Nine";
            else if(n1s==8)cout<<"And Eight";
            else if(n1s==7)cout<<"And Seven";
            else if(n1s==6)cout<<"And Six";
            else if(n1s==5)cout<<"And Five";
            else if(n1s==4)cout<<"And Four";
            else if(n1s==3)cout<<"And Three";
            else if(n1s==2)cout<<"And Two";
            else if(n1s==1)cout<<"And One";
        }
     
}
}
