/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sortArray.h
 * Author: guy
 *
 * Created on November 6, 2018, 4:32 PM
 */

#ifndef SORTARRAY_H
#define SORTARRAY_H
#include<vector>


class sortArray {
public:
    sortArray(int* v, int  s);
    sortArray(const sortArray& orig);
    virtual ~sortArray();
    void bubble(); 
    void insertion(); 
     void merge(int i, int j); 
      void selection();
      void quick(int low, int high); 
       int partition(int* arr, int low, int high);
       void heapify(int n, int i);
       void heap(int n); 
       void thredMerge(int i, int j);       
       void counting(int n); 
    void print(); 
private:
    int* arr; 
    int array_size; 
    
};

#endif /* SORTARRAY_H */

