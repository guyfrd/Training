/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.h
 * Author: guy
 *
 * Created on November 12, 2018, 3:25 PM
 */

#ifndef BUFFER_H
#define BUFFER_H
#include <iostream>
#include <mutex>              // std::mutex, std::unique_lock
#include <stack>          // std::stack

class buffer {
public:
    buffer();
    buffer(const buffer& orig);
    virtual ~buffer();
    int getReaderCount(); 
    void readerIn(); 
    void readerOut(); 
    void push(int v); 
    int peek(); 
    void lockReaderCountr();
    void unlockReaderCountr();
    void lockwrite();
    void unlockwrite();
    bool emty(); 
    
private:
    std::mutex reder_counter_mt; 
    std::mutex write_mt; 

    
    std::stack<int> s; 
    int reader_count; 
};

#endif /* BUFFER_H */

