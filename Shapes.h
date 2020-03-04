#include <iostream>
#include <math.h>
using namespace std;

class Point {
public:
    long double x,y;
    Point() {

    }
    Point(long double xcord,long double ycord) {
        x = xcord;
        y = ycord;
    } 
};


class Region {
public:
    Point origin;
    Region() {
        origin = Point(0,0);
    }
    virtual bool contains(Point){};
    virtual bool accept(Point) {};
    
};

class AbstractRegion : public Region {
public:
    AbstractRegion* a;
    bool lastClass;
    int type;
    float translatex;
    float translatey;
    float rotangle;
    AbstractRegion() {
        lastClass = true;
    }
};

class TranslatedRegion : public AbstractRegion {
public:
    // float translatex;
    // float translatey;
    TranslatedRegion(float x, float y) {
        lastClass =true;
        translatex = x;
        translatey = y;
        type=1;
    }
};

class RotatedRegion : public AbstractRegion {
public:
    RotatedRegion(float theta) {
        lastClass = true;
        rotangle = theta;
        type=2;
    }
};

class RealRegion: public Region {
public:
    AbstractRegion* a;
    RealRegion() {
        a = new TranslatedRegion(0,0);
    }
};

class Basic : public RealRegion {
public:
    RealRegion* r;
    virtual bool contains(Point){};
    virtual bool accept(Point) {};
};

class Union : public RealRegion {
public:
    RealRegion *r1;
    RealRegion *r2;
    virtual bool accept(Point) {};
};

class Complement : public RealRegion {
public:
    RealRegion *r;
    virtual bool accept(Point) {};
};

class Intersection : public RealRegion {
public:
    RealRegion *r1;
    RealRegion *r2;
    virtual bool accept(Point) {};
};

void translate(RealRegion* r,long double x, long double y) {
    AbstractRegion* temp = new TranslatedRegion(x,y);
    temp->lastClass = false;
    temp->a = r->a;
    r->a = temp;
}

void rotate(RealRegion* r,long double angle) {
    AbstractRegion* temp = new RotatedRegion(angle);
    temp->lastClass = false;
    temp->a = r->a;
    r->a = temp;
}

Point modify_point(RealRegion* r, Point p) {
        // (p->x)-=(m->xtranslation);
        // (p->y)-=(m->ytranslation);
        long double theta;
        long double pi = acos(-1);
        long double newx,newy,oldx,oldy;
        AbstractRegion* s = r -> a;
        while((s->lastClass)==false) {
            // cout<<"help"<<' '<< s->type <<' '<<s->translatex<<' '<< s->translatey <<' '<< s->rotangle << ' ' << s->lastClass <<'\n';
            if(s->type == 1) {
                (p.x) -= (s->translatex);
                (p.y) -= (s->translatey); 
            }
            else if(s->type == 2) {
                theta = (s->rotangle);
                oldx = (p.x);
                oldy = (p.y);
                theta *= (pi/180);
                newx = oldx*cos(theta) + oldy*sin(theta);
                newy = (-1)*oldx*sin(theta) + oldy*cos(theta);
                (p.x) = newx;
                (p.y) = newy;
            }
            // cout<<p.x<<' '<<p.y<<'\n';
            s = s->a; 
        }
        return p;
}



///////////////////////////Visitors////////////////////////////////////////////

class Visitor {
public:
    virtual bool visit(RealRegion*,Point){};
    // virtual void translate(RealRegion*,long double,long double){};
    // virtual void rotate(RealRegion*,long double){};
};

class ContainsVisitor : public Visitor {
public:

    bool visit(RealRegion* r, Point p) {
        return r->accept(p);
    }
};


///////////////////////////////BASIC CLASSES///////////////////////////////////////////////////////////
/******************************************************************************************************/
class Circle : public Basic {
public:
    Point centre;
    long double radius;
    Circle(long double r) {
        centre = origin;
        radius = r;
    }
    bool contains(Point p) {
        long double xdif = p.x - centre.x;
        long double ydif = p.y - centre.y;
        if(((xdif*xdif)+(ydif*ydif)) <= radius*radius) {
            return true;
        }
        else return false;
    }
    bool accept(Point p) {
        p= modify_point(this,p);
        // cout << p.x <<' '<<p.y <<'\n';
        return contains(p);
    }
};

class Triangle: public Basic {
public:
    Point A;
    Point B;
    Point C;
    Triangle(Point p1, Point p2) {
        A = origin;
        B = p1;
        C = p2;
    }

    long double triangleArea(Point p1, Point p2, Point p3) {         //find area of triangle formed by p1, p2 and p3
        return abs((p1.x*(p2.y-p3.y) + p2.x*(p3.y-p1.y)+ p3.x*(p1.y-p2.y))/2.0);
    }

    bool isInsideTriag(Point p1, Point p2, Point p3, Point p) {     //check whether p is inside or outside
        long double area = triangleArea (p1, p2, p3);          //area of triangle ABC
        long double area1 = triangleArea (p, p2, p3);         //area of PBC
        long double area2 = triangleArea (p1, p, p3);         //area of APC
        long double area3 = triangleArea (p1, p2, p);        //area of ABP
        return (abs(area - (area1 + area2 + area3))<=1e-5);        //when three triangles are forming the whole triangle
}

    bool contains(Point p) {
        return isInsideTriag(A,B,C,p);
    }

    bool accept(Point p) {
        p= modify_point(this,p);
        return contains(p);
    }
};

class Rectangle: public Basic {
public:
    Point leftBot;
    Point rightTop;
    Rectangle(Point p) {
        leftBot = origin;
        rightTop = p;
    }

    bool contains(Point p) {
        if((p.x<=rightTop.x && p.x>=leftBot.x) || (p.x>=rightTop.x && p.x<=leftBot.x)) {
            if((p.y<=rightTop.y && p.y>=leftBot.y) || (p.y>=rightTop.y && p.y<=leftBot.y)) {
                return true;
            }
        }
        return false;
    }

    bool accept(Point p) {
        p= modify_point(this,p);
        return contains(p);
    }
};

/****************************************************************************************************************/
////////////////////////////////End of Basic Classes/////////////////////////////////////////////////////////////////

//////////////////////////////////////////Union Classes//////////////////////////////////////////////////
/************************************************************************************************************/
class LShaped : public Union {
public:
    Point corner;
    LShaped(Point p1, Point p2) {
        corner = origin;
        r1 = new Rectangle(p1);
        r2 = new Rectangle(p2);
    }

    bool accept(Point p) {
        p= modify_point(this,p);
        return (r1->accept(p)) || (r2->accept(p));
    }
};

/*************************************************************************************************************/
///////////////////////////////////////////////////////End of Union Classes///////////////////////////////////////////

//////////////////////////////////////////////Complement Classes////////////////////////////////////////////////////////////
/***************************************************************************************************************************/
class CircleComplement : public Complement {
public:
    CircleComplement(long double rad) {
        r = new Circle(rad);
    }

    bool accept(Point p) {
        p= modify_point(this,p);
        return !(r->accept(p));
    }
};

/****************************************************************************************************************************/
//////////////////////////////////////////////////////////End of Complement Classes//////////////////////////////////////////


////////////////////////////////////////////////////////////////Intersection Classes////////////////////////////////////////////
/***********************************************************************************************************************************/
class Annulus : public Intersection {
public:
    Annulus(long double rin,long double rout) {
        r1 = new CircleComplement(rin);
        r2 = new Circle(rout);
    }
    
    bool accept(Point p) {
        p= modify_point(this,p);
        return (r1->accept(p)) && (r2->accept(p));
    }
};
/*************************************************************************************************************************************/
///////////////////////////////////////////End of Intersection Classes////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////Creator functions//////////////////////////////////////////////////////////
Circle* create_circle(long double xcord, long double ycord, long double rad) {
    Circle* c = new Circle(rad);
    translate(c,xcord,ycord);
    return c;
}

Triangle* create_triangle(long double xref, long double yref,long double x2, long double y2, long double x3, long double y3) {
    Point p1(x2-xref,y2-yref);
    Point p2(x3-xref,y3-yref);
    Triangle* t = new Triangle(p1,p2);
    translate(t,xref,yref);
    return t;
}

Rectangle* create_rectangle(long double xref, long double yref, long double sx, long double sy) {
    Point p(sx,sy);
    Rectangle* r = new Rectangle(p);
    translate(r,xref,yref);
    return r;
}

Rectangle* create_square(long double xref, long double yref, long double side) {
    Point p(side,side);
    Rectangle* r = new Rectangle(p);
    translate(r,xref,yref);
    return r;
}

LShaped* create_lshape(long double xref, long double yref, long double a, long double b, long double c) {
    Point p1(c+a,a);
    Point p2(a,b);
    LShaped* l = new LShaped(p1,p2);
    translate(l,xref,yref);
    return l;
}

CircleComplement* create_circle_complement(long double xref, long double yref, long double radius) {
    CircleComplement* c = new CircleComplement(radius);
    translate(c,xref,yref);
    return c;
}

Annulus* create_annulus(long double xref, long double yref, long double rin, long double rout) {
    Annulus* a = new Annulus(rin,rout);
    translate(a,xref,yref);
    return a;
}

