/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 26, 2021, 8:57 PM
 * Purpose: augment 2d dynamic array
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//Prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main(int argc, char** argv) {

    //initialize
    int rows, cols,
        **array,
        **brray;
    
   
    array = getData(rows, cols);
    printDat(array, rows, cols);
    
     cout <<endl;
    
    brray = augment(array, rows+1, cols+1);
    printDat(brray, rows+1, cols+1);
    
    destroy(array, rows);
    destroy(brray, rows + 1);
    return 0;
}

//Get the Matrix Data
int **getData(int &rows,int &cols)
{
    rows=rows<2?2:
      rows>1000?1000:rows;
    cols=cols<2?2:
      cols>1000?1000:cols;
    
    //input to rows cols
    cin >> rows >> cols;
    
    //initialize dynamic array
    int **a = new int *[rows];
    
    for(int i = 0; i < rows; i++)
    {
        a[i] = new int[cols];
        for(int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
        
    }
    
    return a;
}

//Print the Matrix
void printDat(const int* const * array,int rows,int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if (i == rows - 1 && j == cols - 1)
            {
                cout  << array[i][j];
            }
            else if (j == cols - 1)
            {
                cout << array[i][j] << endl;
            }
            else
            {
                cout  << array[i][j] << setw(2);
            }
        }
        
    }
}


//Augment the original array
int **augment(const int * const *array, int rows, int cols)
{
    rows=rows<2?2:
      rows>1000?1000:rows;
    cols=cols<2?2:
      cols>1000?1000:cols;
    
    
    int **b = new int* [rows];
    //rows
    for(int i = 0; i < rows; i++)
    {
        b[i] = new int[cols];
        //cols
        for(int j = 0; j < cols; j++)
        {
            b[i][j] = 0;
        }
    }
    
    for (int i = 1; i < rows; i++)
    {
        for(int j = 1; j< cols; j++)
        {
            b[i][j] = array[i-1][j-1];
        }
    }
    
    return b;
}

//Destroy the Matrix, i.e., reallocate memory
void destroy(int **array, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    
    delete[] array;
}

