#ifndef HITTABLE_H
#define HITTABLE_H

#include "utils.hpp"

class material;

class hit_record {
public:
  hit_record() : p(1,1,1),normal(0,0,1), t(0) {};
  point3 p;
  vec3 normal;
  shared_ptr<material> mat;
  double t;
  bool front_face;

  void set_face_normal(const ray &r, const vec3 &outward_normal) {
    // Sets the record normal vector .
    // The parameter 'outward normal' is assumed to have unit length
    front_face = dot(r.direction(), outward_normal) < 0.0;
    normal = front_face ? outward_normal : -outward_normal;
  }
};

class hittable {
public:
 
  virtual ~hittable() = default;

  virtual bool hit(const ray &r,interval ray_t, hit_record& rec) const = 0;
};

#endif // !HITTABLE_H