#ifndef _CONCRETE_FIGURES_H_
#define _CONCRETE_FIGURES_H_

#include <iostream>
#include <string>

#include "figure.h"

// VISITOR
//
#include "visitor.h"


class Ellipse : public Figure
{
private:

    double _a;	///< Half-axis
    double _b;	///< Half-axis

public:

    Ellipse(std::string n, Point c, double a, double b) : Figure(n, c), _a(a), _b(b) {}

    double a_axis() const {return _a;}
    double b_axis() const {return _b;}

	// OBSERVER : add notify() when state is changing
	//
    virtual void scale(double s) { _a *= s; _b *= s; notify(); }
    virtual double surface() const { return PI * _a * _b; }

	virtual void draw(std::ostream& os) const { os << "drawing ellipse with " << "a=" << _a << ", b=" << _b; }

	// VISITOR
	//
	virtual void accept(Visitor &v) { v.visit(*this); }
};


class Circle : public Ellipse
{
public:

    Circle(std::string n, Point c, double r) : Ellipse(n, c, r, r) {}

    double radius() const { return a_axis(); }

    /// Rotate a circle
    virtual void rotate(double alpha)
    {
		// Nothing to do
		cout << "circle rotation : nothing to do. Angle " << alpha  << "unused." << endl;
    }

	virtual void draw(std::ostream& os) const { os << "drawing circle with radius=" << radius(); }
};


class Rectangle : public Figure
{
private:

    double _w;	///< Width
    double _h;	///< Height

public:

    /// Regular constructor
    Rectangle(std::string n, Point c, double w, double h) : Figure(n, c), _w(w), _h(h) {}

    /// Accessor to width
    double width() const {return _w;}

    /// Accessor to height
    double heigth() const {return _h;}
 
	// OBSERVER : add notify() when state is changing
	//
    virtual void scale(double s) { _w *= s; _h *= s; notify(); }

    /// Surface of a rectangle
    virtual double surface() const { return _w * _h; }

	virtual void draw(std::ostream& os) const { os << "drawing rectangle with width=" << _w << ", height=" << _h; }

	// VISITOR
	//
	virtual void accept(Visitor &v) { v.visit(*this); }
};


class Square : public Rectangle
{    
public:

     /// Regular constructor
    Square(std::string n, Point c, double a) : Rectangle(n, c, a, a) {}

    /// Accessor to side
    double side() const {return width();}

	virtual void draw(std::ostream& os) const { os << "drawing square with side=" << side(); }
};

#endif
