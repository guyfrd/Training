/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.cpp
 * Author: guy
 * 
 * Created on November 7, 2018, 4:21 PM
 */

#include <iostream>

#include "buffer.h"

buffer::buffer() {
   
}

buffer::buffer(const buffer& orig) {
}

buffer::~buffer() {
}

void buffer::push(int item)
{
         std::unique_lock<std::mutex> lck (mtx);
         
         cv.wait(lck, [this](){

             if(q.size() >=10)
                 std::cout<< "push-buffer is full - wait "<<q.size()<<" \n"; 
             
              return q.size() <10;});
              
         std::cout<< "push "<< item<<"\n"; 
        
         q.push(item); 
         lck.unlock(); 
         cv.notify_all(); 
}

int buffer::pop()
{
    int item; 
     std::unique_lock<std::mutex> lck (mtx);
     //predicate which returns ​false if the waiting should be continued. 
     cv.wait(lck, [this](){
             if(q.empty())
                 std::cout<<"pop- queue empty" << q.empty()<<" - wait\n";
             return 
                     !q.empty();});  
                     
     item = q.front(); 
     std::cout<< "pop "<< item<<"\n";
     q.pop(); 
     lck.unlock(); 
     cv.notify_all(); 
     return item; 
}

