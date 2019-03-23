#ifndef VEC_H
#define VEC_H

#include <cmath>

class Vec {
public:
    //constructors
    Vec();
    Vec(const double& x, const double& y, const double& z);

    //operator overloads
    Vec operator+(const Vec& v) const;
    Vec operator-(const Vec& v) const;
    Vec operator*(const double& d) const;
    Vec operator/(const double& d) const;

    //normalizes *this
    Vec Normalize() const;

    //getters
    double getX() const;
    double getY() const;
    double getZ() const;

    //setters
    void setX(const double& x);
    void setY(const double& y);
    void setZ(const double& z);
private:
    double x, y, z;
};

#endif
