#ifndef _FILLCOLOR_DECORATOR_H_
#define _FILLCOLOR_DECORATOR_H_

#include "figure.h"
#include "decorator.h"

class FillColor_Decorator: public Decorator
{
private:

    std::string _color;

public:

    FillColor_Decorator(Figure *undecorated, string color) : Decorator(undecorated), _color(color) {}


    void draw(ostream &os) const 
    {
        Decorator::draw(os);
	   	os << " [decorated: fill: " << _color << "]";
    }
    
    static FillColor_Decorator *factory(Figure *undecorated, string color)
    {
        FillColor_Decorator *sp = new FillColor_Decorator(undecorated, color);
        sp->fix_decorator_group();
        return sp;            
    }
};


#endif
