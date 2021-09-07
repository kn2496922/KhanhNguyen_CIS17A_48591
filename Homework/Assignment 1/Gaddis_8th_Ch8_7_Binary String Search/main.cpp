/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Khanh Nguyen
 * Purpose: Using binary search on a string array
 * Created on September 6, 2021, 7:40 PM
 */

 #include <iostream> 
 #include <string> 
 using namespace std; 
 
void sortArray(string [], int);
int binarySearch(string [], int, string);
 
 int main() 
 { 
     //Data being given from the book
     const int size = 20; 
     string names[size] = {"Collins, Bill", "Smith, Bart", "Allen, Jim", 
                                   "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                              "Taylor, Terri", "Johnson, Jill", 
                                   "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                             "James, Jean", "Weaver, Jim", "Pore, Bob", 
                             "Rutherford, Greg", "Javens, Renee", 
                             "Harrison, Rose", "Setzer, Cathy", 
                             "Pike, Gordon", "Holland, Beth" };
     
    //Sorting the string array in descending order using the sort function
     sortArray(names, size);
    
    //Printing out the array for reference
     for(string i: names)
         cout << i << endl;
     
     cout << endl;
     //Asking user input for the search value
     string search{};
     cout << "Type in the names you want to search(last, first name): ";
     getline(cin, search);
     
     //Using the binary search function
     int position = binarySearch(names, size, search);
     
     if(position == -1)
     {
         cout << "The searched name isn't in the array!";
     }
     else
     {
         //Position + 1 since the array starts at 0 instead of 1
         cout << search << " is at position " << position + 1 << " in the array." << endl;
     }
     
     
    return 0;
}

 //Bubble sort the string array in descending alphabetical order
 void sortArray(string array[], int size)
 {
     bool swap;
     string temp;
     
     do 
     {
         swap = false;
         for(int i = 0; i <(size - 1); i++)
         {
             if(array[i] > array[i + 1])
             {
                 temp = array[i];
                 array[i] = array[i + 1];
                 array[i + 1] = temp;
                 swap = true;
             }
         }
     }while(swap);
 }
 
 
 //Binary search function
 int binarySearch(string array[], int size , string value)
 {
    int first = 0, last = size - 1,
             mid{}, position = -1;
    bool found = false;
    
    while (!found && first <= last)
    {
        mid = (first + last) / 2; //Finding midpoint
        if (array[mid] == value) //If the searched term is the midpoint
        {
            found = true;
            position = mid;
        }
        else if (array[mid] >value) //If value is in lower half
            last = mid - 1;
        else                        //value on the other half
            first = mid +1;
    }
    return position;
        
 }