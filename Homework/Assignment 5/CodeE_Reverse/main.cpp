/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 26, 2021, 5:57 PM
 * Purpose: Reverse the dynamic array
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

//Prototypes

int *getData(int &);               //Fill the array
int *sort( int *,int);        //Sort smallest to largest
int *reverse(const int *,int);     //Sort in reverse order
void prntDat(const int *,int);     //Print the array

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int arySize{},
        *array,
        *brray,
        *crray;
    
    array = getData(arySize);
    crray = sort(array, arySize);
    prntDat(crray, arySize);
    cout << endl;
    
    brray = reverse(crray, arySize);
    prntDat(brray, arySize);
    
    
    delete[] array;
    delete[] brray;
    delete[] crray;

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

//Sort smallest to largest
int *sort( int *array,int size)
{
    //Bubble Sort
    int *crray = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        crray[i] = array[i];
    }
    bool swap;
    int temp;
    
    do
    {
        swap = false;
        for (int i = 0; i < (size-1); i++)
        {
            if (crray[i] > crray[i+1])
            {
                temp = crray[i];
                crray[i] = crray[i+1];
                crray[i+1] = temp;
                swap = true;
            }
        }
    }while(swap);
    
    return crray;
}

//Print Array
void prntDat(const int *array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[size - 1];
}


int *reverse(const int *array,int size)
{
    //temp array
    int *brray = new int[size];
    
    //Reverse the order of the array
    
    for(int i = 0; i < size; i++)
    {
        brray[i] = array[size - i - 1];
    }
    
    return brray;
}