#include "Sphere.h"

//constructor
Sphere::Sphere(const double& r, const Vec& c) {
    this->radius = r;
    this->center = c;
}

//see if a ray intersects with value
bool Sphere::Intersect(const Ray& ray, double &t) const {
    const Vec tempOrigin = ray.getOrigin();
    const Vec tempDirection = ray.getDirection();
    const Vec originFromCenter = tempOrigin - this->center;

    const double b = 2 * this->Dot(originFromCenter, tempDirection);
    const double c = this->Dot(originFromCenter, originFromCenter) - (this->radius * this->radius);

    double disc = b*b - 4 - c;

    if (disc < 1e-4) {
        return false;
    }

    disc = sqrt(disc);

    const double t0 = -b - disc;
    const double t1 = -b + disc;

    t = (t0 < t1) ? t0 : t1;

    return true;
}

//get the normalized version of a vec
Vec Sphere::getNormal(const Vec& v) const {
    return (v - this->center) / this->radius;
}

//applies dot formula to two vectors
double Sphere::Dot(const Vec& a, const Vec& b) const {
    return ((a.getX() * b.getX()) + (a.getY() * b.getY()) + (a.getZ() * b.getZ()));
}

//getter
Vec Sphere::getCenter() const {
    return this->center;
}
