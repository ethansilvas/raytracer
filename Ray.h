#ifndef RAY_H
#define RAY_H

class Ray {
public:
    //constructor
    Ray(const Vec& o, const Vec& d);

    //getters
    Vec getOrigin() const;
    Vec getDirection() const;
private:
    Vec origin;
    Vec direction;
};

#endif
