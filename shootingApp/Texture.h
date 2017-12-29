//
//  Texture.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/09.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Texture__
#define __shootingApp__Texture__

#include "Image.h"

class Texture {
public:
    Texture(const std::string& filename);
    virtual ~Texture();
    GLuint _textureID;
    std::unique_ptr<Png> img;
};

#endif /* defined(__shootingApp__Texture__) */
