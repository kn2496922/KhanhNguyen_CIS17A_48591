/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: keurv
 *
 * Created on October 22, 2021, 1:07 PM
 */

#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned short n2Cnvrt;
    
    //Initialize Variables
    cout<<"This program converts Arabic to Roman Numerals"<<endl;
    cout<<"Input a number between 1 - 10000"<<endl;
    cin>>n2Cnvrt;
    //Check for a valid input
    if(n2Cnvrt>=1 && n2Cnvrt<=10000){
    //Process or map Inputs to Outputs
        //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=n2Cnvrt/1000;   //Shift 3 places to the left
        n100s=n2Cnvrt%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=n2Cnvrt%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=n2Cnvrt%10;        //Remainder of division by 10
        
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s){
            
            case 10:{
                cout<<"Ten Thousands ";
                break;
            }
            case 9:{
                cout<<"Nine Thousands ";
                break;
            }
            case 8:{
                cout<<"Eight Thousands ";
                break;
            }
            case 7:{
                cout<<"Seven Thousands ";
                break;
            }
            case 6:{
                cout<<"Six Thousands ";
                break;
            }
            case 5:{
                cout<<"Five Thousands ";
                break;
            }
            case 4:{
                cout<<"Four Thousands ";
                break;
            }
            case 3:{
                cout<<"Three Thousands ";
                break;
            }
            case 2:{
                cout<<"Two Thousands ";
                break;
            }
            case 1:{
                cout<<"One Thousands ";
                break;
            }
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"Nine Hundreds ":
               n100s==8?"Eight Hundreds ":
               n100s==7?"Seven Hundreds ":
               n100s==6?"Six Hundreds ":
               n100s==5?"Five Hundreds ":
               n100s==4?"Four Hundreds ":
               n100s==3?"Three Hundreds ":
               n100s==2?"Two Hundreds ":
               n100s==1?"One Hundred ":"");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<"Ninety ";
        if(n10s==8)cout<<"Eighty ";
        if(n10s==7)cout<<"Seventy ";
        if(n10s==6)cout<<"Sixty ";
        if(n10s==5)cout<<"Fifty ";
        if(n10s==4)cout<<"Forty ";
        if(n10s==3)cout<<"Thirty ";
        if(n10s==2)cout<<"Twenty ";
        if(n10s==1)
        {
            if(n1s==9)cout<<"Nineteen";
            else if(n1s==8)cout<<"Eighteen";
            else if(n1s==7)cout<<"Seventeen";
            else if(n1s==6)cout<<"Sixteen";
            else if(n1s==5)cout<<"Fifteen";
            else if(n1s==4)cout<<"Fourteen";
            else if(n1s==3)cout<<"Thirteen";
            else if(n1s==2)cout<<"Twelve";
            else if(n1s==1)cout<<"Eleven";
        }
        //Output the number of 1's
        //Using Dependent If Statements
        else
        {
            if(n1s==9)cout<<"And Nine";
            else if(n1s==8)cout<<"And Eight";
            else if(n1s==7)cout<<"And Seven";
            else if(n1s==6)cout<<"And Six";
            else if(n1s==5)cout<<"And Five";
            else if(n1s==4)cout<<"And Four";
            else if(n1s==3)cout<<"And Three";
            else if(n1s==2)cout<<"And Two";
            else if(n1s==1)cout<<"And One";
        }
        
        
                
    //The Path to Exit
    }else{
        cout<<"You have problems following Directions"<<endl;
        cout<<"Come back when you decide to comply"<<endl;
    }

    //Exit stage right!
    return 0;
}