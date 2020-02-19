/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   reader.h
 * Author: guy
 *
 * Created on November 12, 2018, 3:22 PM
 */

#ifndef READER_H
#define READER_H
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <stack>          // std::stack


class reader {
public:
    reader();
    reader(const reader& orig);
    virtual ~reader();
    int getReaderCount(); 
    void readerIn(); 
    void readerOut(); 
    void push(int v); 
    int peek(); 
    
private:
    std::stack<int> s; 
    int reader_count; 
};

#endif /* READER_H */

