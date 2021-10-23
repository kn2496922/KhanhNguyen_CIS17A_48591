/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 20, 2021, 8:28 PM
 * Purpose: Find the prime factors
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

//user library
#include "Prime.h"
using namespace std;
 
Prime *factor(int);
void prntPrm(Prime *);
void destroy(Prime *);

int main()
{
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
    return 0;
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