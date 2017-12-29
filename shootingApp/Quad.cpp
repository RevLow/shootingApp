//
//  Quad.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/04.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Quad.h"


Quad::Quad(std::initializer_list<GLfloat> positions) : Base(positions)
{
}

Quad::Quad(std::initializer_list<GLfloat> positions,
           std::initializer_list<GLubyte> color,
           std::initializer_list<GLfloat> uv) : Base(positions, color, uv)
{
    _indices.emplace_back(0);
    _indices.emplace_back(1);
    _indices.emplace_back(2);
    
    _indices.emplace_back(1);
    _indices.emplace_back(2);
    _indices.emplace_back(3);
}
