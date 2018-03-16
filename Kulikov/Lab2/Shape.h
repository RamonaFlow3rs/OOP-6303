/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IFigures.h
 * Author: ekulikov
 *
 * Created on 7 августа 2017 г., 17:00
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

struct Point {
 double x;
 double y;

 Point(): x(0.0), y(0.0) {}
};

class Shape {
public:
    virtual void move(Point newP) = 0;
    virtual void turn(double angle) = 0;
    virtual void scale(double factor) = 0;
    virtual void setColor(string color) = 0;
    virtual string getColor() = 0;
    virtual string getId() = 0;

};

#endif /* SHAPE_H */

