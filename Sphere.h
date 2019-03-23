#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
public:
    //constructor
    Sphere(const double& r, const Vec& c);

    //methods to see if a ray intersects and to apply Dot forumula
    bool Intersect(const Ray& ray, double &t) const;
    double Dot(const Vec& a, const Vec& b) const;

    //getters
    Vec getNormal(const Vec& v) const;
    Vec getCenter() const;
private:
    double radius;
    Vec center;
};

#endif
