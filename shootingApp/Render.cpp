//
//  Render.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/07.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Render.h"

Render::Render() {
    glGenBuffers(1, &_vertexBuffer);
    assert(glGetError() == GL_NO_ERROR);
    assert(_vertexBuffer != 0);
    
    glGenBuffers(1, &_indicesBuffer);
    assert(glGetError() == GL_NO_ERROR);
    assert(_indicesBuffer != 0);
}

Render::~Render()
{
    glDeleteBuffers(1, &_vertexBuffer);
    glDeleteBuffers(1, &_indicesBuffer);
}

void Render::addShape(const Base &baseShape)
{
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, baseShape.refVertex().size() * (3 * sizeof(GLfloat) + 4 * sizeof(GLubyte) + 2 * sizeof(GLfloat)), (GLfloat*)&baseShape.refVertex()[0], GL_STATIC_DRAW);
    assert(glGetError() == GL_NO_ERROR);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, baseShape.refIndices().size()*sizeof(unsigned short), &baseShape.refIndices()[0], GL_STATIC_DRAW);
    assert(glGetError() == GL_NO_ERROR);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Render::draw(const Shader &shader)
{
    // バッファのバインド
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indicesBuffer);
    assert(glGetError() == GL_NO_ERROR);
    
    // 位置の設定
    GLuint attrPos = shader.getAttribute("attr_pos");
    glEnableVertexAttribArray(attrPos);
    glVertexAttribPointer(attrPos, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, pos));
    assert(glGetError() == GL_NO_ERROR);
    
    // 色の設定
    GLuint attrColor = shader.getAttribute("attr_color");
    glEnableVertexAttribArray(attrColor);
    glVertexAttribPointer(attrColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));

    // UVの設定
    GLuint unif_texture = shader.getUniform("texture");
    glUniform1i(unif_texture, 0);
    
    GLuint attrUv = shader.getAttribute("attr_uv");
    glEnableVertexAttribArray(attrUv);
    glVertexAttribPointer(attrUv, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, uv));
    assert(glGetError() == GL_NO_ERROR);
    
    // draw
    glDrawElements(GL_TRIANGLE_STRIP, 6, GL_UNSIGNED_SHORT, (GLvoid*)0);
    GLenum errorcode = glGetError();
    assert(errorcode == GL_NO_ERROR);

    // バッファのアンバインド
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    assert(glGetError() == GL_NO_ERROR);
}
