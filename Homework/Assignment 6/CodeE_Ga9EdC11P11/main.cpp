/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 3, 2021, 1:24 PM
 * Purpose: Store company sale of each division
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

struct MonthlyBudget
{
    float housing;
    float utility;
    float hhExp;
    float trnsPrt;
    float food;
    float medical;
    float insrnce;
    float entertn;
    float clothes;
    float misc;
    float total;
    
};

void compare(MonthlyBudget &, MonthlyBudget & );

int main(int argc, char** argv) {

    //Declaring the budget structure 
    MonthlyBudget budget;
    budget.housing = 500.00;
    budget.utility = 150.00;
    budget.hhExp = 65.00;
    budget.trnsPrt = 50.00;
    budget.food = 250.00;
    budget.medical = 30.00;
    budget.insrnce = 100.00;
    budget.entertn = 150.00;
    budget.clothes = 75.00;
    budget.misc = 50.00;
    budget.total = (budget.housing + budget.utility + budget.hhExp + budget.trnsPrt
            + budget.food + budget.medical + budget.insrnce + budget.entertn +
            budget.clothes + budget.misc);
    
    //Declaring the expense structure
    MonthlyBudget exp;
    
    //input to the expense structure
    cout << "Enter housing cost for the month:$" <<endl;
    cout << "Enter utilities cost for the month:$" <<endl;
    cout << "Enter household expenses cost for the month:$" <<endl;
    cout << "Enter transportation cost for the month:$" <<endl;
    cout << "Enter food cost for the month:$" <<endl;
    cout << "Enter medical cost for the month:$" <<endl;
    cout << "Enter insurance cost for the month:$" <<endl;
    cout << "Enter entertainment cost for the month:$" <<endl;
    cout << "Enter clothing cost for the month:$" <<endl;
    cout << "Enter miscellaneous cost for the month:$" <<endl;
    
    cin >> exp.housing >> exp.utility >> exp.hhExp >> exp.trnsPrt >>
            exp.food >> exp.medical >> exp.insrnce >> exp.entertn >>
            exp.clothes >> exp.misc;
    
    exp.total = (exp.housing + exp.utility + exp.hhExp + exp.trnsPrt
            + exp.food + exp.medical + exp.insrnce + exp.entertn +
            exp.clothes + exp.misc);
    
    compare(budget, exp);
    
    
    return 0;
}

void compare(MonthlyBudget &a, MonthlyBudget &b)
{
    cout << "Housing ";
    if(a.housing == b.housing)
        cout << "Even";
    else if (a.housing > b.housing)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Utilities ";
    if(a.utility == b.utility)
        cout << "Even";
    else if (a.utility > b.utility)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Household Expenses ";
    if(a.hhExp == b.hhExp)
        cout << "Even";
    else if (a.hhExp > b.hhExp)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Transportation ";
    if(a.trnsPrt == b.trnsPrt)
        cout << "Even";
    else if (a.trnsPrt > b.trnsPrt)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Food ";
    if(a.food == b.food)
        cout << "Even";
    else if (a.food > b.food)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Medical ";
    if(a.medical == b.medical)
        cout << "Even";
    else if (a.medical > b.medical)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Insurance ";
    if(a.insrnce == b.insrnce)
        cout << "Even";
    else if (a.insrnce > b.insrnce)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Entertainment ";
    if(a.entertn == b.entertn)
        cout << "Even";
    else if (a.entertn > b.entertn)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Clothing ";
    if(a.clothes == b.clothes)
        cout << "Even";
    else if (a.clothes > b.clothes)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    cout << "Miscellaneous ";
    if(a.misc == b.misc)
        cout << "Even";
    else if (a.misc > b.misc)
        cout << "Under";
    else
        cout << "Over";
    cout << endl;
    
    if(a.total > b.total)
        cout << "You were $" << fixed << setprecision(2) << a.total - b.total << " under budget";
    else
        cout << "You were $" << fixed << setprecision(2) << b.total - a.total << " over budget";
           
    
}

