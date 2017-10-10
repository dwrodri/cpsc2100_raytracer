/** CPSC 2100 - myvector.h  **/

#ifndef myvector_t_H
#define myvector_t_H

#include <iostream>
#include <iomanip>

using namespace std;


class myvector_t
{
  public:
    myvector_t();
    myvector_t(double newx, double newy, double newz);
    myvector_t(double newx);
    myvector_t(const myvector_t & toCopy);
    ~myvector_t();
    double length();
    double dot(const myvector_t &v2);
    myvector_t scale(double fact);
    myvector_t diff(const myvector_t &subtrahend);
    myvector_t sum(const myvector_t &addend);
    myvector_t unitvec();
    myvector_t cross(const myvector_t &v2);
    myvector_t reflect (myvector_t N, myvector_t W);
    double getx();
    double gety();
    double getz();
    void print();
    double get(int i);

    /* operator overloading */
    myvector_t &operator=(const myvector_t &toCopy);
    myvector_t operator*(double fact) const;
    myvector_t operator-(const myvector_t &subtrahend) const;
    myvector_t operator+(const myvector_t &addend) const;
    myvector_t operator~();
    friend ostream &operator<<(ostream &out, const myvector_t &v);
    friend istream &operator>>(istream &in, myvector_t &v);
    double &operator[](int i);


  private:
    double x;
    double y;
    double z;

};

#endif
