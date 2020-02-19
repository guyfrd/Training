/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 12, 2018, 3:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <thread>         // std::thread
#include <unistd.h>
#include<vector>
#include"buffer.h"
#include <condition_variable> 
#include <mutex>              // std::mutex, std::unique_lock

using namespace std;

  std::condition_variable cv; 
 std::mutex mt; 
std::unique_lock<std::mutex> lck(mt);

class reader{
public:
    reader(buffer& b):buff(b)
    {}
    
    void read(){
        
        while(1)
        {
            
         
                    
            buff.lockReaderCountr(); 
            buff.readerIn(); 
            if(buff.getReaderCount() == 1)
            {
                buff.lockwrite(); 
            }
            buff.unlockReaderCountr(); 
            
            
           cv.wait(lck, [this](){
                if(buff.emty())
                    buff.unlockwrite(); 
                return !buff.emty();});
            
                    
            std::cout << "reader read "<< buff.peek()<<" thread num "<< std::this_thread::get_id()<<"\n"; 

            buff.lockReaderCountr(); 
            buff.readerOut();  
            

            if(buff.getReaderCount() == 0)
            {
                buff.unlockwrite(); 
            }
            buff.unlockReaderCountr(); 
            sleep(1);
        }
    }    
private: 
    buffer& buff; 
};

class writer{
public:
    writer(buffer& b): buff(b)
    {}
    void write()
    {
        int x;      
        
        
        while(1)
        {
            x =  (rand() % 10) + 1; 
            std::cout << "write " << x << "\n"; 
            buff.lockwrite(); 
            buff.push(x); 
            buff.unlockwrite(); 
           cv.notify_all();
            sleep(1); 
            
        }
        
    }
private: 
    buffer& buff; 
}; 





/*
 * 
 */
int main(int argc, char** argv) {
    
    buffer b; 
    
    std::vector<std::thread> threads;
    
    threads.push_back(std::thread(&writer::write,writer(b)));
    threads.push_back(std::thread(&reader::read,reader(b))); 
    threads.push_back(std::thread(&writer::write,writer(b)));
    threads.push_back(std::thread(&reader::read,reader(b)));
      threads.push_back(std::thread(&writer::write,writer(b)));
      threads.push_back(std::thread(&reader::read,reader(b)));
      threads.push_back(std::thread(&writer::write,writer(b)));

    
    
    threads.push_back(std::thread(&reader::read,reader(b)));
  
    
    
    for (auto& th : threads) th.join();
    

    
    
    return 0;
}

