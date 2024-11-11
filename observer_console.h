#ifndef _CONSOLE_OBSERVER_H_
#define _CONSOLE_OBSERVER_H_

#include "observer.h"

class Figure;

class Console_Observer : public Observer
{
public:

    virtual void update(const Figure& fig) const
    {
        cout << "*** Console observer=>redrawing: " << fig << std::endl;
    }
};


#endif
