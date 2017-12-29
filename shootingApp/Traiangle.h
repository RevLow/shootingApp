//
//  Traiangle.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/01.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Traiangle__
#define __shootingApp__Traiangle__

#include "Base.h"

class Triangle : public Base {
public:
    Triangle(std::initializer_list<GLfloat> position);
    Triangle(std::initializer_list<GLfloat> position, std::initializer_list<GLubyte> color);
    //virtual void draw();
};

#endif /* defined(__shootingApp__Traiangle__) */
