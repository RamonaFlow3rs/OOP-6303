/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegularPentagon.cpp
 * Author: ekulikov
 * 
 * Created on 15 марта 2018 г., 17:33
 */

#include "RegularPentagon.h"
#include <cmath>
#include <iostream>

using namespace std;


RegularPentagon::RegularPentagon(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d, pair<double, double> e) : _a(a), _b(b), _c(c), _d(d) , _e(e) {
  
}


RegularPentagon::~RegularPentagon() {
}


string RegularPentagon::getId(){
    char buff[20];
    snprintf(buff, sizeof(buff), "%p", this);
    return string(buff);
}

Point RegularPentagon::positionCentre(){
    Point A; Point C;
  
    A.x = min((min(_a.first, _b.first), min(_c.first, _d.first)), _e.first);
    A.y = min((min(_a.second, _b.second), min(_c.second, _d.second)), _e.second);
    
    C.x = max((max(_a.first, _b.first), max(_c.first, _d.first)), _e.first);
    C.y = max((max(_a.second, _b.second), max(_c.second, _d.second)), _e.second);   
    
    
    double xc = (C.x - A.x) / 2;
    double yc = (C.y - A.y) / 2;
    Point centre;
    centre.x = xc;
    centre.y = yc;
    return centre;
}


void RegularPentagon::move(Point newP){
    Point centre = positionCentre();
    
    double movedX = newP.x ;
    double movedY = newP.y;
    _a.first += movedX; _a.second += movedY;
    _b.first += movedX; _b.second += movedY;
    _c.first += movedX; _c.second += movedY;        
    _d.first += movedX; _d.second += movedY;
}


void RegularPentagon::turn(double angle){
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
    
    
    tmp.x = _e.first*cos(angle) - _e.second*sin(angle);
    tmp.y = _e.first*sin(angle) + _e.second*cos(angle); 
    _e.first = tmp.x;
    _e.second = tmp.y;
}


void RegularPentagon::scale(double factor){
    _a.first *= factor; _a.second *= factor;
    _b.first *= factor; _b.second *= factor;
    _c.first *= factor; _c.second *= factor;
    _d.first *= factor; _d.second *= factor;
    _e.first *= factor; _e.second *= factor;
}


void RegularPentagon::setColor(std::string color) {
    _color = color;
}


string RegularPentagon::getColor() {
    return _color;
}


ostream& operator<<(ostream& os, const RegularPentagon& pent){
    os << '(' << pent._a.first << ':' << pent._a.second << ')' << endl << '(' << pent._b.first << ':' << pent._b.second << ')' << endl << '(' << pent._c.first << ':' << pent._c.second << ')' << endl << '(' << pent._d.first << ':' << pent._d.second << ')' << endl << '(' << pent._e.first << ':' << pent._e.second << ')' << endl;    
    return os;

}
