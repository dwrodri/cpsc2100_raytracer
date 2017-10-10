#ifndef mycolor_t_H
#define mycolor_t_H

#include <iostream>
#include <iomanip>
using namespace std;


class mycolor_t
{
public:
    /** color methods **/
    mycolor_t();
    mycolor_t(double newR, double newG, double newB);
    mycolor_t(double newR);
    mycolor_t(const mycolor_t &toCopy);
    ~mycolor_t();
    double dot(const mycolor_t &color2);
    mycolor_t scale(double fact);
    mycolor_t diff(const mycolor_t &subtrahend);
    mycolor_t sum(const mycolor_t &addend);
    double getR();
    double getG();
    double getB();
    void print();
    double get(int i);
    mycolor_t readColor(FILE *infile, const string &errmsg);

    mycolor_t &operator=(const mycolor_t &toCopy);
    mycolor_t operator*(double fact) const;
    mycolor_t operator-(const mycolor_t &subtrahend) const;
    mycolor_t operator+(const mycolor_t &addend) const;
    mycolor_t operator~();
    friend ostream &operator<<(ostream &out, const mycolor_t &color);
    friend istream &operator>>(istream &in, mycolor_t &color);
    double &operator[](int i);


  private:
    double r;
    double g;
    double b;

};

#endif
