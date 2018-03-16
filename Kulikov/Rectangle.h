/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rectangle.h
 * Author: ekulikov
 *
 * Created on 8 августа 2017 г., 16:48
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <utility>
#include <iostream>

using namespace std;

class Rectangle : public Shape {
public:
    
    Rectangle(pair <double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d);
    virtual ~Rectangle();
    
    
    void move(Point newP) override;
    void turn(double angle) override;
    void scale(double factor) override;
    void setColor(std::string color) override;
    string getId() override;
    string getColor() override;
    friend ostream& operator<<(ostream& os, const Rectangle& rect);
    
    
private:     
    Point positionCentre();
    
    
private:
    pair <double, double> _a;
    pair <double, double> _b;
    pair <double, double> _c;
    pair <double, double> _d;
    string _color;

};

#endif /* RECTANGLE_H */

