/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prod.cpp
 * Author: guy
 * 
 * Created on November 7, 2018, 4:37 PM
 */

#include <queue>
#include <stdlib.h> 
#include<iostream>
#include <unistd.h>

#include "prod.h"

prod::prod(buffer& b,int num):buff(b),thread_num(num) {
}


void prod::produceItem()
{
    int x = (rand() % 10) + 1; 
    
    while(1)
    {
        std::cout<<"prod num:" << thread_num;
        x = (rand() % 10) + 1; 
       // std::cout << "produce:" << x << "\n"; 
        buff.push(x);
        sleep(1); 
    }
}