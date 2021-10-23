/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 22, 2021, 7:01 PM
 * Purpose: Menu of midterm problems
 */
//public libraries
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath> //log10
#include <iomanip>//setw
#include <algorithm> //swap

//user libraries
#include "Banking.h"
#include "Check.h"
#include "Encrypt.h"
#include "Prime.h"
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
bool inValid(string);
Banking *bankAcc(string);
void prntAcc(Banking *);
void destroy(Banking *);

void prblm2();
Check *crteChk(int);
void prntChk(Check *, int);
void engCvrt(int);

void prblm3();

void prblm4();
Encrypt *inCode(int);
void encrypt(Encrypt *);
void decrypt(Encrypt *);
void destroy(Encrypt *);

void prblm5();

void prblm6();

void prblm7();
Prime *factor(int);
void prntPrm(Prime *);
void destroy(Prime *);

//Execution Begins Here
int main(int argc, char** argv) {
    //random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;
        cin.ignore();

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}


void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}


void prblm1(){
    
    
    string accNumb;
    
    bool inVal = false;
    do
    {
        cout << "Enter Account Number(5 digits):";
        getline(cin, accNumb);
        inVal = inValid(accNumb);
        if(inVal == false)
            cout << "Invalid Account Number." << endl << endl;
    }while(inVal == false);
            
    Banking *prob1 = bankAcc(accNumb);
    
    prntAcc(prob1);
    
    destroy(prob1);
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
    cout << endl;
    cin.ignore();
    if(a->newBlnc >=0)
        a->newBlnc = a->newBlnc;
    else
    {
        cout << "You overdrawn. $25 has been deducted from your balance. " << endl;
        a->newBlnc -= 25;
    }
    cout << endl;
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
    if(prob1->newBlnc >=0)
        cout << "Current balance: $" << prob1->newBlnc << endl;
    else
        cout << "Current balance: -$" << (prob1->newBlnc)*-1 << endl;
    cout << "__________________________________________"<<endl;
}

//delete the banking struct
void destroy(Banking *prob1)
{
    delete []prob1->deposit;
    delete []prob1->wthdrwl;
    delete prob1;
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
//******************************************************************************
//******************************************************************************

void prblm2(){
    int numEmp;
    cout << "Enter the number of employee: ";
    cin >> numEmp;
    cin.ignore();
    Check *employee = crteChk(numEmp);
    prntChk(employee, numEmp);
    
    delete []employee;
}

//create the check struct
Check *crteChk(int size)
{
    Check *a = new Check[size];
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
        cout << "_____________________________________________________" << endl;
        cout << "Company: Silkroad Ltd." <<endl;
        cout << "Address: 2314 Grove St" << endl;
        cout << "Name: " << a[i].name << setw(30) << "Amount: $"<<a[i].payOut 
                << endl;
        cout  << "Amount: ";
        engCvrt(a[i].payOut); 
        cout << "Dollars" << endl;
        cout << "Signature Line: Thomas Wayne" << endl;
        cout << "_____________________________________________________" << endl << endl;;
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

//******************************************************************************
//******************************************************************************

void prblm3(){
    cout<<"Open problem 3 in the Folder"<<endl;
}


void prblm4(){
    cout << "1. To encrypt" << endl;
    cout << "2. To decrypt" << endl;
    
    int ecrMenu;
    cin >> ecrMenu;
    cin.ignore();
    switch(ecrMenu){
        case 1:
        {
            cout << "Enter the 4 digits code (digits must be from 0-7): ";
            int codeVal;
            cin >> codeVal;
            Encrypt *prob4 = inCode(codeVal);
            encrypt(prob4);
            destroy(prob4);
            break;
        }
        case 2:
        {
            cout << "Enter the 4 digits code (digits must be from 0-7): ";
            int codeVal;
            cin >> codeVal;
            Encrypt *prob4 = inCode(codeVal);
            decrypt(prob4);
            destroy(prob4);
            break;
        }
        default:
            cout << "Not a valid option." <<endl;
    }
}

// take in and validate the user input
Encrypt *inCode(int codeVal)
{
    //initializing the struct
    Encrypt *a = new Encrypt;
    a->size = 4; //size 4 for 4 digits
    a->code = new int[a->size];//array to hold each digit
    a->val = codeVal;
    //bool to break out of loop
    bool inValid = false;
    
    //loop value
    int loopCnt = 0;
    
    do{
        //filling in the arrays
        for(int i = 0; i < a->size -1; i++)
        {
            a->code[i] = 0;
        }
        
        //count for input loop
        if(loopCnt >0)
        {
            cout << "Enter the 4 digits code (digits must be from 0-7): ";
            cin >> a->val;
            cin.ignore();
        }
        
        
        
        //splitting the input
        a->code[3] = a->val % 10;
        a->code[2] = a->val /10 %10;
        a->code[1] = a->val /100 % 10;
        a->code[0] = a->val /1000 % 10;
        
        int valCnt = 0;
        for(int i = 0; i < a->size; i++)
        {
            if(a->val >7777)
            {
                cout << "Invalid code." << endl;
                break;
            }
            if(a->code[i] > 7)
            {
                cout << "Invalid code." << endl;
                break;
            }
            else
            {
                valCnt++;
                if(valCnt == 4)
                    inValid = true;
            }
        }
        
        loopCnt++;
    }while(inValid == false);
  
    return a;
}

//encrypting the data
void encrypt(Encrypt *prob4)
{
    for(int i = 0; i < prob4->size; i++)
    {
        prob4->code[i] = (prob4->code[i] + 3) % 8;
    }
    swap(prob4->code[0], prob4->code[2]);
    swap(prob4->code[1], prob4->code[3]);
    
    cout << "The encrypted code is: ";
    for(int i = 0; i < prob4->size; i++)
        cout << prob4->code[i];
    
    cout << endl;
}

//decrypting the data
void decrypt(Encrypt *prob4)
{
    for(int i = 0; i < prob4->size; i++)
    {
        if(prob4->code[i] >2)
            prob4->code[i] = (prob4->code[i] - 3);
        else
            prob4->code[i] = (prob4->code[i] + 5);
    }
    
    swap(prob4->code[0], prob4->code[2]);
    swap(prob4->code[1], prob4->code[3]);
    
    cout << "The decrypted code is: ";
    for(int i = 0; i < prob4->size; i++)
        cout << prob4->code[i];
    
    cout << endl;
}

//destroy the struct
void destroy(Encrypt *prob4)
{
    
    delete []prob4->code;
    delete prob4;
}

//******************************************************************************
//******************************************************************************

void prblm5(){
    cout << "Signed Char = 5!"<< endl;
    cout << "Unsigned Char = 5!"<< endl << endl;
    
    cout << "Signed Int = 12!"<< endl;
    cout << "Unsigned Int = 12!"<< endl << endl;
    
    cout << "Signed Short = 7!"<< endl;
    cout << "Unsigned Short = 8!"<< endl << endl;
    
    cout << "Signed Long = 20!"<< endl;
    cout << "Unsigned Long = 20!"<< endl << endl;
    
    cout << "Signed Long Long = 20!"<< endl;
    cout << "Unsigned Long Long = 20!"<< endl << endl;
    
    cout << "Float = 34!"<< endl;
    cout << "Double = 170!"<< endl << endl;
}

//******************************************************************************
//******************************************************************************

void prblm6(){
    cout<<"Problem 6 is in the scanned PDF"<<endl;
}

//******************************************************************************
//******************************************************************************

void prblm7(){
    int pNumb {};
    bool inCheck = false;
    do{
        cout << "Type a number between 2 and 65000:";
        if(cin >> pNumb)
        {
            if(pNumb>1 && pNumb <= 65000)
                
                inCheck = true;
        }
        cin.ignore();
        
    }while(inCheck == false);
    
    Prime *prime = factor(pNumb);
    
    prntPrm(prime);
    
    destroy(prime);
}

//function to find the prime factor of a number
Prime *factor(int n)
{
    Prime *array = new Prime;
    
    array->size = 30;
    array->prime = n; // the number to find prime factor of
    array->power = new unsigned int[array->size] ; //power of the prime factor
    array->nPrimes = new unsigned int [array->size] ; // the prime numbers
    
    //initialize to 0
    for(int i = 0; i < array->size - 1; i++)
    {
        array->power[i] = 0;
        array->nPrimes[i] = 0;
    }
   
    // Check for multiplication of 2
    while (n % 2 == 0)
    {
        array->power[0] = array->power[0] + 1;
        array->nPrimes[0] = 2;
        n = n/2;
    }
    int j = 0;
    //check for the rest of the odd numbers
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        
        //when n divides by i, put i in the power array
        while (n % i == 0)
        {
            if(array->nPrimes[j] != i) j++;
            array->power[j] = array->power[j] + 1;
            array->nPrimes[j] = i;
            n = n/i;
            
        }
        
    }
    //the remainder prime number
    if( n > 1)
    {
        j++;
        array->power[j] += 1;
        array->nPrimes[j] = n;
    }
    
    return array;
}

//print the prime structure
void prntPrm(Prime *a)
{
    if(a->nPrimes[0] |= 0)
    {
        cout << a->prime << " = " << a->nPrimes[0] << "^" << a->power[0];
        for(int i = 1; i < a->size -1 && a->nPrimes[i] != 0; i++)
        {
            cout << " * " << a->nPrimes[i] << "^" << a->power[i] ;
        }
    }
    else
    {
        cout << a->prime << " = " << a->nPrimes[1] << "^" << a->power[1];
        for(int i = 2; i < a->size -1 && a->nPrimes[i] != 0; i++)
        {
            cout << " * " << a->nPrimes[i] << "^" << a->power[i] ;
        }
    }
}

//destroy the structure
void destroy(Prime *a){
    delete []a->nPrimes;
    delete []a->power;
    delete a;
}