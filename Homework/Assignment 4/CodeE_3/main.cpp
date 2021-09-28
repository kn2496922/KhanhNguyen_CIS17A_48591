/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: keurv
 *
 * Created on September 19, 2021, 5:48 PM
 */

#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here
#include <algorithm> 

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char []);//Search for 1 occurrence
void srchAll(const char [],const char [],int [], int&);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int [], int); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    int size{}; // Sise of the match array
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match, size);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    
    print(match, size);
    
    //Exit
    return 0;
}

//Search for 1 occurrence
int  srch1(const char sntnce[],const char pattern[])
{
   
    int pos = -1;
    for(int i = 0; i < strlen(sntnce); i++)
    {
        if(pattern == sntnce)
        {
            pos = i;
            
        }
    }
    
    return pos;
}

//Search for all occurrences
void srchAll(const char sntnce[],const char pattern[],int match[], int &size)
{
    int j = 0;
    for(int i = 0 ; i < strlen(sntnce); i++)
    {
        int pos = srch1(sntnce, pattern);
        if(pos != -1)
        {
            match[j] = pos;
            j++;
        }
    }
    
    size = j;
    
    
}

//Print the character arrays
void print(const char array[])
{
    for(int i = 0; i < strlen(array); i++)
    {
        cout << array[i];
    }
    cout <<endl;
}

//Print the array of indexes where the pattern found
void print(const int array[], int size)
{
    if(size > 0)
    {
        for(int i = 0; i < size; i++)
        {
            cout << array[i];
        }
    }
    else
    {
        cout << "None" <<endl;
    }
}