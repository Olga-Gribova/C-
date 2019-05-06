/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Rational {
    int x;
    unsigned int y;
public:
    //Rational (int a, unsigned int b) {x = a,y = b;}
    Rational(const int & x_0, const unsigned int & y_0) {
        x = x_0;
        y = y_0;
    }
    Rational operator+(Rational & r) {
        Rational temp(x*r.y + r.x*y , y*r.y);
        return temp;
    }
    Rational operator+=(Rational & r) {
        x = x*r.y + r.x*y;
        y = y*r.y;
        Rational temp(x,y);
        return temp;
    }
    Rational operator-(Rational & r) {
        Rational temp = r;
        temp.x *= -1;
        return *this + temp;
    }
    Rational operator-=(Rational & r) {
        x = x*r.y - r.x*y;
        y = y*r.y;
        Rational temp(x,y);
        return temp;
    }
    Rational operator*(const Rational & r) {
        Rational temp(x*r.x,y*r.y);
        return temp;
    }
    Rational operator*=(const Rational & r) {
        x = x*r.x;
        y = y*r.y;
        Rational temp(x,y);
        return temp;
    }
    Rational operator/(const Rational & r) {
        Rational temp(x*r.y,y*r.x);
        return temp;
    }
    Rational operator/=(const Rational & r) {
        x = x*r.y;
        y = y*r.x;
        Rational temp(x,y);
        return temp;
    }
    void show ()
    {
        std::cout << x << "/" << y << endl;;
    }
    //~Rational ();
};


int main() {
    Rational r1(-1,2), r2(3,3), r3(3,4);
    r1 /= r3;
    r1.show();
	return 0;
}