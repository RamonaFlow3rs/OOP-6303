/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exc.cpp
 * Author: ekulikov
 * 
 * Created on 22 марта 2018 г., 21:24
 */

#include "exc.h"
#include <iostream>

using namespace std;

void badRectangleException::print(){
    cout<<"This is not a Rectangle!" <<endl;
}
void badTrapezeException::print(){
    cout<<"This is not a Trapeze!"<<endl;
}

void badPentagonException::print(){
    cout<<"This is not a Pentagon!"<<endl;
}

