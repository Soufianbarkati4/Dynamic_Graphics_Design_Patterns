#include <cassert>
#include <algorithm>

#include "figure.h"

// bidirectional COMPOSITE
//
#include "group.h"

class Observer;

using namespace std;

unsigned Figure::_nb_figures = 0;

ostream& operator<<(ostream& os, const Figure& fig)
{
    os	<< "name=" << fig.name()
		<< ", center=" << fig._center
		<< ", angle=" << fig._angle << " -- ";
	fig.draw(os);
    return os;
}

// bidirectional COMPOSITE
//
void Figure::print_path(ostream& os) const
{
	if (_group)
	{
		_group->print_path(os);
		os << "->";
	}
    os << _name;
}

void Figure::set_group(Group *group)
{
    if ( _group ) throw Figure_Already_In_Group();
    _group = group;
}

// OBSERVER
//
set<Observer *> Figure::_observers;
