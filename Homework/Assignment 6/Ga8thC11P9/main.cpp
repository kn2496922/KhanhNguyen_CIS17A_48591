/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Created on October 4, 2021, 12:20 PM
 * Purpose: A program  that  keeps  track  of  a  speakers’  bureau.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Speaker
{
    string name;
    string teleNum;
    string topic;
    float fee;
    
};


void nwEntry(struct Speaker [], int&);
void edit(struct Speaker [], int);
void print(struct Speaker [], int);

int main(int argc, char** argv) {
    
    int const maxEntry = 10;
    Speaker entry[maxEntry];
    int n3Count = 0; //counting the entry
    char menu;
    do{
        cout << "_________________________________" << endl;
        cout << "Welcome to the Speakers' Bureau" << endl;
        cout << "Main Menu " << endl;
        cout << "1. Enter new Entry." << endl;
        cout << "2. Edit an Entry." << endl;
        cout << "3. Print all Entries." << endl;
        cout << "Q. Exit the program." << endl;
        cout << "_________________________________" << endl;
        cout << "Enter your choice: ";
        cin >> menu;
        cout << endl;
        switch(menu)
        {
            case '1':
                //enter new entry
                if(n3Count < maxEntry)
                    nwEntry(entry, n3Count);
                else
                    cout << "Reached max Entry." << endl;
                break;
            case '2':
                //editing menu
                int editPos;
                cout << "Enter the entry you want to edit: " << endl;
                cin >> editPos;
                
                //check if the entered position is valid( less than actual entries
                // and more than 0
                if(editPos <= n3Count && editPos > 0)
                {
                    edit(entry, editPos-1);
                }
                else
                {
                    cout << "Invalid entry number. Return to Main Menu." << endl;
                }
                break;
            case '3':
                //Print out all entries
                //Check if the structure array is empty
                if(n3Count != 0)
                {
                    print(entry, n3Count);
                }
                else
                {
                    cout << "There's no entry." << endl;
                }
                break;
                
            case 'Q':
            case 'q':
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Not a valid option." << endl;
                break;
        }
        
    }while(tolower(menu) != 'q');
    
    return 0;
}


//Enter a new entry
void nwEntry(struct Speaker a[] , int &pos)
{
    cin.ignore();
    
    cout << "Enter your name: ";
    getline(cin, a[pos].name);
    
    cout << "Enter your telephone number: ";
    getline(cin, a[pos].teleNum);
    
    cout << "Enter your Speaking Topic: ";
    getline(cin, a[pos].topic);
    
    //input validation for fee
    for(;;)
    {
        cout << "Enter the Required Fee: ";
        
        if(cin >> a[pos].fee && a[pos].fee > 0)
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
    
    cout << "Completed! Returning to Main Menu" << endl;
    pos++;
    
}

//Edit an existing entry
void edit(struct Speaker a[],int pos )
{
    string choice;
    cout << "Editing entry number " << pos + 1 << endl;
    cout << "Do you want to change the name? (y/n)" ;
    cin >> choice;
    if(tolower(choice[0]) == 'y')
    {
        cout << "Enter your name: " ;
        cin.ignore();
        getline(cin, a[pos].name);
    }
    
    cout << "Do you want to change the telephone number? (y/n)" ;
    cin >> choice;
    if(tolower(choice[0]) == 'y')
    {
        cout << "Enter your telephone number: " ;
        cin.ignore();
        getline(cin, a[pos].teleNum);
    }
    
    cout << "Do you want to change the topic? (y/n)" ;
    cin >> choice;
    if(tolower(choice[0]) == 'y')
    {
        cout << "Enter your Speaking Topic: ";
        cin.ignore();
        getline(cin, a[pos].topic);
    }
    
    cout << "Do you want to change the fee? (y/n)" ;
    cin >> choice;
    if(tolower(choice[0]) == 'y')
    {
        //input validation for fee
        for(;;)
        {
            cout << "Enter the Required Fee: " ;

            if(cin >> a[pos].fee && a[pos].fee > 0)
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
    cout << "Completed! Returning to Main Menu" << endl;
}

//Printing all the structure arrays
void print(struct Speaker a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "Entry number " << i+1 << endl;
        cout << "Name: " << a[i].name << endl;
        cout << "Telephone Number: " << a[i].teleNum << endl;
        cout << "Speaking Topic: " << a[i].topic << endl;
        cout << "Required Fee: " << a[i].fee << endl;
        cout << "****************" << endl;
    }
    
    cout << "The end of all entries. Going back to main menu." << endl << endl;
}