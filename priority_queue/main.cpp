/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: guy
 *
 * Created on November 18, 2018, 2:44 PM
 */


#include <iostream>     // std::cout
#include <functional>   // std::function, std::negate
#include"p_queue.h"
#include<string>
using namespace std;

/*
 * 
 */

bool comp(int a, int b)
{
    return b > a; 
}

struct Person{
    Person(std::string n, int a): name(n), age(a){;}
    std::string name;
    int age; 
    
};
bool Person_comper(Person* p1, Person* p2)
{
    return p2->age > p1->age; 
}

int main(int argc, char** argv) {
    
    Person* person_arr[6]; 
    
    person_arr[0] = new  Person("Mosh", 34); 
    person_arr[1] = new Person ("David", 16);
    person_arr[2] = new Person("Shlomo", 45);
    person_arr[3] = new Person("Oded", 15);
    person_arr[4] = new Person("Sapir", 100);
    person_arr[5] = new Person("Sara", 66);
    
    std::function<bool(int, int)> comperator = comp; 
    std::function<bool(Person*, Person*)> person_func = Person_comper;  
    p_queue<int> q(comperator);
    p_queue<Person*> q_person(person_func); 
    
    q.enqueue(2); 
    std::cout << q.front()<< std::endl;
    
    q.enqueue(5); 
    std::cout << q.front()<< std::endl;
    q.enqueue(1); 
    std::cout << q.front()<< std::endl;
    q.enqueue(7); 
    std::cout << q.front()<< std::endl;
    
    q.dequeue();  
    std::cout << q.front()<< std::endl;
    q.dequeue();  
    std::cout << q.front()<< std::endl;    
    
    
    
    q_person.enqueue(person_arr[0]); 
    std::cout << "Oldest person " << q_person.front()->name<<"\n"; 
    q_person.enqueue(person_arr[1]); 
    std::cout << "Oldest person " << q_person.front()->name<<"\n"; 
    q_person.enqueue(person_arr[2]);
    std::cout << "Oldest person " << q_person.front()->name<<"\n"; 
      q_person.enqueue(person_arr[3]);
    std::cout << "Oldest person " << q_person.front()->name<<"\n"; 
      q_person.enqueue(person_arr[4]);
    std::cout << "Oldest person " << q_person.front()->name<<"\n"; 
      q_person.enqueue(person_arr[5]);
    std::cout << "Oldest person " << q_person.front()->name<<"\n"; 
    return 0;
}

