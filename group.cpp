#include "group.h"

class Figure;

// DECORATOR
//
void Group::replace(Figure *old, Figure *replacement)
{
	set<Figure *>::iterator it = _children.find(old);
	if (it == _children.end()) return;
	_children.erase(it);
	_children.insert(replacement);
}
