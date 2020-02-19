/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 18, 2018, 5:38 PM
 */

#include <cstdlib>
#include<iostream>
#include<string>
#include "list.h"

using namespace std;

/*
 * 
 */


struct Person{
    Person(std::string n, int a): name(n), age(a){;}
    std::string name;
    int age; 
    
};

int foo()
{
    return 435; 
}

int main(int argc, char** argv) {
    
    list<int> l_int; 

   const list<int> cl{5,2,5,6,7}; 
    for(list<int>::const_iterator it = cl.cbegin(); it != cl.cend(); it++)
    {
        std::cout<< *it<<"\n"; 
    }
   
   
    
    int x = 3; 
    l_int.push_back(1);        
    l_int.push_back(2);        
    l_int.push_back(x);      
   
   
    
    for(list<int>::iterator it = l_int.begin(); it != l_int.end(); it++)
    {
        std::cout<< *it<<"\n"; 
    }
    
    list<int>::iterator it = l_int.begin(); 
    it =5;
    
     std::cout<< *it<<"\n"; 
     
         for(list<int>::iterator it = l_int.begin(); it != l_int.end(); it++)
    {
        std::cout<< *it<<"\n"; 
    }
    

     
    const list<int>::const_iterator cit = l_int.cbegin();
    const list<int>::const_iterator cit2 = l_int.cbegin();
    bool d = cit != cit2 ;
    std::cout<< "const_iterator- != "<< d <<"\n";
    std::cout<< "const_iterator- "<< *cit<<"\n";
      
    
    list<std::string> ls; 
    std::string str = "guy"; 
    
    ls.push_front(str);
    ls.push_front("secong");
    ls.push_front(std::move(str));
    
    std::cout<< "str "<< str<<"\n"; 
    
   
      
    
    
    return 0;
}

