/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 25, 2018, 9:58 AM
 */

#include <cstdlib>
#include<iostream>
#include"bitset.h"
//#include<bitset>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    bitset<128> b1; 
    bitset<128> b2;
    
    std::cout<< b1 << endl;
    try{
        //std::cout<< b1.get(300) << endl;
    }
    catch(const std::out_of_range& oor){
     //   std::cout << "Out of Range error: " << oor.what() << '\n';
    }
    
    b1[2] = 1; 
    b2[2] = 1; 
    b1[1] = 1; 
    cout<<"b1 \n"<< b1 << endl;
    cout<<"b2 \n"<< b2 << endl;
    b1 &= b2;
    cout<<"b1 &= b2 \n"<< b1 << endl;
    b2[0] = 1; 

    cout<< endl; 
    cout<<"b1 \n"<< b1 << endl;
    cout<<"b2 \n"<< b2 << endl;
    b1 |= b2;
    cout<<"b1 |= b2 \n"<< b1 << endl;
    
    cout<< endl; 
    b2[3] = 1; 
    cout<<"b1 \n"<< b1 << endl;
    cout<<"b2 \n"<< b2 << endl;
    b1 ^= b2;
    cout<<"b1 ^= b2 \n"<< b1 << endl;
    
    cout<< endl; 
    b1[68] =1; 
    b1[64] =1; 
    b1[4] =1; 
     b1[0] =1; 
   
    cout<<"b1 \n"<< b1 << endl;
   
    
    
   bitset<192> b3;
   b3[0] = 1;
   b3[1] = 1; 
   b3[63] = 1; 
    b3[64] = 1; 
       b3[127] = 1; 
  //b3[66] = 1; 
   
   cout<<"b3 \n"<< b3 << endl;
   
   b3 <<=3;
   cout<<"b3 <<= 3 \n"<< b3 << endl;
   b3 >>=65;
   cout<<"b3 >>= 65 \n"<< b3 << endl;
   
    cout<<"~b3 : \n"<< ~b3 << endl;
    
    bitset<192> b4;
    
    cout<<"b3 == b4 : "<< (b3 == b4) << endl;
    cout<<"b3 != b4 : "<< (b3 != b4) << endl;
    
    bitset<1> b5; 
    bitset<1> b6;
    
    ~b5; 
    b6[0] = 1; 
     cout<<"b5 : "<< b5 << endl;
      cout<<"b6 : "<< b6 << endl;
    std::cout << (b5 == b6) << std::endl; 
    
   return 0;
}

