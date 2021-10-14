/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 10, 2021, 1:20 AM
 * Purpose: Corporate Sales data output
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;



struct Company
{
    string divName;
    int quarter;
    int sales;
};



void wrtText(fstream &,struct Company[], int);
void wrtBin(fstream &,struct Company[], int);
void print(struct Company [], int);

int main(int argc, char** argv) {

    //open binary and text files
    fstream txtFile,binFile;
    
    //creating the files
    txtFile.open("corporate.txt", ios::out);
    binFile.open("corporate.dat", ios::out);
    
    txtFile.close();
    binFile.close();
    
    //open the files
    txtFile.open("corporate.txt", ios::in|ios::out);
    binFile.open("corporate.dat", ios::in|ios::out|ios::binary);
    
    int size = 4;
    
    Company corp[size];
    corp[0] = {"West", 1, 0};
    corp[1] = {"East", 2 , 0};
    corp[2] = {"South", 3, 0};
    corp[3] = {"North", 4, 0};
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter a sale figure for " << corp[i].divName << " division's quarter " <<
                corp[i].quarter << " :";
        //input validation
        for(;;)
        {
            if(cin >> corp[i].sales && corp[i].sales > 0)
            {
                break;
            }
            else
            {
                cout << "Please enter a valid amount" << endl;
                //clear the buffer
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
            }
        }
    }
    wrtText(txtFile, corp, size);
    wrtBin(binFile, corp, size);
    
    print(corp, size);
    
    txtFile.close();
    binFile.close();
    
    return 0;
}

void wrtText(fstream &out,struct Company a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        out << a[i].divName << endl;
        out << "Quarter " << a[i].quarter << endl;
        out << "Sale figure: " << a[i].sales << endl << endl;
    }
}

void wrtBin(fstream &out,struct Company a[], int size)
{
    out.write(reinterpret_cast<char *>(a), size*sizeof(a));
}



void print(struct Company a[], int size)
{
    cout << "Printing to files..." << endl;
    for(int i = 0; i < size; i++)
    {
        cout << a[i].divName << endl;
        cout << "Quarter " << a[i].quarter << endl;
        cout << "Sale figure: " << a[i].sales << endl << endl;
    }
}



