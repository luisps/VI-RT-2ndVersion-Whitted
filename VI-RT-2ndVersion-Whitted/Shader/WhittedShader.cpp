//
//  WhittedShader.cpp
//  VI-RT-LPS
//
//  Created by Luis Paulo Santos on 14/03/2023.
//

#include "WhittedShader.hpp"
#include "Phong.hpp"
#include "ray.hpp"

RGB WhittedShader::directLighting (Intersection isect, Phong *f) {
    RGB color(0.,0.,0.);
    
    // Loop over scene's light sources
    for (auto l = scene->lights.begin() ; l != scene->lights.end() ; l++) {
        
        if ((*l)->type == AMBIENT_LIGHT) {  // is it an ambient light ?
            if (!f->Ka.isZero()) {
                RGB Ka = f->Ka;
                color += Ka * (*l)->L();
            }
            continue;
        }
        if ((*l)->type == POINT_LIGHT) {  // is it a point light ?
            // ...
           
            continue;
        }  // END of point light
    }  // END iterate over light sources
    return color;
}

inline Vector refract(const Vector& V, const Vector& N, double IOR) {
    auto cos_theta = std::fmin(N.dot(-1.*V), 1.0);

    Vector const r_out_perp =  IOR * (V + cos_theta*N);
    Vector const r_out_parallel = -std::sqrt(std::fabs(1.0 - r_out_perp.normSQ())) * N;
    Vector T = r_out_perp + r_out_parallel;
    T.normalize();
    return T;
}

inline Vector reflect(const Vector& V, const Vector& N) {
    float cos = N.dot(V);
    return 2.f * cos * N - V;
}

RGB WhittedShader::specularReflection (Intersection isect, Phong *f, int depth) {
    RGB color(0.,0.,0.);
    
    // ...
    // generate the specular ray
    


    return color;
}

RGB WhittedShader::specularTransmission (Intersection isect, Phong *f, int depth) {
    RGB color(0., 0., 0.);

    // generate the transmission ray
    // from https://raytracing.github.io/books/RayTracingInOneWeekend.html#dielectrics
    // ...

    return color;
}

RGB WhittedShader::shade(bool intersected, Intersection isect, int depth) {
    RGB color(0.,0.,0.);
    
    // if no intersection, return background
    if (!intersected) {
        return (background);
    }
    if (isect.isLight) { // intersection with a light source
        return isect.Le;
    }
    // get the BRDF
    Phong *f = (Phong *)isect.f;
    
    // if there is a specular component sample it
    if (!f->Ks.isZero() && depth<3) {
        color += specularReflection (isect, f, depth+1);
    }
    // if there is a specular component sample it
    if (!f->Kt.isZero() && depth<7) {
        color += specularTransmission (isect, f, depth+1);
    }

    color += directLighting(isect, f);
        
    return color;
};
