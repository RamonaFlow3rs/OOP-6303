#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <utility>
#include "exc.h"
#include <iostream>

using namespace std;

class Rectangle : public Shape {
public:
    
    Rectangle(const Point a, const Point b, const Point c, const Point d);
    ~Rectangle();
    
    
    void move(const Point newP) override;
    void turn(double angle) override;
    void scale(double factor) override;
    void setColor(std::string color) override;
    int getId() override;
    string getColor() override;
    friend ostream& operator<<(ostream& os, const Rectangle& rect);
    
private:     
    Point positionCentre();
    
   
private:
    Point _a;
    Point _b;
    Point _c;
    Point _d;
    string _color;
    uint32_t _id;
};

#endif /* RECTANGLE_H */

