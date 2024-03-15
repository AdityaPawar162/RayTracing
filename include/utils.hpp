#ifndef UTILS_HPP
#define UTILS_HPP

#include <cmath>
#include <cstdlib>
#include <random>
#include <limits>
#include <memory>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degress_to_radians(double degrees){
    return degrees * pi / 180;
}

inline double random_generator(){
    // Returns a random double generator
    static std::uniform_real_distribution<double> distribution(0.0,1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_generator(double min,double max)
{
    // Returns a random double generator[parametetrized]
    static std::uniform_real_distribution<double> distribution(min,max);
    static std::mt19937 generator;
    return distribution(generator);
}



// Common Headers
#include "interval.hpp"
#include "ray.hpp"
#include "vec3.hpp"


#endif  //!UTILS_HPP
