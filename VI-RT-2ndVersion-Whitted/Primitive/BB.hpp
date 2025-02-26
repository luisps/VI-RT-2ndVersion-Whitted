//
//  AABB.hpp
//  VI-RT
//
//  Created by Luis Paulo Santos on 30/01/2023.
//

#ifndef BB_hpp
#define BB_hpp

#include "vector.hpp"
#include "ray.hpp"
#include <limits>

// pbrt 3rd edition, pag 214 (pbrt.org)
static constexpr float MachineEpsilon =
    std::numeric_limits<float>::epsilon() * 0.5;

// pbrt 3rd edition, pag 217 (pbrt.org)
inline constexpr float gamma(int n) {
    return (n * MachineEpsilon) / (1 - n * MachineEpsilon);
}
    
typedef struct BB {
public:
    Point min, max;
    void update (Point p) {
        if (p.X < min.X) min.X = p.X;
        else if (p.X > max.X) max.X = p.X;
        if (p.Y < min.Y) min.Y = p.Y;
        else if (p.Y > max.Y) max.Y = p.Y;
        if (p.Z < min.Z) min.Z = p.Z;
        else if (p.Z > max.Z) max.Z = p.Z;
    }
    /*
     * I suggest you implement:
     *  bool intersect (Ray r) { }
     *
     * based on PBRT's 3rd ed. book , sec 3.1.2, pags 125..128 + 214,217,221
     *
     * or https://doi.org/10.1007/978-1-4842-7185-8_2
     *
     */
    bool intersect (Ray r) {
        return true;
    }
} BB;

#endif /* AABB_hpp */
