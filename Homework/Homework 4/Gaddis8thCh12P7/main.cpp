/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 10, 2021, 3:48 PM
 * Purpose: Sentence filter
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char** argv) {

    fstream txtFile1,txtFile2;
    
    char ch;
    string fleName;
    
    //User input for the files name
    cout << "Enter the name to create files: ";
    getline(cin,fleName);
    
    fleName += ".txt";
    
    //Creating the files
    txtFile1.open(fleName, ios::out);
    
    //open input file
    txtFile2.open("essay.txt", ios::in);
    
    if(txtFile2)
    {
        txtFile2.get(ch);
        //output to file and capitalize the 1st letter
        txtFile1.put(toupper(ch));
        
        
        
        while(txtFile2)
        {
            txtFile2.get(ch);
            if( ch == '.')
            {
                txtFile1 << ch;
                
                txtFile2.get(ch);
                txtFile1.put(toupper(ch));
            }
            else
            {
                txtFile1.put(tolower(ch));
            }
        }
    }
    else
    {
        cout << "Can not open the file. Exiting.";
        exit(0);
    }
    cout << "Converting... " << endl;
    
    
    
    
    //Close the file
    txtFile1.close();
    txtFile2.close();
    
    
    return 0;
}

