#include "vec3.hpp"
#include "color.hpp"
#include "ray.hpp"
#include <iostream>

int main()
{
    //Image
    const int image_width{256}, image_height{256};

    //Render
     std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n" ;

     for(int j = image_height - 1; j >= 0; --j)
     {
        std::cerr << "\r Scanlines remaining: " << j << std::flush;
        for (int i = 0 ; i < image_width ; ++i) {
            color pixel_color(double(i)/(image_width - 1), double(j)/(image_height - 1));
            // writeColor(std::cout , pixel_color);
        }
     }

     std::cerr << "\nDone\n" ;

    return 0;
}