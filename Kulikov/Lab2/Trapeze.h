#ifndef TRAPEZE_H
#define TRAPEZE_H
#include "Shape.h"
#include "exc.h"
#include <utility>

using namespace std;

class Trapeze : public Shape {
public:
    Trapeze(const Point a, const Point b, const Point c, const Point d);
    ~Trapeze();
    
    void move(const Point newP) override;
    void turn(double angle) override;
    void scale(double factor) override;
    void setColor(string color) override;
    string getColor() override;
    int getId() override;
    friend ostream& operator<<(ostream& os, const Trapeze& rect);

    
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

#endif /* TRAPEZE_H */

