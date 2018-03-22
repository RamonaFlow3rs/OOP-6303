/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exc.h
 * Author: ekulikov
 *
 * Created on 22 марта 2018 г., 21:24
 */

#ifndef EXC_H
#define EXC_H

class ex{

public:
    virtual void print()=0;
};

class badRectangleException: public ex{
public:
    void print() override;
};

class badTrapezeException:public ex{
public:
    void print() override;
};

class badPentagonException:public ex
{
public: 
    void print() override;
};



#endif // EXC_H

