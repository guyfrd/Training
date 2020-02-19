/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   con.cpp
 * Author: guy
 * 
 * Created on November 7, 2018, 4:37 PM
 */


#include<iostream>
#include <queue>
#include <unistd.h>

#include "con.h"


con::con(buffer& b, int num):buff(b),  thread_num(num){
}

void con::consumeItem()
{
    int item; 
    
    while(1)
    {      
        std::cout<<"cons num:" << thread_num;
        item = buff.pop();
        sleep(1); 
        
   }
        
}
    
