/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh
 *
 * Created on September 26, 2021, 2:42 AM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library

#include <iomanip> //setprecision

using namespace std;

//Prototypes
int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array
int *sort( int *,int );    //sort the array
	
int main(){
    int arySize{},
        *ary;
    float *medAry;    
    
    
    
    ary = getData(arySize);
    prntDat(ary,arySize);
    
    
    
    medAry = median(ary, arySize);
    prntMed(medAry);
    
    
    delete[] ary;
    delete[] medAry;
    return 0;

}


//Return the array
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

//Print the integer array
void prntDat(int *array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[size - 1];
    cout << endl;
}

//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *array,int size)
{
    float *b = new float[size+2];
    int *c = new int[size];
    float median {};
    c = sort(array, size);
    (size%2 == 1)? median = c[size/2]: median = (c[size/2] + c[size/2 -1])/2.0;
    
    b[0] = size+2;
    b[1] = median;
    
    for(int i = 2; i <size +2; i++)
        b[i] = array[i-2];
    
    delete[] c;
    return b;
}

//Print the median Array
void prntMed(float *array)
{
    cout << array[0] << " ";
    for(int i = 1; i < array[0]; i++)
    {
        if(i < array[0] - 1)
        {
            cout << fixed << setprecision(2) << array[i] << " ";
        }
        else
        {
            cout << fixed << setprecision(2) << array[i];
        }
    }
    
}

//Sort smallest to largest
int *sort( int *array,int size)
{
    //Bubble Sort
    int *b = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        b[i] = array[i];
    }
    bool swap;
    int temp;
    
    do
    {
        swap = false;
        for (int i = 0; i < (size-1); i++)
        {
            if (b[i] > b[i+1])
            {
                temp = b[i];
                b[i] = b[i+1];
                b[i+1] = temp;
                swap = true;
            }
        }
    }while(swap);
    
    return b;
}