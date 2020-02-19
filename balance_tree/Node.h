/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: guy
 *
 * Created on November 5, 2018, 1:43 PM
 */

#ifndef NODE_H
#define NODE_H

#include <vector>


class Node {
public:
    Node(int v);
    Node(const Node& orig);
    virtual ~Node();

        
    int data; 
    Node* left;
    Node* right; 
    int height; 
   
};






#endif /* NODE_H */

