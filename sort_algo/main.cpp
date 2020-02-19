/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 6, 2018, 4:17 PM
 */

#include <cstdlib>
#include"sortArray.h"
#include<vector>
#include<iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int arr[] ={22,5,3,1,6,7,1,8,1}; 
    int* p = arr; 
    
   sortArray sa(p,9);
   sa.print(); 
  // sa.insertion(); 
  // sa.selection();
   sa.thredMerge(0,8);
   
   //sa.quick(0,8);
   //sa.heap(9);
     
   //sa.counting(9); 
   sa.print(); 
    
    
    return 0;
}

