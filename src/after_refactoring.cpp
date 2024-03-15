#include "utils.hpp"
#include "color.hpp"
#include "camera.hpp"
#include "material.hpp"  // Make sure this is before "sphere.hpp"
#include "hittable_list.hpp"
#include "sphere.hpp"



int main(){

    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, material_ground));

        for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_generator();
            point3 center(a + 0.9*random_generator(), 0.2, b + 0.9*random_generator());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_generator(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));


   
    /*
    auto R  = cos(pi/4);

    auto material_left  = make_shared<lambertian>(color(0,0,1));
    auto material_right = make_shared<lambertian>(color(1,0,0));

    world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
    world.add(make_shared<sphere>(point3( R, 0, -1), R, material_right));   
    */

    camera cam;

    cam.aspect_ratio = 16.0/9.0;
    cam.image_width  = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth = 50;

    cam.vfov      = 20;
    cam.lookfrom  = point3(13,2,3);
    cam.lookat    = point3(0,0,0);
    cam.vup       = vec3(0,1,0);

    cam.defocus_angle = 0.6;
    cam.focus_dist = 10.0;
    cam.render(world);

}