/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.h
 * Author: guy
 *
 * Created on November 7, 2018, 4:21 PM
 */

#ifndef BUFFER_H
#define BUFFER_H
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <queue>


class buffer {
public:
    buffer();
    buffer(const buffer& orig);
    void push(int item); 
    int pop(); 
    virtual ~buffer();
    
private:
    std::condition_variable cv;
    std::mutex mtx;
    std::queue<int> q; 
};

#endif /* BUFFER_H */

