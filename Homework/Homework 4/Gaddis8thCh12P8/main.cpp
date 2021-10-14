/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 10, 2021, 8:11 PM
 * Purpose: Array to binary file and reverse
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void aryToFi(fstream &, int * , int);
void fiToAry(fstream &, int *, int);
int *fillAry(int);
void prntAry(int*, int);

int main(int argc, char** argv) {

    //random number seed
    srand(static_cast<unsigned int> (time(0)));
    
    //declaring array
    int *array = new int;
    int *brray = new int;
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;
    cin.ignore();
    
    array = fillAry(size);
    prntAry(array, size);
    
    fstream binFile;
    //creating the file
    binFile.open("data.bin",ios::out);
    binFile.close();
    
    //opening binary file for io
    binFile.open("data.bin", ios::in|ios::out|ios::binary);
    
    //output array to binary file
    aryToFi(binFile, array, size);
    

    //input binary file to brray
    fiToAry (binFile, brray, size);

    prntAry(brray, size);
    
    delete array;
    delete brray;
    binFile.close();
    return 0;
}


//Output the array into the binary file
void aryToFi(fstream &out, int *a, int size)
{   
    out.write(reinterpret_cast<char *>(a), (size)*sizeof(a));
}

//input the binary file to an array
void fiToAry(fstream &in, int *a, int size)
{
    in.seekg(0L, ios::beg);
    in.read(reinterpret_cast<char *>(a), (size)*sizeof(a));
    
}


//randomly assign a value to the array
int *fillAry(int size)
{
    int *a = new int [size];
    for (int i = 0; i < size; i++)
        a[i] = rand()%100 + 1;
    
    return a;
}


//printing the array
void prntAry(int* a, int size)
{
    cout << "Printing the array: " <<endl;
    
    for(int i = 0; i < size; i++)
        cout << a[i] << " ";
    
    cout << endl;
}