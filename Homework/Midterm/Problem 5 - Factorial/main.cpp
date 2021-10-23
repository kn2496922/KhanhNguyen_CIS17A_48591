/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: keurv
 *
 * Created on October 21, 2021, 11:07 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    cin >> n;
    double fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    
    cout << "Factorial of " << n << " = " << fact;

    return 0;
}

