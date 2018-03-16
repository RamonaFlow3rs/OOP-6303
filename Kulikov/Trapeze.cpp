/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trapeze.cpp
 * Author: ekulikov
 * 
 * Created on 15 марта 2018 г., 17:31
 */

#include "Trapeze.h"
#include <cmath>
#include <iostream>

using namespace std;

Trapeze::Trapeze(std::pair <double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d): _a(a), _b(b), _c(c), _d(d)  {
    
}


Trapeze::~Trapeze() {
}


string Trapeze::getId(){
    char buff[20];
    snprintf(buff, sizeof(buff), "%p", this);
    return string(buff);
}


Point Trapeze::positionCentre(){
    Point A; Point B; Point C; Point D;
  
    A.x = std::min(std::min(_a.first, _b.first), std::min(_c.first, _d.first));
    A.y = std::min(std::min(_a.second, _b.second), std::min(_c.second, _d.second));
    
    C.x = std::max(std::max(_a.first, _b.first), std::max(_c.first, _d.first));
    C.y = std::max(std::max(_a.second, _b.second), std::max(_c.second, _d.second));   
    
    B.x = A.x;
    B.y = C.y;
    
    D.x = C.x;
    D.y = A.y;
    
    double xc = (C.x - A.x) / 2;
    double yc = (C.y - A.y) / 2;
    Point centre;
    centre.x = xc;
    centre.y = yc;
    return centre;
}


void Trapeze::move(Point newP) {
    Point centre = positionCentre();
    
    double movedX = newP.x - centre.x;
    double movedY = newP.y - centre.y;
    _a.first += movedX; _a.second += movedY;
    _b.first += movedX; _b.second += movedY;
    _c.first += movedX; _c.second += movedY;        
    _d.first += movedX; _d.second += movedY;
}

void Trapeze::turn(double angle){
    angle *= M_PI/180;
    
    Point tmp;
    
    tmp.x = _a.first*cos(angle) - _a.second*sin(angle);
    tmp.y = _a.first*sin(angle) + _a.second*cos(angle); 
    _a.first = tmp.x;
    _a.second = tmp.y;
    
    
    tmp.x = _b.first*cos(angle) - _b.second*sin(angle);
    tmp.y = _b.first*sin(angle) + _b.second*cos(angle); 
    _b.first = tmp.x;
    _b.second = tmp.y;
    
    
    tmp.x = _c.first*cos(angle) - _c.second*sin(angle);
    tmp.y = _c.first*sin(angle) + _c.second*cos(angle); 
    _c.first = tmp.x;
    _c.second = tmp.y;
    
    
    tmp.x = _d.first*cos(angle) - _d.second*sin(angle);
    tmp.y = _d.first*sin(angle) + _d.second*cos(angle); 
    _d.first = tmp.x;
    _d.second = tmp.y;    
}


void Trapeze::scale(double factor){
    _a.first *= factor; _a.second *= factor;
    _b.first *= factor; _b.second *= factor;
    _c.first *= factor; _c.second *= factor;
    _d.first *= factor; _d.second *= factor;

}


void Trapeze::setColor(std::string color) {
    _color = color;
}


string Trapeze::getColor() {
    return _color;
}


ostream& operator<<(ostream& os, const Trapeze& trap){
    os << '(' << trap._a.first << ':' << trap._a.second << ')' << endl << '(' << trap._b.first << ':' << trap._b.second << ')' << endl << '(' << trap._c.first << ':' << trap._c.second << ')' << endl << '(' << trap._d.first << ':' << trap._d.second << ')' << endl;
            
    return os;

}