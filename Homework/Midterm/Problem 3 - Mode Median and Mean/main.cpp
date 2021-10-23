/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 21, 2021, 8:33 PM
 * Purpose: Find the mode median and mean and average
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    
    //Find the max Frequency
    int maxFreq = 1; //Max frequency
    int count = 1; //Counting like elements
    int number = array->data[0]; //Used to compare with subsequent elements
    
    for (int i = 1; i < array->size; i++)
    {
        //count like elements
        if(array->data[i] == number)
        {
            count++;
        } 
        //if it's a different value
        else
        {
            if(count > maxFreq)
            {
                maxFreq = count;
            }
            ////reset the counter and assign new value to number
            count = 1;
            number = array->data[i];
        }
    }
    //Find the number of modes
    int mdeSize = 0;
    count = 1;
    number = array->data[0];
    
    for (int i = 1; i < array->size; i++)
    {
        //counting the occurrence of a number, if it's = maxFreq it's added to
        //the mode
        if(array->data[i] == number)
        {
            count++;
            if(count == maxFreq)
            {
                mdeSize++;
            }
        }
        //when the value change/different from the number we're comparing
        else
        {
            number = array->data[i];
            count = 1;
        }   
       
    }

    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size = mdeSize;
    int nModes=mdeSize;
    if(nModes!=0)
        stats->mode->data=new int[nModes];
    stats->modFreq=maxFreq;
    //median of the array for odd and even array.
    (array->size % 2 == 1)? stats->median = array->data[array->size/2]:
        stats->median = (array->data[array->size /2] + array->data[array->size/2 -1])/2.0;
    //Fill the mode array
    if(mdeSize > 0)
    {
        count = 1;
        number = array->data[0];
        int modeCnt = 0;
        for(int i = 1; i<array->size; i++ )
        {
            if(array->data[i] == number)
            {
                count++;
                //if counter is the same as maxFreq, assign the number to
                //stats->mode
                if(count == maxFreq)
                {
                    stats->mode->data[modeCnt] = number;
                    modeCnt++;
                }
            }
            else
            {
                //reset the counter and assign new value to number
                number = array->data[i];
                count = 1;
            }
        }
    }
    
    //finding the average
    float sum = 0;
    for(int i = 0; i < array->size; i++)
    {
        sum+= array->data[i];
    }
    stats->avg = sum / array->size / 1.0;
    return stats;
}

