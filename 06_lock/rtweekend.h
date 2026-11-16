#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#ifdef _OPENMP
#include <omp.h>
#endif
using std::make_shared;
using std::shared_ptr;
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
inline double degrees_to_radians(double degrees) { return degrees * pi / 180.0; }

// Each OpenMP thread owns its own random-number generator.
inline unsigned int& base_random_seed() {
    static unsigned int seed = 42;
    return seed;
}
inline std::mt19937& random_generator() {
    static thread_local std::mt19937 generator([] {
        unsigned int thread_id = 0;
#ifdef _OPENMP
        thread_id = static_cast<unsigned int>(omp_get_thread_num());
#endif
        return base_random_seed() + 9973u * thread_id;
    }());
    return generator;
}
inline void set_random_seed(unsigned int seed) {
    base_random_seed() = seed;
    random_generator().seed(seed);
}


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
