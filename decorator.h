#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include "figure.h"


// (Hyp) cannot decorate a group
//
class Attempt_Decorating_Group {};

class Decorator: public Figure
{
private:

    Figure *_undecorated;

public:

    Decorator(Figure *undeco) : _undecorated(undeco) {
        if (dynamic_cast<Group *>(_undecorated)) throw Attempt_Decorating_Group();
    }

    Figure *undecorated() const { return _undecorated; }

    void draw(ostream &os) const	{ _undecorated->draw(os); }
    void move(double dx, double dy)	{ _undecorated->move(dx, dy); }
    void rotate(double alpha)		{ _undecorated->rotate(alpha); }
    void scale(double s)			{ _undecorated->scale(s); }
    string name() const				{ return _undecorated->name(); }
    Point center() const			{ return _undecorated->center(); }
    double surface() const			{ return _undecorated->surface(); }
 	Group *group() const			{ return _undecorated->group();}

	// in case the decorated figure is already in a group, replace old one by newer one
	//
    void fix_decorator_group()
    {
		Group *gr = _undecorated->group();        
		if (gr) gr->replace(_undecorated, this);
    }

	// VISITOR
	//
	virtual void accept(Visitor &v) { _undecorated->accept(v); }
};

#endif
