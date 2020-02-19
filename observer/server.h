/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   server.h
 * Author: guy
 *
 * Created on November 20, 2018, 2:42 PM
 */

#ifndef SERVER_H
#define SERVER_H
#include<list> 
#include"observer.h"


class server {
public:
   
    void attach(observer* ob); 
    void update(int t); 
private:
    std::list<observer*> obs_list;  
};

#endif /* SERVER_H */

