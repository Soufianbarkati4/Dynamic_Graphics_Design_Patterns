#ifndef _SURFACE_VISITOR_H_
#define _SURFACE_VISITOR_H_

#include <iostream>

#include "visitor.h" 

class Surface_Visitor : public Visitor
{
public:

    virtual void visit(Rectangle& fig)	{ _print_surface(fig); }
    virtual void visit(Square& fig)		{ _print_surface(fig); }
    virtual void visit(Ellipse& fig)	{ _print_surface(fig); }
    virtual void visit(Circle& fig)		{ _print_surface(fig); }
    virtual void visit(Group& fig)		{ _print_surface(fig); }

private:

    void _print_surface(const Figure& fig)
    {
        cout<< "Figure path: ";
	   	fig.print_path();
		cout << " --- surface: " << fig.surface() << endl;
    }
};


#endif
