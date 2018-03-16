/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RegularPentagon.h
 * Author: ekulikov
 *
 * Created on 15 марта 2018 г., 17:33
 */

#ifndef REGULARPENTAGON_H
#define REGULARPENTAGON_H

#include "Shape.h"
#include <utility>

using namespace std;

class RegularPentagon : public Shape {
public:
    RegularPentagon(pair <double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d, pair<double, double> e);
    virtual ~RegularPentagon();
    
    void move(Point newP) override;
    void turn(double angle) override;
    void scale(double factor) override;
    void setColor(std::string color) override;
    string getColor() override;
    string getId() override;
    friend ostream& operator<<(ostream& os, const RegularPentagon& pent);
    
private:
    Point positionCentre();
  
    
private:
    pair <double, double> _a;
    pair <double, double> _b;
    pair <double, double> _c;
    pair <double, double> _d;
    pair <double, double> _e;
    string _color;
};

#endif /* REGULARPENTAGON_H */

