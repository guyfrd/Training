/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sortArray.cpp
 * Author: guy
 * 
 * Created on November 6, 2018, 4:32 PM
 */

#include "sortArray.h"
#include<vector>
#include<iostream>
#include <stdio.h> 
#include <string.h> 
#include<thread>

sortArray::sortArray(int* v,int size):arr(v),array_size(size) {
    
}

sortArray::sortArray(const sortArray& orig) {
}

sortArray::~sortArray() {
}

 void sortArray::bubble()
 {
     for(int i =0; i < array_size -1; i++)
     {
         for(int j =0; j < array_size-i -1; j++)
         {
             if((arr[j]) > (arr[j+1]))
             {
                 int temp = arr[j+1];
                 (arr[j+1]) = (arr[j]);
                 (arr[j]) = temp;
             }
         }
     }
 } 

 void sortArray::insertion()
 {  
     int key,j;
     
     for(int i =0; i < array_size; i++)
     {
         key = arr[i]; 
         j = i-1; 
         while(j >= 0 && arr[j] > key)
         {
             arr[j+1] = arr[j]; 
             j -= 1; 
         }
         arr[j+1] = key; 
         print();
     }
 } 
 
 void sortArray::thredMerge(int i, int j)
 {
     
     int mid = (i + j) / 2; 
     
     std::thread t1( &sortArray::merge, this,i,  mid); 
     std::thread t2(&sortArray::merge ,this,  mid+1,  j);
     
     t1.join(); 
     t2.join(); 
     
     
 }
 
 
 
 
 
 
void sortArray::merge(int l, int r)
{
    if(l-r == 0)
    return; 
    
    int i =l; 
    
    int k =0;
    int m= (l+r)/2; 
    int left_i =  l, right_i =  m+1; 
    int j =m+1; 
    int tmp_arr[r-l+1]; 
    
    std::cout<<  "l= "<< l<<", r= "<< r<<std::endl; 
    
    merge(l,m); 
    merge(m+1,r);

    while(k < r-l+1 )
    {
        
        if(arr[i] > arr[j] && j <= r  )
        {
            tmp_arr[k] = arr[j]; 
            j++; 
        }
        else
        {
            tmp_arr[k] = arr[i]; 
            i++;
        }
        k++;
    }
    
    for(int i =0; i < r-l +1; i++)
    {
        arr[l+i] = tmp_arr[i]; 
    }

    
}



 void sortArray::selection()
 {
     int min_i;
     
     for (int i =0; i<array_size - 1; i++)
     {
         min_i = i;
         for(int j = i+1 ; j <array_size; j++)
         {
             if(arr[j] < arr[min_i])
             {
                 min_i = j;
             }
            
         }
            int tmp = arr[min_i];
             arr[min_i] = arr[i]; 
             arr[i] = tmp;
             print(); 
     }
     
 }
 static void swap(int* a, int* b)
 {
     int temp = *a; 
     *a = *b; 
     *b = temp; 
 }
 
 
 int sortArray::partition(int* arr, int low, int high)
 {
     int pivot = arr[high]; 
     int i = (low -1); 
     int temp; 
       std::cout<<"pivot "<<pivot <<" low "<< low<<" high "<<high <<"\n";
     for(int j = low; j <= high -1; j++)
     {
         if(arr[j] <= pivot)
         {
             i++; 
             swap(&arr[j],&arr[i]);
         }
        print(); 
     }
     swap(&arr[i+1], &arr[high]); 
        std::cout<< i+1 <<" end partion \n";
      print(); 
   
     
     return i+1; 
 }
 
 void sortArray::quick(int low, int high)
 {
     if(low < high)
     {
  
         
         int partion = partition(arr, low, high); 
         
         quick(low,partion-1 ); 
         quick(partion +1, high); 
     }
 }

 
 void sortArray::heapify(int n, int i)
 {
     int large = i; 
     int l =2*i+1; 
     int r = 2*i +2; 
     
     if(l < n && arr[l] > arr[large] )
         large = l; 
     
     if(r< n && arr[r] > arr[large])
         large =r; 
     
     if(large != i)
     {
         swap(&(arr[i]), &(arr[large]));
         heapify(n, large); 
     }
     
 }
 
 void sortArray::heap(int n)
 {
     for(int i = n/2 -1; i>=0; i-- )
     {
         heapify(n,i); 
     }
     
     for(int i =n-1; i>=0; i--)
     {
         swap(&(arr[0]), &(arr[i]));
         heapify(i,0); 
     }
     
     
 }
 
 void sortArray::counting(int n)
 {
     int range = 25; 
     int count[range]; 
     int res[n] ; 
     memset(count, 0, range); 
     
   
     
     for(int i =0; i < n; i++)
     {
         ++count[arr[i]]; 
     }
          //print();
     for(int i = 1; i < range; i++)
     {
         count[i] = count[i] + count [i -1]; 
     }
          //print();
     for(int i = 0; i<n ; i++)
     {
         res[count[arr[i]]-1] = arr[i]; 
         count[arr[i]]--; 
     }
     //print();
     
     for(int i =0; i<n;i++)
     {
       //       print();
         arr[i] = res[i]; 
     }
 } 
 
 
void sortArray::print()
{
    for (int i =0; i<array_size; i++)
    {
        std::cout << arr[i] << " , "; 
    }
     std::cout << "\n"; 
}