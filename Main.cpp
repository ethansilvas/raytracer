#include "Vec.cpp"
#include "Ray.cpp"
#include "Sphere.cpp"

#include <fstream>
#include <vector>

void clamp255(Vec& col) {
    col.setX((col.getX() > 255) ? 255 : (col.getX() < 0) ? 0 : col.getX());
    col.setY((col.getY() > 255) ? 255 : (col.getY() < 0) ? 0 : col.getY());
    col.setZ((col.getZ() > 255) ? 255 : (col.getZ() < 0) ? 0 : col.getZ());
}

int main() {
    const int H = 1000;
    const int W = 1000;

    //make some colors to color spheres
    const Vec white(255, 255, 255);
    const Vec black(0, 0, 0);
    const Vec blue(100, 50, 255);

    //hold sphere and the light reflection
    const Sphere sphere(50, Vec(W * .5, H * .5, 50));
    const Sphere sphere2(150, Vec(W * 1, H * .5, 150));
    const Sphere sphere3(150, Vec(W * 0, H * 1, 150));
    const Sphere light(1, Vec(50, 50, 50));

    std::vector<Sphere> spheres;
    spheres.push_back(sphere);
    spheres.push_back(sphere2);
    spheres.push_back(sphere3);


    //build the picture file
    std::ofstream out("picture.ppm");
    out << "P3\n" << W << ' ' << H << ' ' << "255\n";

    double t;
    Vec pixelColor(black);

    //fill the picture file 
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            pixelColor = black;

            const Ray r(Vec(x, y, 0), Vec(0, 0, 1));

            for (int i = 0; i < spheres.size(); i++) {
                if (spheres[i].Intersect(r, t)) {
                    const Vec pi = r.getOrigin() + (r.getDirection() * t);
                    const Vec L = light.getCenter() - pi;
                    const Vec N = spheres[i].getNormal(pi);
                    const double dt = spheres[i].Dot(L.Normalize(), N.Normalize());

                    pixelColor = (blue + white*dt) * .5;
                    clamp255(pixelColor);
                }
            }
            out << (int)pixelColor.getX() << ' '
                << (int)pixelColor.getY() << ' '
                << (int)pixelColor.getZ() << '\n';
        }
    }

    return 0;
}
