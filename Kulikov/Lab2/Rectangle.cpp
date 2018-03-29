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
        throw BadFigureException("Rectangle");   
    }
    
    _id = getNextId(); 
}

Rectangle::~Rectangle() {
}


uint32_t Rectangle::id(){
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
    Point centre = positionCentre();
    
    angle =  fmod(angle, 360);
    angle *= M_PI/180;
    
    Point tmp;
    
    //X = x0 + (x - x0) * cos(a) - (y - y0) * sin(a);
    //Y = y0 + (x - x0) * sin(a) + (y - y0) * cos(a);
    
    tmp.x = centre.x + (_a.x - centre.x)*cos(angle) - (_a.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_a.x - centre.x)*sin(angle) + (_a.y - centre.y)*cos(angle);
    _a.x = round(tmp.x*10000)/10000;
    _a.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_b.x - centre.x)*cos(angle) - (_b.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_b.x - centre.x)*sin(angle) + (_b.y - centre.y)*cos(angle);
    _b.x = round(tmp.x*10000)/10000;
    _b.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_c.x - centre.x)*cos(angle) - (_c.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_c.x - centre.x)*sin(angle) + (_c.y - centre.y)*cos(angle);
    _c.x = round(tmp.x*10000)/10000;
    _c.y = round(tmp.y*10000)/10000;


    tmp.x = centre.x + (_d.x - centre.x)*cos(angle) - (_d.y - centre.y)*sin(angle);
    tmp.y = centre.y + (_d.x - centre.x)*sin(angle) + (_d.y - centre.y)*cos(angle);
    _d.x = round(tmp.x*10000)/10000;
    _d.y = round(tmp.y*10000)/10000;    
}


void Rectangle::scale(double factor){
    Point centre = positionCentre();
    
    vector <double> xArray = {_a.x, _b.x, _c.x, _d.x};
    vector <double> yArray = {_a.y, _b.y, _c.y, _d.y};
     
    for (int i = 0; i < xArray.capacity() ; i++) {
        if (xArray[i] > centre.x) {
            xArray[i] = centre.x + (xArray[i] - centre.x) * factor;
            
        } else {
            xArray[i] = centre.x - (centre.x - xArray[i]) * factor; 
        }
    }
    
    for (int i = 0; i < yArray.capacity() ; i++) {
        if (yArray[i] > centre.y) {
            yArray[i] = centre.y + (yArray[i] - centre.y) * factor; 
        } else {
            yArray[i] = centre.y - (centre.y - yArray[i]) * factor; 
        }
    }

    _a.x = xArray[0]; _a.y = yArray[0];
    _b.x = xArray[1]; _b.y = yArray[1];
    _c.x = xArray[2]; _c.y = yArray[2];
    _d.x = xArray[3]; _d.y = yArray[3];
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
