#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <set>
#include <algorithm>

#include "goodies.h"

// OBSERVER
//
#include "observer.h"

using namespace std;

const double PI = 3.141592;

struct Point
{
    double _x;
    double _y;

    Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& pt)
    {
        return os << "(" << pt._x << ", " << pt._y << ")";
    }
};

// COMPOSITE
//
class Figure_Already_In_Group {}; // for set_group
class Group; // forward declaration for _group

// VISITOR
//
class Visitor;

class Figure
{
	private:

    static unsigned _nb_figures;

    Point _center; 	///< Center of this figure
    double _angle;	///< Angle of this figure with the horizontal axis
    string _name;	///< Name of this figure

	// COMPOSITE
	//
    Group *_group;

	// OBSERVER (all figures share same observers => static)
	//
	static set<Observer *> _observers;

	public:

    Figure(string name = "") : _center(), _angle(0), _name(name), _group(0)  { ++_nb_figures; }
    Figure(string name, Point c, double a = 0.0) : _center(c), _angle(a), _name(name), _group(0)   { ++_nb_figures; }

    Point center() const { return _center; }
    string name() const { return _name; }
	static int nb_figures() { return _nb_figures; }

	// OBSERVER : add notify() when state is changing
	//
    virtual void move(double dx, double dy) { _center._x += dx; _center._y += dy; notify(); }
    virtual void rotate(double alpha) { _angle += alpha; notify(); }

    virtual void scale(double s) = 0;

    /// Compute the surface of a figure.
    virtual double surface() const = 0;


    // print general (common) properties and draw with specific info
	//
    friend ostream& operator<<(ostream& os, const Figure& fig);

	virtual ~Figure()
	{
        --_nb_figures;
        cout << "Figure::destructor: " << _nb_figures << " remaining" << std::endl;   
	}

	virtual void draw(std::ostream& os) const = 0;

	// COMPOSITE
	//
    void print_path(ostream& os = cout) const;

    Group *group() const { return _group; }
    void set_group(Group *group);

	// OBSERVER
	//
	void attach_observer(Observer *o) { _observers.insert(o); }
	void detach_observer(Observer *o) { _observers.erase(o); }

	void notify() const { 
			for (set<Observer *>::const_iterator it = _observers.begin(); it != _observers.end(); it++) (*it)->update(*this);
	}

	// VISITOR
	//
	virtual void accept(Visitor &v) = 0;
}; 

#endif
