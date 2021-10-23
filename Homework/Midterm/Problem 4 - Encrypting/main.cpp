/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 20, 2021, 10:21 PM
 * Purpose: Encrypting and decrypting a given code
 */

//public libraries
#include <cstdlib>
#include <iostream>
#include <algorithm> //swap

//user libraries
#include "Encrypt.h"


using namespace std;

Encrypt *inCode(int);
void encrypt(Encrypt *);
void decrypt(Encrypt *);
void destroy(Encrypt *);


int main(int argc, char** argv) {

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
            cin.ignore();
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
            cin.ignore();
            Encrypt *prob4 = inCode(codeVal);
            decrypt(prob4);
            destroy(prob4);
            break;
        }
        default:
            cout << "Not a valid option." <<endl;
    }
    return 0;
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