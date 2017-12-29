//
//  Base.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/05.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Base__
#define __shootingApp__Base__

#include "Vertex.h"

class Base {
public:
    Base(std::initializer_list<GLfloat> position);
    Base(std::initializer_list<GLfloat> position,
         std::initializer_list<GLubyte> color,
         std::initializer_list<GLfloat> uv);
    const std::vector<Vertex>& refVertex() const { return _vertex; };
    const std::vector<unsigned short>& refIndices() const { return _indices; };
protected:
    std::vector<Vertex> _vertex;
    std::vector<unsigned short>  _indices;
};

#endif /* defined(__shootingApp__Base__) */
