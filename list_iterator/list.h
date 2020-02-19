/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: guy
 *
 * Created on November 18, 2018, 5:40 PM
 */

#ifndef LIST_H
#define LIST_H
#include <utility>      // std::move
#include <stdexcept>
#include<iostream>
#include <initializer_list>

template <typename T> 
class list {
    
    private:
        struct Node;

public:
    
    struct iterator{
        iterator& operator++(int); 
        iterator& operator--(int);
        bool operator !=(const iterator& other); 
        iterator& operator=(T v); 
        T& operator*(); 
        Node * n; 
    };  
    
    struct const_iterator{       
        const_iterator& operator++(int)  ; 
        const_iterator& operator--(int) ;
        const T& operator*() const;
        bool operator !=(const const_iterator& other) const;
        Node * n; 
    };
    list(); 
    list(std::initializer_list<T> l);
    ~list(); 
    void push_back(T&& data);
    void push_back(T const& data);
    void push_front(T&& data);
    void push_front(T const& data);
    void pop_back();
    void pop_front();
    T& front(); 
    const T & front() const ;
    T& back(); 
    const T & back() const;
    
    iterator begin(); 
    const_iterator cbegin() const  ;
    
    iterator end(); 
    const_iterator cend() const;

private:
    struct Node{
        Node(T const & data, Node * next, Node* prev): data(data), next(next), prev(prev){
        std::cout<<"node ctor\n";}
        Node(T&& data, Node* next, Node* prev): data(std::move(data)), next(next), prev(prev){
        std::cout<<"node move ctor\n";}
        Node* next; 
        Node* prev; 
        T data; 
    };
    
    
    Node* head = nullptr; 
    Node* tail = nullptr; 
    int node_count = 0; 
};



template <typename T> 
list<T>::list()
{
    
}   

template <typename T> 
list<T>::list(std::initializer_list<T> l)
{
    for(auto& elm : l)
    {
        push_back(elm); 
    }
}


template <typename T> 
list<T>::~list()
{
    Node* tmp = head->next; 
    while(head)
    {
        tmp = head;
        head = head->next; 
        delete tmp; 
    }
}


/*----------------------PUSH BACK---------------------*/
template <typename T> 
void list<T>::push_back(T&& data)
{
    Node * new_node = new Node(std::move(data), nullptr, nullptr); 
    std::cout<<"push_back() r-value\n"; 
    
    if(head == nullptr)
    {
        head = new_node; 
    }
    if(tail != nullptr)
    {
        tail->next = new_node;
        new_node->prev = tail; 
    }
    
    tail = new_node; 
    node_count++; 
     
}
template <typename T> 
void list<T>::push_back(T const& data)
{
    Node * new_node = new Node(data, nullptr, nullptr); 
        std::cout<<"push_back() l-value\n"; 
    if(head == nullptr)
    {
        head = new_node; 
    }
    if(tail != nullptr)
    {
        tail->next = new_node;
        new_node->prev = tail; 
    }
    
    tail = new_node; 
    node_count++; 

}

template <typename T>
void list<T>::push_front(T&& data)
{
    Node * new_node = new Node(std::move(data), nullptr, nullptr); 
     if(tail == nullptr)
    {
        tail = new_node; 
    }
    if(head != nullptr)
    {
        head->prev = new_node;
        new_node->next = head; 
        
    }
    
    head = new_node; 
    node_count++; 
    std::cout<<"push_front r-vlaue()\n"; 
}
template <typename T>
void list<T>::push_front(T const& data)
{
    Node * new_node = new Node(data, nullptr, nullptr); 
     if(tail == nullptr)
    {
        tail = new_node; 
    }
    if(head != nullptr)
    {
        head->prev = new_node;
        new_node->next = head; 
    }
    head = new_node; 
    node_count++; 
     std::cout<<"push_front() lvalue\n"; 
}

template <typename T>
void list<T>::pop_back()
{
    if(tail == nullptr)
        return; 
    Node* tmp = tail; 
    
    tail = tail->prev; 
    
    if(tail != nullptr)
    {
        tail->next = nullptr; 
    }
    delete tmp; 
             std::cout<<"pop_front()\n"; 

}

template <typename T>
void list<T>::pop_front()
{
    if(head == nullptr)
        return; 
    Node* tmp = head; 
    
    head = head->next; 
    
    if(head != nullptr)
    {
        head->prev = nullptr; 
    }
    delete tmp; 
         std::cout<<"pop_front() const\n"; 
}

template <typename T>
T& list<T>::front()
{
    std::cout<<"front()\n"; 
    return head->data; 
}
template <typename T>
T const& list<T>::front() const 
{
    std::cout<<"front() const\n"; 
    return head->data;
}
template <typename T>
T& list<T>::back()
{
    std::cout<<"back()\n"; 
    return tail->data;
}
template <typename T>
T const& list<T>::back() const
{
    std::cout<<"back() const\n"; 
    return tail->data;
}



template <typename T>
typename list<T>::iterator list<T>::end()
{
    list<T>::iterator it; 
    it.n = tail->next;
   return it; 
}
template <typename T>
typename list<T>::const_iterator list<T>::cend() const
{
    list<T>::const_iterator it; 
    it.n = tail->next;
   return it; 
}

template <typename T>
typename list<T>::iterator list<T>::begin()
{
    list<T>::iterator it; 
    it.n = head;
   return it; 
}
template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const
{
    list<T>::const_iterator it; 
    it.n = head;
   return it; 
}

template <typename T>
T&  list<T>::iterator::operator*()
{
    return this->n->data; 
}

template <typename T>
const T&  list<T>::const_iterator::operator*() const
{
    return this->n->data; 

}
template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++(int) 
{
    this->n = this->n->next; 
    return *this; 
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator--(int)
{
    this->n = this->n->prev; 
    return *this; 
}

template <typename T>
typename list<T>::const_iterator& list<T>::const_iterator::operator++(int)  
{
    this->n = this->n->next; 
    return *this; 

}
template <typename T>
typename list<T>::const_iterator& list<T>::const_iterator::operator--(int) 
{
    this->n = this->n->prev; 
    return *this; 
}

template <typename T>
 bool list<T>::iterator::operator!=(const list<T>::iterator& other)
{
    return other.n != this->n; 
}
template <typename T>
 bool list<T>::const_iterator::operator!=(const list<T>::const_iterator& other) const
{
    return other.n != this->n; 
}



 template <typename T>
typename list<T>::iterator& list<T>::iterator::operator=(T v)
 {
     this->n->data = v;
 }
#endif /* LIST_H */

