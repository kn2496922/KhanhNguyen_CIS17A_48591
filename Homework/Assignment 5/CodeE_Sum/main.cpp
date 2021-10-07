/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 26, 2021, 5:57 PM
 * Purpose: Sum of the previous numbers
 */

#include <cstdlib>
#include <iostream>


using namespace std;

//prototypes
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

//main
int main(int argc, char** argv) {

    //initialize
    int arySize{},
        *array,
        *brray;
    //input to array
    array = getData(arySize);
    //print the array
    prntAry(array, arySize);
    cout << endl;
    
    //create brray in which every elements is the sum of the successive numbers
    //from array
    brray = sumAry(array, arySize);
    
    //print brray
    prntAry(brray, arySize);
    
        
    
    delete[] array;
    delete[] brray;
    return 0;
}



//Return the array and size
int *getData(int &size)
{
    cin >> size;
    int *a = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    return a;
}
//Return the array with successive sums
int *sumAry(const int *array,int size)
{
    //initialize dynamic array
    int *b = new int[size];
    int sum{};
    //
    for(int i = 0; i < size; i++)
    {
        sum += array[i];
        b[i] = sum;
    }
    return b;
}


//Print the array
void prntAry(const int *array,int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[size - 1];
    
}

