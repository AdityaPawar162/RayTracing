#ifndef ray_hpp
#define ray_hpp

#include "vec3.hpp"

class ray {
public:
  ray() : orig(point3(0,0,0)),dir(vec3(0,0,0)) {}

  ray(const point3& origin, const point3& direction) : orig(origin), dir(direction) {}

  point3 origin() const { return orig; }
  vec3 direction() const { return dir; }

  point3 at(double t) const { return orig + t * dir; }

private:
  point3 orig;
  vec3 dir;

  
};

#endif  // !ray_hpp 
