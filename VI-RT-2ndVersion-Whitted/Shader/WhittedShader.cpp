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
            if (!f->Kd.isZero()) {
            } // Kd is zero
            continue;
        }  // END of point light
    }  // END iterate over light sources
    return color;
}

RGB WhittedShader::specularReflection (Intersection isect, Phong *f, int depth) {
    RGB color(0.,0.,0.);
    Vector Rdir;
    
    // ...
    // generate the specular ray
    
    // direction R = 2 (N.V) N - V

    return color;
}

RGB WhittedShader::specularTransmission (Intersection isect, Phong *f, int depth) {
    RGB color(0., 0., 0.);
    
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
    if (!f->Kt.isZero() && depth<3) {
        color += specularTransmission (isect, f, depth+1);
    }

    color += directLighting(isect, f);
        
    return color;
};
