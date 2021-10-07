/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 26, 2021, 7:20 PM
 * Purpose: Find the Mode
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort
int *copy(const int *,int); //Copy the Array
void shuffle(int *,int,int);//Shuffle the Array
unsigned int GRB();         //Generate Random Bit
void GR(unsigned int&);     //Generate Random Number
int *mode(const int *,int); //Find the mode set

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"The program finds the mode of a set"<<endl;
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Array before shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Shuffle the Array 7 times
    shuffle(ary,arySize,7);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the initial array
    cout<<"The Array after shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the modal information of the array
    cout<<"The Modal Information"<<endl;
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void shuffle(int *a,int n,int nShuf){
    unsigned int temp;
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int i=0;i<n;i++){
            GR(temp);
            temp%=n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}

unsigned int GRB(){
    static unsigned int seed=0;
    seed += (seed * seed) | 5;
    return seed & 0x80000000;
}
 
void GR(unsigned int& value){
    value=0;
    const unsigned int numBits = sizeof(int) * 8;
    unsigned int* dataPointer = (unsigned int *)&value;
    for (unsigned int index = 0; index < numBits; ++index)
    {
        if(GRB()) {
            unsigned int pointerIndex = index / 32;
            unsigned int mask = 1 << index % 32;
            dataPointer[pointerIndex] |= mask;
        }
    }
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the copy
    mrkSort(ary,arySize);
    //Find the max Frequency
    int maxFreq = 1; //Max frequency
    int count = 1; //Counting like elements
    int number = ary[0]; //Used to compare with subsequent elements
    
    for (int i = 1; i < arySize; i++)
    {
        //count like elements
        if(ary[i] == number)
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
            number = ary[i];
        }
    }
    //Find the number of modes
    int mdeSize = 0;
    count = 1;
    number = ary[0];
    
    for (int i = 1; i <arySize; i++)
    {
        //counting the occurrence of a number, if it's = maxFreq it's added to
        //the mode
        if(ary[i] == number)
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
            number = ary[i];
            count = 1;
        }   
       
    }
    //Allocate the mode array
    //Again this is just a stub.
    int nmodes=mdeSize;
    int *modeAry=new int[nmodes+2];
    modeAry[0]=(mdeSize == 0)? 0: mdeSize;//Stub returns no modes
    modeAry[1]=maxFreq;//Stub returns Frequency 1
    
    
    //Fill the mode array
    if(mdeSize > 0)
    {
        count = 1;
        number = ary[0];
        int modeCnt = 2; //where the modeAry data set starts
        for(int i = 1; i<arySize; i++ )
        {
            if(ary[i] == number)
            {
                count++;
                //if counter is the same as maxFreq, assign the number to
                //modeAry
                if(count == maxFreq)
                {
                    modeAry[modeCnt] = number;
                    modeCnt++;
                }
            }
            else
            {
                //reset the counter and assign new value to number
                number = ary[i];
                count = 1;
            }
        }
    }
    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}

