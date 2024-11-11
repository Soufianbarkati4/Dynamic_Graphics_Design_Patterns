#ifndef _PERIMETER_VISITOR_H_
#define _PERIMETER_VISITOR_H_

#include <iostream>
#include <cmath>

#include "visitor.h" 


class Perimeter_Visitor : public Visitor
{
public:

    virtual void visit(Rectangle& fig)	{ _print_perimeter(fig, 2 * (fig.width() + fig.heigth())); }

    virtual void visit(Square& fig)		{ _print_perimeter(fig, 4 * fig.side()); }

    virtual void visit(Ellipse& fig)	{ _print_perimeter(fig, _ramanujan(fig)); }

    virtual void visit(Circle& fig)		{ _print_perimeter(fig, 2 * PI * fig.radius()); }

    virtual void visit(Group& fig)		{ _print_perimeter(fig, 0.0); }

private:

    void _print_perimeter(const Figure& fig, double perimeter)
    {
        cout << "Figure path: ";
		fig.print_path();
		cout << " --- perimeter: " << perimeter << std::endl;
    }

    /// Ramanujan's approximation of ellipse perimeter.
    static double _ramanujan(const Ellipse& ell)
    {
        double a = ell.a_axis();
        double b = ell.b_axis();
        return PI * (3*(a + b) - std::sqrt((3*a + b)*(a + 3*b)));
    }
};

#endif
