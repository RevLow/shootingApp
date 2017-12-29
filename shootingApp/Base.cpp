//
//  Base.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/05.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Base.h"

Base::Base(std::initializer_list<GLfloat> position) :
Base(position,
     {0, 0, 0},
     { 1.0, 0.0,
       1.0, 1.0,
       0.0, 0.0,
       0.0, 1.0 })
{
}

Base::Base(std::initializer_list<GLfloat> position,
           std::initializer_list<GLubyte> color,
           std::initializer_list<GLfloat> uv)
{
    const GLubyte* color_ptr = color.begin();
    const GLfloat* uv_ptr = uv.begin();
    for (const GLfloat *pos = position.begin();
         pos != position.end();
         pos+=3)
    {
        Vertex v({
                    {pos[0], pos[1], pos[2]},
                    {color_ptr[0], color_ptr[1], color_ptr[2], color_ptr[3]},
                    {uv_ptr[0], uv_ptr[1]}
                  });
        _vertex.emplace_back(std::move(v));
        
        if (color_ptr + 4 != color.end())
        {
            color_ptr += 4;
        }
        if (uv_ptr + 2 != uv.end())
        {
            uv_ptr += 2;
        }
    }
}