/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 20, 2018, 2:35 PM
 */

#include <cstdlib>
#include<iostream>
#include"observer.h"
#include"server.h"

using namespace std;


class listenA:public observer{
public:
    
    virtual void update(int t)
    {
        std::cout<<"listenA update:"<< t<<"\n"; 
    }
    
};

class listenB:public observer{
public:
    
    virtual void update( int t)
    {
        std::cout<<"listenB update:"<< t<<"\n"; 
    }
    
};


int main(int argc, char** argv) {
    
//    observer<int>* a = new listenA; 
//    observer<int>* b = new listenB; 
    observer* o_int = new listenA; 
     observer* o_int2 = new listenB ;
    server s; 
    
    s.attach(o_int); 
    s.attach(o_int2);
   
    s.update(3);
    return 0;
}

