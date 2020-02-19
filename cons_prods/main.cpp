/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 7, 2018, 4:06 PM
 */

#include <cstdlib>
#include<queue>
#include <thread>         // std::thread
#include <unistd.h>
#include<vector>
#include"prod.h"
#include"con.h"
#include"buffer.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    buffer b; 
   
    
    std::thread t_p1(&prod::produceItem,prod(b,1)); 
    std::thread t_p2(&prod::produceItem,prod(b,2));
    
    std::thread t_c1(&con::consumeItem,con(b,1)); 
    std::thread t_c2(&con::consumeItem,con(b,2));
    
    t_c1.join();
    t_c2.join();
    t_p1.join(); 
    t_p2.join(); 
    
    
    
    return 0;
}

