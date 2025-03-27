#include "Matrix.h"


std::ostream& operator<<(std::ostream& os, const matrix& m)
{
    os << std::endl;
    os << m.a << " " << m.b << std::endl;
    os << m.c << " " << m.d << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, matrix& m)
{
    is >> m.a >> m.b >> m.c >> m.d;
    return is;
}

matrix matrix::operator+(const matrix& m) const
{
    return matrix(a + m.a, b + m.b, c + m.c, d + m.d);
}

matrix matrix::operator-(const matrix& m) const
{
    return matrix(a - m.a, b - m.b, c - m.c, d - m.d);
}

matrix matrix::operator*(const matrix& m) const
{
    return matrix(a * m.a + b * m.c, a * m.b + b * m.d, c * m.a + d * m.c, c * m.b + d * m.d);
}

matrix matrix::operator+=(const matrix& m)
{
    a += m.a;
    b += m.b;
    c += m.c;
    d += m.d;
    return *this;
}

matrix matrix::operator-=(const matrix& m)
{
    a -= m.a;
    b -= m.b;
    c -= m.c;
    d -= m.d;
    return *this;
}

matrix matrix::operator*=(const matrix& m)
{
    *this = *this * m;
    return *this;
}

matrix matrix::operator*(const double scalar) const
{
    return matrix(a * scalar, b * scalar, c * scalar, d * scalar);
}

matrix matrix::operator*=(const double scalar)
{
    a *= scalar;
    b *= scalar;
    c *= scalar;
    d *= scalar;
    return *this;
}

bool matrix::operator==(const matrix& other) const
{
    return a == other.a && b == other.b && c == other.c && d == other.d;
}

bool matrix::operator!=(const matrix& other) const
{
    return !(*this == other);
}