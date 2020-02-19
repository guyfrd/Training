/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   con.h
 * Author: guy
 *
 * Created on November 7, 2018, 4:37 PM
 */

#ifndef CON_H
#define CON_H

#include <queue>
#include"buffer.h" 

class con {
public:
    con(buffer& b,int num);
 
    void consumeItem(); 
private:
    
    buffer& buff;
    int thread_num; 
};

#endif /* CON_H */

