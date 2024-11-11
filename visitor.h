#ifndef _VISITOR_H_
#define _VISITOR_H_

// static list of concrete nodes
//
class Rectangle;
class Square;
class Ellipse;
class Circle;
class Group;

class Visitor
{
public:

    virtual void visit(Rectangle& rectangle) = 0;
    virtual void visit(Square& square) = 0;
    virtual void visit(Ellipse& ellipse) = 0;
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Group& group) = 0;

	virtual ~Visitor() { }
};

#endif
