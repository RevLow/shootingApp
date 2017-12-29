//
//  Render.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/07.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Render__
#define __shootingApp__Render__

#include "Base.h"
#include "Shader.h"
#include "Texture.h"

class Render {
public:
    Render();
    virtual ~Render();
    void addShape(const Base& baseShape);
    void setTexture(std::unique_ptr<Texture>& texture) { _texture = std::move(texture); };
    void draw(const Shader& shader);
private:
    GLuint _vertexBuffer;
    GLuint _indicesBuffer;
    std::unique_ptr<Texture> _texture;
};

#endif /* defined(__shootingApp__Render__) */
