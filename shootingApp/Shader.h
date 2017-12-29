//
//  Shader.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/01.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Shader__
#define __shootingApp__Shader__

class Shader {
    // シェーダクラスはファクトリ経由でのみ作成することが出来るようにする
    friend class ShaderFactory;
public:
    virtual ~Shader();
    void use();
    GLuint shaderProgram;
    GLint getAttribute(const std::string& attr) const;
    GLint getUniform(const std::string& str) const;
private:
    Shader(const std::string& vertexShader, const std::string& fragmentShader);
};

#endif /* defined(__shootingApp__Shader__) */
