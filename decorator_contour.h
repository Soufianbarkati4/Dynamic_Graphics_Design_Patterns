#ifndef _CONTOUR_DECORATOR_H_
#define _CONTOUR_DECORATOR_H_

#include <sstream>

#include "figure.h"
#include "decorator.h"

class Contour_Decorator: public Decorator
{
	private:

    string _line_color;
    unsigned _line_width;

	public:

    Contour_Decorator(Figure *undecorated, string line_color, unsigned line_width) :
		Decorator(undecorated), _line_color(line_color), _line_width(line_width) {}

    void draw(ostream &os) const 
    {
        Decorator::draw(os);
		os << " [decorated: line: " << _line_color << "--" << _line_width << "]";
    }

	// "redefine" new
	//
    static Contour_Decorator *factory(Figure *undecorated, string line_color, unsigned line_width)
    {
        Contour_Decorator *sp = new Contour_Decorator(undecorated, line_color, line_width);
        sp->fix_decorator_group();
        return sp;            
    }
};

#endif
