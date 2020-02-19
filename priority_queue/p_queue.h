/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   
 * 
 * Author: guy
 *
 * Created on November 18, 2018, 2:44 PM
 */

#ifndef P_QUEUE_H
#define P_QUEUE_H
#include <iostream>     // std::cout
#include <functional>   // std::function, std::negate

#include <list>

template <typename T>
class p_queue {
public:
    p_queue(std::function<int(T,T)> compare);
    void enqueue(T item); 
    T dequeue();
    T front(); 
   
private:
    std::function<int(T,T)> compare_function; 
    std::list<T> queue; 
};

template <typename T>
p_queue<T>::p_queue(std::function<int(T,T)> compare)
{
     compare_function = compare; 
}

template <typename T>
void p_queue<T>::enqueue(T item)
{
       typename std::list<T>::reverse_iterator it = queue.rbegin(); 
        
        while(it != queue.rend() && compare_function(*it,item))
        {
            it++; 
        }
       
       if(it == queue.rend())
       {
           queue.push_front(item); 
       }
       else
       {
           queue.insert(it.base(), item); 
       }
        
} 

template <typename T>
T p_queue<T>::dequeue()
{
    
    T tmp = queue.front(); 
    queue.pop_front(); 
    return tmp; 
    
}

template <typename T>
T p_queue<T>::front()
{
    return queue.front(); 
}



#endif /* P_QUEUE_H */

