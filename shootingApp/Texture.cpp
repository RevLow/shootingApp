//
//  Texture.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/09.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Texture.h"

Texture::Texture(const std::string& filename)
{
    glGenTextures(1, &_textureID);
    assert(_textureID != 0);
    assert(glGetError() == GL_NO_ERROR);
    
    glBindTexture(GL_TEXTURE_2D, _textureID);
    assert(glGetError() == GL_NO_ERROR);
    
    img = std::unique_ptr<Png>(new Png(filename));
    
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    assert(glGetError() == GL_NO_ERROR);
    
    // VRAMにピクセル情報をコピーする
    glTexImage2D(GL_TEXTURE_2D, 0, img->hasAlpha() ? GL_RGBA : GL_RGB,
                 img->getWidth(), img->getHeight(),
                 0, img->hasAlpha() ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, img->imageBuffer());
    assert(glGetError() == GL_NO_ERROR);
    
    // テクスチャ領域外の補間方法
    // GL_CLAMP_TO_EDGEは端の色をそのままコピーする
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    // 拡大時の補間方法
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // 縮小時の補間方法
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    assert(glGetError() == GL_NO_ERROR);
}

Texture::~Texture()
{
    glBindTexture(_textureID, 0);
    glDeleteTextures(1, &_textureID);
    assert(glGetError() == GL_NO_ERROR);
}