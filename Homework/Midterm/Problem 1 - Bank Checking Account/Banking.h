/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Banking.h
 * Author: keurv
 *
 * Created on October 22, 2021, 1:57 PM
 */
#include <string>
#ifndef BANKING_H
#define BANKING_H

struct Banking{
    std::string accNumb;
    std::string name;
    std::string address;
    int balance;
    int newBlnc;
    int wSize;
    int *wthdrwl;
    int dSize;
    int *deposit;
    
};

#endif /* BANKING_H */

