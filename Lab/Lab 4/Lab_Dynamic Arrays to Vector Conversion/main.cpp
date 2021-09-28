/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on September 25, 2021, 6:48 PM
 * Purpose: Convert dynamic arrays to vector
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension

//Function Prototypes Here
void prntAry(vector<int> &,int);
void prntAry(vector<vector <int>> &);
void fillAry(vector<int> &,int,int);
void fillAry(vector <vector<int>> &,vector <int> &,int);
void swap(int &,int &);
void smlLst(vector<int> &,int);
void mrkSort(vector <int> &);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int ROWSIZE=4;
    const int COLSIZE=3;
    vector <int> array(ROWSIZE);
    vector <int> brray(ROWSIZE);
    vector <int> crray(ROWSIZE);
    vector <vector <int>> table(ROWSIZE, vector<int> (COLSIZE));
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel array
    fillAry(array,highRng,lowRng);
    fillAry(brray,highRng/10,lowRng/10);
    fillAry(crray,highRng/100,lowRng/100);
    
    //Sort the array the for all positions
    mrkSort(array);
    mrkSort(brray);
    mrkSort(crray);
    
    //Fill the 2-D array
    fillAry(table,array,0);
    fillAry(table,brray,1);
    fillAry(table,crray,2);
    
    //Print the values in the array
    prntAry(array,perLine);
    prntAry(brray,perLine);
    prntAry(crray,perLine);
    prntAry(table);

    //Exit
    return 0;
}

void fillAry(vector<vector<int>> &a,vector<int> & c,int wchCol){
    for(int row=0;row<a.size();row++){
        a[row][wchCol]=c[row];
    }
}

void fillAry(vector<int> & a,int hr,int lr){
    for(int indx=0;indx<a.size();indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(vector<vector <int>> &a){
     cout<<endl<<"The Array Values"<<endl;
    for(int row=0;row<a.size();row++){
        for(int col=0;col<a[row].size();col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}

void prntAry(vector<int> &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(vector<int> &a){
    for(int pos=0;pos<a.size()-1;pos++){
        smlLst(a,pos);
    }
}

void smlLst(vector<int> &a,int pos){
    for(int i=pos+1;i<a.size();i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}