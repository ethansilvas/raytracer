#include "Ray.h"

//constructor
Ray::Ray(const Vec& o, const Vec& d) {
    this->origin = o;
    this->direction = d;
}

//getters
Vec Ray::getOrigin() const {
    return this->origin;
}

Vec Ray::getDirection() const {
    return this->direction;
}
