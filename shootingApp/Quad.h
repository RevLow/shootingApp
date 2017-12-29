//
//  Quad.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/04.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Quad__
#define __shootingApp__Quad__

#include "Base.h"

class Quad : public Base {
public:
    Quad(std::initializer_list<GLfloat> positions);
    Quad(std::initializer_list<GLfloat> positions,
         std::initializer_list<GLubyte> color,
         std::initializer_list<GLfloat> uv);
};

#endif /* defined(__shootingApp__Quad__) */
