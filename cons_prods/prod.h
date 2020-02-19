/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prod.h
 * Author: guy
 *
 * Created on November 7, 2018, 4:37 PM
 */

#ifndef PROD_H
#define PROD_H

#include <queue>
#include"buffer.h"
class prod {
public:
    prod(buffer& b, int num);

    void produceItem(); 
    
private:

    buffer& buff; 
     int thread_num; 
    
};

#endif /* PROD_H */

