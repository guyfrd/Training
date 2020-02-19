/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: guy
 * 
 * Created on November 5, 2018, 1:42 PM
 */

#include <iostream>
#include <algorithm>    // std::max
#include <cmath>        // std::abs
     
#include "Tree.h"
#include"Node.h"

Tree::Tree(int v){
    root = new Node(v); 
}

Tree::Tree(const Tree& orig) {
}

Tree::~Tree() {
}

int Tree::height(Node* n)
{
    if(n == NULL)
    {
        return 0; 
    }
    return n->height;
}


Node*  Tree::insert(Node* n, int data)
{
    Node* prev; 

    Node* new_node; 
    int next_child;
    
    if(n == NULL)
    {
        new_node = new Node(data); 
        return (new_node);
    }
    
   
        std::cout <<"n->data:"<< n->data<<" data:"<<data<<std::endl; 
        if(n->data < data)
        {
                n->right  = insert(n->right ,data); 
        }
        else if(n->data> data)
        {
             n->left = insert(n->left,data);          
         }
        else
        {
            return n; 
        }
        
        n->height = 1 + std::max(height(n->left),height(n->right));
        
        
        int balance_factor = balanced(n); 
        
        //right-right
        if(balance_factor > 1 && n->left->data > data)
        {
            
        }
        if(balance_factor< -1 && n->right->data < data)
        {
            //left-left
        }
        
        if(balance_factor > 1 && data < n->left->data )
        {
            //left-right
        }
        if(balance_factor < -1 && n->right->data > data)
        {
            //right-left
        }
}



 Node* Tree::rightRotate(Node* n)
{
    Node* left = n->left; 
    Node* left_right = left->right;
    
    left->right = n; 
    n->left = left_right; 
    
    n->height = std::max(Tree::height(n->left), Tree::height(n->right));
    left->height = std::max(Tree::height(left->left), Tree::height(left->right));
    
    return left;
}


 Node* Tree::leftRotate(Node* n)
{
    Node* right = n->right; 
    Node* right_left = right->left;
    
    right->left = n; 
    n->right = right_left; 
    
    n->height = std::max(Tree::height(n->left), Tree::height(n->right));
    right->height = std::max(height(right->left), height(right->right));
    
    return right;
}




Node* Tree::getRoot()
{
    return root; 
}

 int Tree::depth(Node* n){
       
     if(n == NULL)
         return 0; 
     
     return 1+std::max(depth(n->left), depth(n->right) );
 
 } 

 
 int Tree::balanced(Node* n)
 { 
  
     return height(n->left) - height(n->right); 
 }
 
 
 
 
 
 void Tree::treeToLink(std::vector<Node*>& list, Node* n, int depth)
 {
        
     if(n == NULL)
         return; 
     
     treeToLink(list,n->left, depth+1); 
     treeToLink(list,n->right, depth+1);
     
     if(list[depth-1] == NULL)
     {
         Node* tmp = new Node(n->data); 
         //list.insert(list.begin()+depth-1,  ); 
         list[depth-1] = tmp; 
         return; 
     }
     
     Node * trav = list[depth-1]; 
     while(trav->right != NULL)
     {
         trav = trav->right; 
     }
     
     trav->right = n;  
     
 }
 
 
 int Tree::findMax(Node* n, int * max)
 {
     int left_res, right_res,local_max; 
     
     if(n == NULL)
     {
         return 0; 
     }
     
     left_res = findMax(n->left,max) ; 
     right_res = findMax(n->right, max); 
     
     local_max =  std::max(std::max(right_res, left_res)+ n->data,n->data);
     
     
     if(local_max > *max)
     {
         *max= local_max; 
     }
     
     return local_max; 
 }