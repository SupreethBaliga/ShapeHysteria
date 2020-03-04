#include "Shapes.h"
using namespace std;

void drive_circle() {
    /*INSTRUCTIONS
        Input : (x coord of center, y coord of center, radius)
        Contains: Either inside or on circumference. (Note the error due to floating point precision)
    */
   cout<< "DRIVING ROUTINE FOR A CIRCLE\n------------------------------------------\n\n";
   Visitor* v1 = new ContainsVisitor();
   //Creating R
   Circle* circle = create_circle(2,0,3);
   Point A(3,0), B(-2,1), A1(0,0), B1(6,0),A2(3,0),B2(0,4);
   //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(circle,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(circle,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(circle,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(circle,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(circle,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(circle,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';

    // Translating R to R1
    translate(circle,3,0);
    cout<<'\n';
    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(circle,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(circle,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(circle,-3,0);
    rotate(circle,90);
    // now centre is at (0,2)
    // cout<< circle->m->xtranslation <<','<< circle -> m -> ytranslation << ',' << circle->m->rotangle<<'\n';

    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(circle,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(circle,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive_triangle() {
    /*INSTRUCTIONS
        Input: (x1,y1,x2,y2,x3,y3)
        Contains: Inside or on the perimeter. (float precision error)
    */
   cout<< "DRIVING ROUTINE FOR A TRIANGLE\n------------------------------------------\n\n";
    Visitor* v1 = new ContainsVisitor();
    Triangle* tri = create_triangle(2,0,5,0,2,5);
    Point A(3,1),B(-1,0),A1(4,1),B1(1,1),A2(3,1),B2(-3,-1);

    //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(tri,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(tri,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(tri,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(tri,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(tri,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(tri,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";

    // Translating R to R1
    translate(tri,-2,0);
    cout<<'\n';

    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(tri,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(tri,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(tri,2,0);
    rotate(tri,180);

    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(tri,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(tri,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive_rectangle() {
    /*INSTRUCTIONS
        Input: (xcoord of bottom left corner, ycoord of bottom left corner, side length along x, side length along y)
        Contained: Inside or on the border. (float precision error note)
    */
   cout<< "DRIVING ROUTINE FOR A RECTANGLE\n------------------------------------------\n\n";
    Visitor* v1 = new ContainsVisitor();
    Rectangle* rect = create_rectangle(2,0,5,2);
    Point A(3,1),B(-1,1),A1(6,1),B1(1,1),A2(3,1),B2(1,-3);

    //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(rect,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(rect,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(rect,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(rect,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(rect,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(rect,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";

    // Translating R to R1
    translate(rect,-2,0);
    cout<<'\n';

    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(rect,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(rect,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(rect,2,0);
    rotate(rect,-90);

    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(rect,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(rect,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive_square() {
    /*INSTRUCTIONS
        Input: (xcoord of bottom left corner, ycoord of bottom left corner, side of square)
        Contains: Inside or on the border (float precision error note)
    */
   cout<< "DRIVING ROUTINE FOR A SQUARE\n------------------------------------------\n\n";
    Visitor* v1 = new ContainsVisitor();
    Rectangle* rect = create_square(2,0,5);
    Point A(3,1),B(-1,1),A1(6,1),B1(1,1),A2(3,1),B2(-1,3);

    //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(rect,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(rect,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(rect,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(rect,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(rect,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(rect,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";

    // Translating R to R1
    translate(rect,-2,0);
    cout<<'\n';

    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(rect,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(rect,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(rect,2,0);
    rotate(rect,90);

    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(rect,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(rect,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive_circle_complement() {
    /*INSTRUCTIONS
        Input: (xcoord of center, ycoord of center, radius of circle of which this is complement)
        Contains: Strictly outside the circle of which this is complement. (float precision error)
    */
    cout<< "DRIVING ROUTINE FOR A CIRCLE COMPLEMENT\n------------------------------------------\n\n";
    Visitor* v1 = new ContainsVisitor();
    CircleComplement* comp = create_circle_complement(2,0,2);
    Point A(6,13),B(1,0),B1(3,1),A1(0,3),A2(-1,0),B2(2,0);

    //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(comp,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(comp,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(comp,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(comp,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(comp,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(comp,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";

    // Translating R to R1
    translate(comp,-2,2);
    cout<<'\n';

    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(comp,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(comp,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(comp,2,-2);
    rotate(comp,180);

    // cout<< comp->m->xtranslation <<','<< comp->m->ytranslation <<',' << comp->m->rotangle<<'\n';
    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(comp,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(comp,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive_lshaped() {
    /*INSTRUCTIONS
        Input: (xcoord of bottom left corner, ycoord of bottom left corner, a,b,c) - (a,b,c as per pdf problem statement)
        Contains: Similar to that of rectangle
    */
   cout<< "DRIVING ROUTINE FOR A L-SHAPED\n------------------------------------------\n\n";
    Visitor* v1 = new ContainsVisitor();
    LShaped* reg = create_lshape(1,0,2,6,4);
    Point A(5,1),B(4,5),A1(2,3),B1(-5,2),A2(2,3),B2(1,-3);

    //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(reg,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(reg,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(reg,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(reg,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(reg,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(reg,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";

    // Translating R to R1
    translate(reg,-7,0);
    cout<<'\n';

    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(reg,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(reg,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(reg,7,0);
    rotate(reg,-90);

    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(reg,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(reg,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive_annulus() {
    /*INSTRUCTIONS
        Input: (xcoord of center, ycoord of center, inner rad, outer rad)
        Contains: strictly outside inner circle and within the outer circle or on circumference of outer circle (float precision)
    */
   cout<< "DRIVING ROUTINE FOR A ANNULUS\n------------------------------------------\n\n";
   Visitor* v1 = new ContainsVisitor();
   //Creating R
   Annulus* circle = create_annulus(1,0,1,5);
   Point A(4,1), B(0.5,0), A1(5.5,0), B1(1.5,0),A2(5.5,0),B2(-5.5,0);
   //Testing for all points first with R
    cout<<"Testing for R\n";
    if(v1->visit(circle,A)) cout << '(' << A.x << ',' << A.y << ") is contained.\n";
    else cout<< '(' << A.x << ',' << A.y << ") is not contained.\n";
    if(v1->visit(circle,B)) cout << '(' << B.x << ',' << B.y << ") is contained.\n";
    else cout<< '(' << B.x << ',' << B.y << ") is not contained.\n";
    if(v1->visit(circle,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(circle,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    if(v1->visit(circle,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(circle,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";

    // Translating R to R1
    translate(circle,-1,0);
    cout<<'\n';
    //Testing A1 and B1 for R1
    cout<<"Testing for R1\n";
    if(v1->visit(circle,A1)) cout << '(' << A1.x << ',' << A1.y << ") is contained.\n";
    else cout<< '(' << A1.x << ',' << A1.y << ") is not contained.\n";
    if(v1->visit(circle,B1)) cout << '(' << B1.x << ',' << B1.y << ") is contained.\n";
    else cout<< '(' << B1.x << ',' << B1.y << ") is not contained.\n";
    cout<<'\n';

    // Rotating R to R2
    translate(circle,1,0);
    rotate(circle,180);
    // cout<< circle->m->xtranslation <<','<< circle -> m -> ytranslation << ',' << circle->m->rotangle<<'\n';
    //Testing A2 and B2 for R2
    cout<<"Testing for R2\n";
    if(v1->visit(circle,A2)) cout << '(' << A2.x << ',' << A2.y << ") is contained.\n";
    else cout<< '(' << A2.x << ',' << A2.y << ") is not contained.\n";
    if(v1->visit(circle,B2)) cout << '(' << B2.x << ',' << B2.y << ") is contained.\n";
    else cout<< '(' << B2.x << ',' << B2.y << ") is not contained.\n";
    cout<<'\n';
}

void drive() {
    drive_circle();
    drive_triangle();
    drive_rectangle();
    drive_square();
    drive_circle_complement();
    drive_lshaped();
    drive_annulus();
}

int main() {
    drive();
    return 0;
}