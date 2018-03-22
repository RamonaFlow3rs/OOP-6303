#include "Trapeze.h"
#include <cmath>
#include <iostream>

using namespace std;

Trapeze::Trapeze(const Point a, const Point b, const Point c, const Point d): _a(a), _b(b), _c(c), _d(d)  {
    if (abs((_a.x - _b.x)/(_a.y - _b.y)) == abs((_c.x - _d.x)/(_c.y - _d.y))) {
        cout << "The new Trapeze has been created!" << endl;          
    } else 
        if (abs((_b.x - _c.x)/(_b.y - _c.y)) == abs((_a.x - _d.x)/(_a.y - _d.y))) {
            cout << "The new Trapeze has been created!" << endl;
        } else throw badTrapezeException();
    _id = Shape::sCounter++;
}


Trapeze::~Trapeze() {
}


int Trapeze::getId(){
    return _id;
}


Point Trapeze::positionCentre(){
    Point A; Point B; Point C; Point D;
  
    A.x = min(min(_a.x, _b.x), min(_c.x, _d.x));
    A.y = min(min(_a.y, _b.y), min(_c.y, _d.y));
    
    C.x = max(max(_a.x, _b.x), max(_c.x, _d.x));
    C.y = max(max(_a.y, _b.y), max(_c.y, _d.y));   
    
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


void Trapeze::move(const Point newP) {
    Point centre = positionCentre();
    
    double movedX = newP.x - centre.x;
    double movedY = newP.y - centre.y;
    _a.x += movedX; _a.y += movedY;
    _b.x += movedX; _b.y += movedY;
    _c.x += movedX; _c.y += movedY;        
    _d.x += movedX; _d.y += movedY;
}

void Trapeze::turn(double angle){
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


void Trapeze::scale(double factor){
    _a.x *= factor; _a.y *= factor;
    _b.x *= factor; _b.y *= factor;
    _c.x *= factor; _c.y *= factor;
    _d.x *= factor; _d.y *= factor;

}


void Trapeze::setColor(std::string color) {
    _color = color;
}


string Trapeze::getColor() {
    return _color;
}


ostream& operator<<(ostream& os, const Trapeze& trap){
    os << '(' << trap._a.x << ':' << trap._a.y << ')' << endl << '(' << trap._b.x << ':' << trap._b.y << ')' << endl << '(' << trap._c.x << ':' << trap._c.y << ')' << endl << '(' << trap._d.x << ':' << trap._d.y << ')' << endl;
            
    return os;

}
