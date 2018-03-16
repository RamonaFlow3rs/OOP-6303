/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trapeze.h
 * Author: ekulikov
 *
 * Created on 15 марта 2018 г., 17:31
 */

#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "Shape.h"
#include <utility>

using namespace std;

class Trapeze : public Shape {
public:
    Trapeze(pair <double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d);
    virtual ~Trapeze();
    
    void move(Point newP) override;
    void turn(double angle) override;
    void scale(double factor) override;
    void setColor(std::string color) override;
    string getColor() override;
    string getId() override;
    friend ostream& operator<<(ostream& os, const Trapeze& rect);
    
private:
    Point positionCentre();
    
private:
    pair <double, double> _a;
    pair <double, double> _b;
    pair <double, double> _c;
    pair <double, double> _d;
    string _color;
};

#endif /* TRAPEZE_H */

