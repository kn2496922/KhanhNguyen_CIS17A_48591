/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 26, 2021, 5:57 PM
 * Purpose: Sum of 2d array
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

/*
 * 
 */
int main(int argc, char** argv) {
    //initialize
    int rows, cols, total,
        **array;
    
    //input the size of 2d array(rows,cols and values)
    array = getData(rows,cols);
    
    //print the 2d array
    prntDat(array, rows, cols);
    
    //finding the sum
    total = sum(array, rows, cols);
    cout << total;
    
    
    //deallocate memory
    destroy(array, rows, cols);
    return 0;
}

//Return the 2-D array and its size.
int **getData(int &rows ,int &cols)
{
    rows=rows<2?2:
      rows>1000?1000:rows;
    cols=cols<2?2:
      cols>1000?1000:cols;
    
    
    int **a = new int *[rows];
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++)
    {
        a[i] = new int [cols];
        for(int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
    }
    
    return a;
    
}

//Print the 2-D Array
void prntDat(const int* const * array,int rows,int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if (j == cols - 1)
            {
                cout  << array[i][j] << endl;
            }
            else
            {
                cout  << array[i][j] << setw(2);
            }
        }
        
    }
    
}

//Deallocate memory
void destroy(int **array,int rows,int cols)
{
    for(int r=0;r<rows;r++){
        delete []array[r];
    }
    delete []array;
}


//Return the Sum
int sum(const int * const *array, int rows,int cols)
{
    int sum {};
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum += array[i][j];
        }
    }
    
    return sum;
}
