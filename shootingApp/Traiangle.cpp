//
//  Traiangle.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/01.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Traiangle.h"

Triangle::Triangle(std::initializer_list<GLfloat> position) : Base(position)
{
}

Triangle::Triangle(std::initializer_list<GLfloat> position, std::initializer_list<GLubyte> color) : Base(position, color, {1.0, 1.0})
{
}

/*
void Triangle::draw()
{
    if (_shader == nullptr) return;
    static GLfloat addPos[3] = {0.01f, 0.0f, 0.0f};

    GLint attrPos = _shader->getAttribute("attr_pos");
    glEnableVertexAttribArray(attrPos);
    
    GLint unifColor = _shader->getUniform("unif_color");
    glUniform4fv(unifColor, 1, _color.get());

    GLint unifPos = _shader->getUniform("unif_pos");
 
    glVertexAttribPointer(attrPos, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLvoid*>(_position.get()));
    
    glUniform3f(unifPos, -addPos[0], addPos[1], addPos[2]);
    addPos[0] += 0.01f;
    glDrawArrays(GL_TRIANGLES, 0, 3);
}*/