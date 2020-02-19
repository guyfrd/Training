/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   server.cpp
 * Author: guy
 * 
 * Created on November 20, 2018, 2:42 PM
 */

#include "server.h"


void server::attach(observer* ob)
{
    obs_list.push_back(ob); 
}

void server::update(int t)
{
    for(auto ob : obs_list)
    {
        ob->update(t); 
    }
}