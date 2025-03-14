//
//  mesh.hpp
//  VI-RT
//
//  Created by Luis Paulo Santos on 05/02/2023.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "geometry.hpp"
#include "vector.hpp"
#include <math.h>

class Triangle: public Geometry {
public:
    bool BackFaceCulling;
    Point v1, v2, v3;
    Vector normal;           // geometric normal
    Vector edge1, edge2;
    BB bb;      // face bounding box
                // this is min={0.,0.,0.} , max={0.,0.,0.} due to the Point constructor
    bool intersect (Ray r, Intersection *isect);
    bool isInside(Point p);
    
    Triangle(Point _v1, Point _v2, Point _v3, Vector _normal, bool backface=true): v1(_v1), v2(_v2), v3(_v3), normal(_normal) {
        edge1 = v1.vec2point(v2);
        edge2 = v1.vec2point(v3);
        bb.min.set(v1.X, v1.Y, v1.Z);
        bb.max.set(v1.X, v1.Y, v1.Z);
        bb.update(v2);
        bb.update(v3);
        BackFaceCulling = backface;
    }
    
    Triangle(Point _v1, Point _v2, Point _v3, bool backface=false): v1(_v1), v2(_v2), v3(_v3), BackFaceCulling(backface) {
        edge1 = v1.vec2point(v2);
        edge2 = v1.vec2point(v3);
        // compute the geometric normal as the cross product of the 2 vectors spawned by the vertices
        normal = edge1.cross(edge2);
        normal.normalize();

        bb.min.set(v1.X, v1.Y, v1.Z);
        bb.max.set(v1.X, v1.Y, v1.Z);
        bb.update(v2);
        bb.update(v3);
    }
    
    // Heron's formula
    // https://www.mathopenref.com/heronsformula.html
    float area () {
        
        // ...
        
        //const float A = ...
        const float A = 1.f;

        return A;
    }
    float points_area (Point v1, Point v2, Point v3) {
        
        // ...
        
        //const float A = ...
        const float A = 1.f;

        return A;

    }
};

#endif /* triangle_hpp */
