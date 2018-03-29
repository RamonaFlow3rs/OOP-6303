#ifndef EXC_H
#define EXC_H

#include <string>

class BadFigureException{


private:
    std::string _figureName;

public:
    BadFigureException(std::string name);
    void print();
};


#endif // EXC_H
