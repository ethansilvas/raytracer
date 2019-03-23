#include "Vec.h"

//constructors
Vec::Vec() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vec::Vec(const double& x, const double& y, const double& z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

//operator overloads
Vec Vec::operator+(const Vec& v) const {
    return Vec(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vec Vec::operator-(const Vec& v) const {
    return Vec(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vec Vec::operator*(const double& d) const {
    return Vec(this->x * d, this->y * d, this->z * d);
}

Vec Vec::operator/(const double& d) const {
    return Vec(this->x / d, this->y / d, this->z / d);
}

//function to normalize
Vec Vec::Normalize() const {
    //use Dot formula on this x, y, z
    double mg = sqrt(x*x + y*y + z*z);
    return Vec(x/mg, y/mg, z/mg);
}

//getters and setters
double Vec::getX() const {
    return this->x;
}

double Vec::getY() const {
    return this->y;
}

double Vec::getZ() const {
    return this->z;
}

void Vec::setX(const double& x) {
    this->x = x;
}
void Vec::setY(const double& y) {
    this->y = y;
}
void Vec::setZ(const double& z) {
    this->z = z;
}
