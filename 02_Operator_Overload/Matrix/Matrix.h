/*****************************
*    Header file for the     *
*    matrix                  *
*****************************/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class matrix
{
    private:
        double a,b,c,d;

    public:
        matrix(double a = 1.0, double b = 0.0, double c = 1.0, double d = 0.0) : a(a), b(b), c(c), d(d) {};
        friend std::ostream& operator<<(std::ostream&, const matrix&);
        friend std::istream& operator>>(std::istream&, matrix&);
        matrix operator+(const matrix&) const;
        matrix operator-(const matrix&) const;
        matrix operator*(const matrix&) const;
        matrix operator+=(const matrix&);
        matrix operator-=(const matrix&);
        matrix operator*=(const matrix&);
        matrix operator*(const double) const;
        matrix operator*=(const double);
        bool operator==(const matrix&) const;
        bool operator!=(const matrix&) const;
};

#endif
