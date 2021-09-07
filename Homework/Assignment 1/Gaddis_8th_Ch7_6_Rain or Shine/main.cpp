/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Purpose: Reading from a file into 2d arrays then write the processed data into
 * another file
 * Created on September 6, 2021, 6:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaring 2 dim array with rows and cols
    int rows = 3, cols = 30;
    char weather [rows][cols];
    
    //Reading values from file.txt into the array.
    ifstream fin;
    
    fin.open("file.txt");
    while (!fin.eof())
    {
        for (int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                fin >> weather[i][j];
            }
        }
    }
    fin.close();
    
    //Display the array
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << weather[i][j] << " ";
        }
        cout << endl;
    }
    //Counting the total of rainy, sunny and couldy days for each months
    int jSun {}, jRain{}, jCloud{}; //counters for june
    int juSun {}, juRain{}, juCloud{};// counters for july
    int aSun {}, aRain{}, aCloud{}; // counters for august
    
    //Counting days for June
    for(int i = 0; i < cols; i++)
    {
        if (weather[0][i] == 'S')
            jSun++;
        else if (weather[0][i] == 'R')
            jRain++;
        else 
            jCloud++;
    }
    
    //Counting days for July
    for(int i = 0; i < cols; i++)
    {
        if (weather[1][i] == 'S')
            juSun++;
        else if (weather[1][i] == 'R')
            juRain++;
        else 
            juCloud++;
    }
    
    //Counting days for August
    for(int i = 0; i < cols; i++)
    {
        if (weather[2][i] == 'S')
            aSun++;
        else if (weather[2][i] == 'R')
            aRain++;
        else 
            aCloud++;
    }
    //Writing data in the rainorshine.txt file
    ofstream fout;
    fout.open("RainorShine.txt");
    fout << "The number of rainy days in June: " << jRain << endl;
    fout << "The number of sunny days in June: " << jSun << endl;
    fout << "The number of cloudy days in June: " << jCloud << endl;
    
    fout << "The number of rainy days in July: " << juRain << endl;
    fout << "The number of sunny days in July: " << juSun << endl;
    fout << "The number of cloudy days in July: " << juCloud << endl;
    
    fout << "The number of rainy days in August: " << aRain << endl;
    fout << "The number of sunny days in August: " << aSun << endl;
    fout << "The number of cloudy days in August: " << aCloud << endl;
    
    fout << "The total rainy days in 3 months: " << jRain + juRain +aRain << endl;
    fout << "The total sunny days in 3 months: " << jSun + juSun + aSun << endl;
    fout << "The total cloudy days in 3 months: " << jCloud + juCloud + aCloud << endl;
    
    //Decide which month is the rainiest
    string rainMth = jRain > juRain && jRain > aRain? "July has the most rainy days":
        juRain > jRain && juRain > aRain? "July has the most rainy days": "August has the most rainy days";
    
    fout << rainMth; 
    fout.close();
    cout << jRain <<endl;
    cout << juRain <<endl;
    cout << aRain <<endl;
    return 0;
}

