/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: guy
 *
 * Created on November 5, 2018, 1:42 PM
 */

#ifndef TREE_H
#define TREE_H
#include<vector>  
#include "Node.h"


class Tree {
public:
    Tree(int v); 
    Tree(const Tree& orig);
    ~Tree();
    Node*  insert(Node* n,int data); 
    int depth(Node* n);
    int balanced(Node* n);
    Node* getRoot();
    int height(Node* n);
    void treeToLink(std::vector<Node*>& list, Node* n, int depth);
    Node* rightRotate(Node* n);
    Node* leftRotate(Node* n);
    int findMax(Node* n, int * max); 
private:
    Node*  root; 
};



#endif /* TREE_H */

