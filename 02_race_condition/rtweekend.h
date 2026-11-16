#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
using std::make_shared;
using std::shared_ptr;
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
inline double degrees_to_radians(double degrees) { return degrees * pi / 180.0; }

// INTENTIONAL RACE: all OpenMP threads access the same generator without protection.
inline std::mt19937& random_generator() {
    static std::mt19937 generator(42);
    return generator;
}
inline void set_random_seed(unsigned int seed) { random_generator().seed(seed); }


inline double random_double() {
    return static_cast<double>(random_generator()()) / 4294967296.0;
}
inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}
#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"
#endif
