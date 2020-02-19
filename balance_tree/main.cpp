/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 5, 2018, 1:40 PM
 */

#include <cstdlib>
#include <iostream>
#include<vector>
#include"Tree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Tree t(5); 
    Node* root = t.getRoot(); 
    
    t.insert(root,2); 
    t.insert(root,6);
    t.insert(root,1); 
    t.insert(root,3);
    t.insert(root,4);
    t.insert(root,8);
    t.insert(root,7); 
    
    std::cout << "balanced factor: " << t.balanced(root)<<std::endl; 
    // t.insert(root,10);
    //t.insert(root,20); 
      //  t.insert(root,30);
        
    
    //std::cout << "balanced factor: " << t.balanced(root)<<std::endl; 
     // t.insert(root,25);
      int m; 
      t.findMax(root,&m);
        std::cout << "maxr: " << m <<std::endl; 
    /*
    int d = t.depth(t.getRoot()); 
    
    std::vector<Node*> list(d); 
    t.treeToLink(list,t.getRoot(),1); 
    int size =list.size(); 
    Node* trav;  
    for(int i = 0; i < size; i++)
    {
        std::cout<<"level:"<< i<< std::endl;
        trav = list[i]; 
        while(trav != NULL)
        {
            std::cout<<"list item:"<<trav->data<<std::endl; 
            trav= trav->right; 
        }
        
    }
    */
    
    return 0;
}

