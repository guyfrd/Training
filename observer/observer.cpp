/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   observer.cpp
 * Author: guy
 * 
 * Created on November 20, 2018, 2:36 PM
 */

#include "observer.h"




 observer::~observer()
{}

void observer::update(int t)
{
    std::cout<<"update " << t << "\n"; 
}

