//
//  Phong.hpp
//  VI-RT
//
//  Created by Luis Paulo Santos on 07/02/2023.
//

#ifndef Phong_hpp
#define Phong_hpp

#include "RGB.hpp"
#include "BRDF.hpp"

class Phong: public BRDF {
public:
    RGB Ka;
    float rough;
    Phong () {rough=1.;}
};

#endif /* Phong_hpp */
