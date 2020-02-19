/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.cpp
 * Author: guy
 * 
 * Created on November 12, 2018, 3:25 PM
 */

#include "buffer.h"

buffer::buffer() {
}

buffer::buffer(const buffer& orig) {
}

buffer::~buffer() {
}

int buffer::getReaderCount()
{
    return reader_count; 
}

void buffer::readerIn()
{
    reader_count++;
}
void buffer::readerOut()
{
    reader_count--;
}

void buffer::push(int v)
{
    s.push(v); 
}
int buffer::peek()
{
    return s.top(); 
}

void buffer::lockReaderCountr()
{
    reder_counter_mt.lock(); 
}

void buffer::unlockReaderCountr()
{
    reder_counter_mt.unlock(); 
}
void buffer::lockwrite()
{
    write_mt.lock(); 
}
void buffer::unlockwrite()
{
    write_mt.unlock(); 
}

bool buffer::emty()
{
    return s.empty(); 
}