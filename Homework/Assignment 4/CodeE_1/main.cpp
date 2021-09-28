/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: keurv
 *
 * Created on September 19, 2021, 1:45 PM
 */

#include <iostream>//cout,cin
#include <cstring> //strlen()
#include <string>
#include <algorithm>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    
    
    //Exit
    return 0;
}

//Read in an array and return the size of it
int  read(char array[])
{
    string temp {};
    cin >> array;
    
    int count = strlen(array);

   
    
    return count;
}

//Sorting an array
void sort(char array[],int sizeIn)
{
     bool swap;
     char temp;
     
     do 
     {
         swap = false;
         for(int i = 0; i <(sizeIn - 1); i++)
         {
             if(array[i] > array[i + 1])
             {
                 temp = array[i];
                 array[i] = array[i + 1];
                 array[i + 1] = temp;
                 swap = true;
             }
         }
     }while(swap);
}

//Print out the array
void print(const char array[],int sizeIn)
{
    for(int i = 0; i < sizeIn; i++)
    {
        cout << array[i];
    }

}