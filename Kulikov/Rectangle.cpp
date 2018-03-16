/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangle.cpp
 * Author: ekulikov
 * 
 * Created on 8 августа 2017 г., 16:48
 */

#include "Rectangle.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle(pair <double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d) : _a(a), _b(b), _c(c), _d(d) {
    
}

Rectangle::~Rectangle() {
}


string Rectangle::getId(){
    char buff[20];
    snprintf(buff, sizeof(buff), "%p", this);
    return string(buff);
}

Point Rectangle::positionCentre(){
    double xc = (_c.first - _a.first) / 2;
    double yc = (_c.second - _a.second) / 2;
    Point centre;
    centre.x = xc;
    centre.y = yc;
    return centre;
}

void Rectangle::move(Point newP) {
    
    Point centre = positionCentre();
    
    double movedX = newP.x - centre.x;
    double movedY = newP.y - centre.y;
    _a.first += movedX; _a.second += movedY;
    _b.first += movedX; _b.second += movedY;
    _c.first += movedX; _c.second += movedY;        
    _d.first += movedX; _d.second += movedY;        
}


void Rectangle::turn(double angle){
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


void Rectangle::scale(double factor){
    _a.first *= factor; _a.second *= factor;
    _b.first *= factor; _b.second *= factor;
    _c.first *= factor; _c.second *= factor;
    _d.first *= factor; _d.second *= factor;
}

void Rectangle::setColor(std::string color) {
    _color = color;
}

string Rectangle::getColor() {
    return _color;
}

ostream& operator<<(ostream& os, const Rectangle& rect){
    os << '(' << rect._a.first << ':' << rect._a.second << ')' << endl << '(' << rect._b.first << ':' << rect._b.second << ')' << endl << '(' << rect._c.first << ':' << rect._c.second << ')' << endl << '(' << rect._d.first << ':' << rect._d.second << ')' << endl;
            
    return os;

}