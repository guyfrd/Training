/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bitset.h
 * Author: guy
 *
 * Created on November 25, 2018, 10:02 AM
 */

#ifndef BITSET_H
#define BITSET_H

#include <iostream>
#include <algorithm>       //transform
#include<vector>
#include <stdexcept>      // std::out_of_range

template<std::size_t N> 
class bitset {
    private:
          class proxyBitset;
    public:
  
    bitset();
    bitset(size_t v); 
    bitset(const bitset& other);

    
    bool operator==(const bitset<N>& other) const; 
    bool operator!=(const bitset<N>& other) const;
    
    /*Element access */
    bool operator[](std::size_t pos) const; 
    proxyBitset operator[](std::size_t pos); 
    
    std::size_t count() const;  
    
    bitset<N> & operator&=(const bitset<N>& other); 
    bitset<N> & operator^=(const bitset<N>& other); 
    bitset<N> & operator|=(const bitset<N>& other); 
    bitset<N> & operator~(); 
    
	
    bitset<N>& operator<<=( std::size_t pos );
    bitset<N>& operator>>=( std::size_t pos );
    bitset<N>& operator<<( std::size_t pos );
    bitset<N>& operator>>( std::size_t pos );
    bitset<N>& set( std::size_t pos, bool value = true );
    bool get(std::size_t pos) const;

    private:
        /*------proxy---------*/ 
    class proxyBitset{
    public: 
        proxyBitset(bitset<N>& bit_set, size_t pos); 
        proxyBitset& operator=(bool x); 
        proxyBitset& operator=(const proxyBitset& x); 
        operator bool() const;
    private:    
        size_t pos; 
        bitset<N>& bit_set;
    };
    /*--------------------*/
    
    
        static const int BIT_IN_SIZE_T = 8 * sizeof(std::size_t); 
        static const int ARR_SIZE = ((N + BIT_IN_SIZE_T -1)& (~(BIT_IN_SIZE_T-1)))/BIT_IN_SIZE_T; 
        std::vector<size_t> bit_arr;
};



template<std::size_t N>
bitset<N>::bitset(): bit_arr(ARR_SIZE,0)
{
    std::cout<< "cons - ARR_SIZE  = "<< ARR_SIZE<< std::endl;

}


template<std::size_t N>
bitset<N>::bitset(size_t v) : bit_arr(ARR_SIZE,0)
{
    size_t a =1; 
    for(int i =0; i <BIT_IN_SIZE_T; i++)
    {
        set(i, v & a); 
        a <<= 1; 
    }
}

template<std::size_t N>
bool bitset<N>::operator==(const bitset<N>& other) const
{
    return bit_arr == other.bit_arr; 
}

template<std::size_t N>
bool  bitset<N>::operator!=(const bitset<N>& other) const
{
       return bit_arr != other.bit_arr; 
}




template<std::size_t N> 
bitset<N>& bitset<N>::operator~()
{
    
    for(int i= 0 ; i < N; i++)
        set(i, !get(i)); 
    
    
    return *this;
}

template<std::size_t N> 
std::ostream& operator<<(std::ostream& os, const bitset<N>& bit_set)
{
    size_t size = 8*sizeof(size_t); 
    
    for(int i =N-1; i >= 0 ; i--)
    {
          os<< bit_set.get(i);
         if(i%64 == 0 && i != 0)
            os << " ";
        
    }
    return os;
}

template<std::size_t N> 
 bool  bitset<N>::get(std::size_t pos) const
{
     size_t i =/* N - 1 -*/ pos ;
     if(pos >= N)
         throw std::out_of_range ("get()- out_of_range");
     
     return ((1UL<< (i % BIT_IN_SIZE_T) & bit_arr[i / BIT_IN_SIZE_T]));
}



template<std::size_t N>
bitset<N>& bitset<N>::set(std::size_t pos, bool value)
{
    size_t i =/* N - 1 - */pos ;
    if(pos >= N)
        throw std::out_of_range ("set()- out_of_range");
    
    bit_arr[i/BIT_IN_SIZE_T] = (bit_arr[i/BIT_IN_SIZE_T] & ~(1UL << (i%BIT_IN_SIZE_T))) |
                        ((size_t)value << i%BIT_IN_SIZE_T);
    return *this; 
}


template<std::size_t N> 
bool bitset<N>::operator[](std::size_t pos) const
{
    return get(pos); 
}

template<std::size_t N> 
typename bitset<N>::proxyBitset  bitset<N>::operator[](std::size_t pos)
{
    return proxyBitset(*this, pos);
}

template<std::size_t N> 
 bitset<N>&  bitset<N>::operator&=(const bitset<N>& other)
{
    std::transform(bit_arr.begin(), bit_arr.end(),other.bit_arr.begin(),bit_arr.begin(), [](size_t x, size_t y) { return x & y ;});
    
    return *this; 
}
template<std::size_t N> 
 bitset<N>&  bitset<N>::operator|=(const bitset<N>& other)
{
    std::transform(bit_arr.begin(), bit_arr.end(),other.bit_arr.begin(),bit_arr.begin(), [](size_t x, size_t y) { return x | y ;});
    return *this; 
}
template<std::size_t N> 
 bitset<N>&  bitset<N>::operator^=(const bitset<N>& other)
{
    std::transform(bit_arr.begin(), bit_arr.end(),other.bit_arr.begin(),bit_arr.begin(), [](size_t x, size_t y) { return x ^ y ;});
    return *this; 
}


template<std::size_t N>
bitset<N>& bitset<N>::operator<<=( std::size_t pos )
{
    
    int a = pos / BIT_IN_SIZE_T; 
    size_t x = pos %  bitset<N>::BIT_IN_SIZE_T;  
    size_t start_in = pos / bitset<N>::BIT_IN_SIZE_T;  
    size_t tmp_pos = pos; 
    int i = ARR_SIZE   - 1; 

  std::transform(bit_arr.rbegin() + start_in,
                        bit_arr.rend() -1 , 
                        bit_arr.rbegin() + start_in +1,
                         bit_arr.rbegin(),
                        [=](size_t a, size_t b){
                              if(x % 64 == 0)
                                  return a; 
                              
                              return (a << x) | (b >> (bitset<N>::BIT_IN_SIZE_T -x)); 
                        });
                       
                        bit_arr[start_in] = bit_arr[0] << x;
                      
                        for(int i =0; i < start_in; i++)
                         bit_arr[i] = 0; 
                        

}

template<std::size_t N>
bitset<N>& bitset<N>::operator>>=( std::size_t pos )
{
    
    int a = pos / BIT_IN_SIZE_T; 
    size_t x = pos %  BIT_IN_SIZE_T;  
    size_t start_in =pos / BIT_IN_SIZE_T;  
    size_t tmp_pos = pos; 
 
    
    std::transform(bit_arr.begin() + start_in,
                        bit_arr.end() -1 , 
                        bit_arr.begin() + start_in +1,
                         bit_arr.begin(),
                        [=](size_t a, size_t b){
                              if(x % 64 == 0)
                                  return a; 
                              
                              return (a >> x) | (b << (BIT_IN_SIZE_T -x)); 
                        });
                       
                        bit_arr[ARR_SIZE -1 - start_in] = bit_arr[ARR_SIZE -1] >> x;
                      
                        for(int i =ARR_SIZE - 1; i > ARR_SIZE -1- start_in ; i--)
                            bit_arr[i] = 0; 
                        

}




template<std::size_t N>
bitset<N>& bitset<N>::operator<<( std::size_t pos )
{
    
}

template<std::size_t N>
bitset<N>& bitset<N>::operator>>( std::size_t pos )
{
    
}  

/*---------bitset proxy----------------------------------------------------------*/

template<std::size_t N> 
bitset<N>::proxyBitset::proxyBitset(bitset<N>& bit_set, size_t pos): pos(pos), bit_set(bit_set)
{}

template<std::size_t N> 
typename bitset<N>::proxyBitset& bitset<N>::proxyBitset::operator=(bool x)
{
    bit_set.set(pos,x); 
    return *this; 
}
template<std::size_t N> 
typename bitset<N>::proxyBitset& bitset<N>::proxyBitset::operator=(const proxyBitset& x)
{
    bit_set.set(pos, (bool)(x));
}

template<std::size_t N> 
bitset<N>::proxyBitset::operator bool() const
{
    return bit_set.get(pos); 
}
#endif /* BITSET_H */

