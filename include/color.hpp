#ifndef COLOR_HPP
#define COLOR_HPP

#include <iostream>
#include "vec3.hpp"

using color = vec3;

inline double linear_to_gamma(double linear_component)
{
  return sqrt(linear_component);
}

void writeColor(std::ostream &out, color pixel_color,int samples_per_pixels) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  // Divide the color by the number of samples
  auto scale = 1.0/samples_per_pixels;
  r *= scale;
  g *= scale;
  b *= scale;

    // Apply the linear to gamma transform.
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Write the translated [0,255] value of each color component.
     const interval intensity(0.000, 0.999);

      out << static_cast<int>(256*intensity.clamps(r)) << ' '
        << static_cast<int>(256*intensity.clamps(g)) << ' '
        << static_cast<int>(256*intensity.clamps(b)) << '\n';
}


#endif //  !COLOR_HPP 
