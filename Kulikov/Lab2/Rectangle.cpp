#include "Rectangle.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle(const Point a, const Point b, const Point c, const Point d) : _a(a), _b(b), _c(c), _d(d) {
    if ((sqrt(powf(_a.x - _c.x, 2) + powf(_a.y - _c.y, 2))) == 
        (sqrt(powf(_d.x - _b.x, 2) + powf(_d.y - _b.y, 2)))) {
        cout << "The new Rectangle has been created!" << endl;
        
    } else {
        throw badRectangleException();   
    }

    _id = Shape::sCounter++;
}

Rectangle::~Rectangle() {
}

int Rectangle::getId(){
    return _id;
}

Point Rectangle::positionCentre(){
    double xc = (_c.x - _a.x) / 2;
    double yc = (_c.y - _a.y) / 2;
    Point centre;
    centre.x = xc;
    centre.y = yc;
    return centre;
}

void Rectangle::move(const Point newP) {
    
    Point centre = positionCentre();
    
    double movedX = newP.x - centre.x;
    double movedY = newP.y - centre.y;
    _a.x += movedX; _a.y += movedY;
    _b.x += movedX; _b.y += movedY;
    _c.x += movedX; _c.y += movedY;        
    _d.x += movedX; _d.y += movedY;        
}


void Rectangle::turn(double angle){
    angle *= M_PI/180;
    
    Point tmp;
    
    tmp.x = _a.x*cos(angle) - _a.y*sin(angle);
    tmp.y = _a.x*sin(angle) + _a.y*cos(angle); 
    _a.x = tmp.x;
    _a.y = tmp.y;
    
    
    tmp.x = _b.x*cos(angle) - _b.y*sin(angle);
    tmp.y = _b.x*sin(angle) + _b.y*cos(angle); 
    _b.x = tmp.x;
    _b.y = tmp.y;
    
    
    tmp.x = _c.x*cos(angle) - _c.y*sin(angle);
    tmp.y = _c.x*sin(angle) + _c.y*cos(angle); 
    _c.x = tmp.x;
    _c.y = tmp.y;
    
    
    tmp.x = _d.x*cos(angle) - _d.y*sin(angle);
    tmp.y = _d.x*sin(angle) + _d.y*cos(angle); 
    _d.x = tmp.x;
    _d.y = tmp.y; 
}


void Rectangle::scale(double factor){
    _a.x *= factor; _a.y *= factor;
    _b.x *= factor; _b.y *= factor;
    _c.x *= factor; _c.y *= factor;
    _d.x *= factor; _d.y *= factor;
}

void Rectangle::setColor(string color) {
    _color = color;
}

string Rectangle::getColor() {
    return _color;
}

ostream& operator<<(ostream& os, const Rectangle& rect){
    os << '(' << rect._a.x << ':' << rect._a.y << ')' << endl << '(' << rect._b.x << ':' << rect._b.y << ')' << endl << '(' << rect._c.x << ':' << rect._c.y << ')' << endl << '(' << rect._d.x << ':' << rect._d.y << ')' << endl;
            
    return os;
}
