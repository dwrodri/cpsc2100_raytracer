/** 
   CPSC 2100 mycolor_t class
**/

#include <iostream>
#include <math.h>
#include "mycolor.h"

using namespace std;

mycolor_t::mycolor_t()
{
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

mycolor_t::mycolor_t(double newR, double newG, double newB)
{
    r = newR;
    g = newG;
    b = newB;
}

mycolor_t::mycolor_t(double newR)
{
    r = newR;
    g = 0.0;
    b = 0.0;
}

mycolor_t::mycolor_t(const mycolor_t & toCopy)
{
    r = toCopy.r;
    g = toCopy.g;
    b = toCopy.b;
}

mycolor_t::~mycolor_t()
{

}

double mycolor_t::dot(const mycolor_t &color2)
{
    return (r*color2.r + g*color2.g + r*color2.b);
}

mycolor_t mycolor_t::scale(double fact)
{
	return mycolor_t(r*fact, g*fact, b*fact);
}

mycolor_t mycolor_t::diff(const mycolor_t &subtrahend)
{
	return mycolor_t(r - subtrahend.r, g - subtrahend.g, b - subtrahend.b);
}

mycolor_t mycolor_t::sum(const mycolor_t & addend)
{
	return mycolor_t(r + addend.r, g + addend.g, b + addend.b);
}

double mycolor_t:: getR() {
        return(r);
}

double mycolor_t:: getG() {
        return(g);
}

double mycolor_t:: getB() {
        return(b);
}

void mycolor_t::print()
{
    cerr << "(" << r << ", " << g << ", " << b << ")\n";
}

mycolor_t &mycolor_t::operator=(const mycolor_t &toCopy) {
    r = toCopy.r;
    g = toCopy.g;
    b = toCopy.b;
    return *this;
}

/** Overloaded operators **/
/** scale **/
mycolor_t mycolor_t::operator*(double fact) const
{
    return mycolor_t(r*fact, g*fact, b*fact);
}

/** difference **/
mycolor_t mycolor_t::operator-(const mycolor_t &subtrahend) const
{
    return mycolor_t((r-subtrahend.r), (g-subtrahend.g), (b-subtrahend.b));
}

/** sum **/
mycolor_t mycolor_t::operator+(const mycolor_t &addend) const
{
    return mycolor_t((r+addend.r), (g+addend.g), (b+addend.b));
}

/** "friend" function to output a mycolor_t **/
ostream &operator<<(ostream &out, const mycolor_t &color)
{
    //out << "(" << setprecision(0) << color.r << ", " << color.g << ", " << color.b << ")";
    out << setprecision(0) << color.r << "   " << color.g << " " << color.b;
    return out;
}

/** "friend" function to input a mycolor_t **/
istream &operator>>(istream &in, mycolor_t &color)
{
    in >> color.r >> color.g >> color.b;
    return in;
}

/** mycolor_t field access **/
double &mycolor_t::operator[](int i) {
    if(i == 0) return r;
    else if(i == 1) return g;
    else return b;
}


