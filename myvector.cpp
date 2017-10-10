/** CPSC 2100 myvector_t class
    Similar to the one developed in an earlier lab
**/

#include <iostream>
#include <math.h>
#include "myvector.h"

using namespace std;

myvector_t &myvector_t::operator=(const myvector_t &toCopy) {
    x = toCopy.x;
    y = toCopy.y;
    z = toCopy.z;
    return *this;
}

/** Overloaded operators **/
/** scale **/
myvector_t myvector_t::operator*(double fact) const
{
    return myvector_t(x*fact, y*fact, z*fact);
}

/** difference **/
myvector_t myvector_t::operator-(const myvector_t &subtrahend) const
{
    return myvector_t((x-subtrahend.x), (y-subtrahend.y), (z-subtrahend.z));
}

/** sum **/
myvector_t myvector_t::operator+(const myvector_t &addend) const
{
    return myvector_t((x+addend.x), (y+addend.y), (z+addend.z));
}

/** unitize **/
myvector_t myvector_t::operator~()
{
    myvector_t result;
    result = *this * (1.0/this->length());
    return(result);
}

/** "friend" function to output a myvector_t **/
ostream &operator<<(ostream &out, const myvector_t &v)
{
    out << fixed;
    //out << "(" << setprecision(2) << v.x << ", " << v.y << ", " << v.z << ")";
    out << setprecision(2) << v.x << "   " << v.y << "   " << v.z ;
    return out;
}

/** "friend" function to input a myvector_t **/
istream &operator>>(istream &in, myvector_t &v)
{
    in >> v.x >> v.y >> v.z;
    return in;
}

/** myvector_t field access **/
double &myvector_t::operator[](int i) {
    if(i == 0) return x;
    else if(i == 1) return y;
    else return z;
}

/*******************************************************************
      The rest of this file is the solution to lab 11 -- it does not
      need to change
********************************************************************/
myvector_t::myvector_t()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}

myvector_t::myvector_t(double newx, double newy, double newz)
{
    x = newx;
    y = newy;
    z = newz;
}

myvector_t::myvector_t(double newx)
{
    x = newx;
    y = 0;
    z = 0;
}

myvector_t::myvector_t(const myvector_t & toCopy)
{
    x = toCopy.x;
    y = toCopy.y;
    z = toCopy.z;
}

myvector_t::~myvector_t()
{
}

double myvector_t::length()
{
    return sqrt(x*x + y*y + z*z);
}

double myvector_t::dot(const myvector_t &v2)
{
    return (x*v2.x + y*v2.y + z*v2.z);
}

myvector_t myvector_t::scale(double fact)
{
	return myvector_t(x*fact, y*fact, z*fact);
}

myvector_t myvector_t::diff(const myvector_t &subtrahend)
{
	return myvector_t(x - subtrahend.x, y - subtrahend.y, z - subtrahend.z);
}

myvector_t myvector_t::sum(const myvector_t & addend)
{
	return myvector_t(x + addend.x, y + addend.y, z + addend.z);
}

myvector_t myvector_t::unitvec()
{
	double len = length();
	return myvector_t(x/len, y/len, z/len);
}

myvector_t myvector_t::cross(const myvector_t &v2)
{
   myvector_t work;
   work.x = y * v2.z - z * v2.y;
   work.y = z * v2.x - x * v2.z;
   work.z = x * v2.y - y * v2.x;
   return work;
}

myvector_t myvector_t::reflect(myvector_t N, myvector_t W)
{ 
   myvector_t U = W * -1;
   return  ((~N * 2) * U.dot(~N)).diff(U);
}

double myvector_t::getx() {
        return(x);
}

double myvector_t::gety() {
        return(y);
}

double myvector_t:: getz() {
        return(z);
}

void myvector_t::print()
{
    cerr << "(" << x << ", " << y << ", " << z << ")\n";
}

