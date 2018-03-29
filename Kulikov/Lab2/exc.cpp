#include "exc.h"
#include <iostream>

using namespace std;


BadFigureException::BadFigureException(std::string name) : _figureName(name) {}

void BadFigureException::print(){
    cout<<"bad "+_figureName+" exception"<<endl;
}


