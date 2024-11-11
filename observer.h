#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Figure;

class Observer
{
public:

    virtual void update(const Figure& fig) const = 0;
	virtual ~Observer() { }
};

#endif
