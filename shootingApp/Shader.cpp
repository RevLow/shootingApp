//
//  Shader.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/01.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Shader.h"
#include <fstream>

namespace {
    template<GLenum T>
    GLuint readShader(const std::string& shaderSourcePath);
    std::string fileRead(const std::string& filePath);
}


Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) :
shaderProgram(0)
{
    GLuint vertexShader = readShader<GL_VERTEX_SHADER>(vertexShaderPath);
    assert(vertexShader != 0);
    GLuint fragmentShader = readShader<GL_FRAGMENT_SHADER>(fragmentShaderPath);
    assert(fragmentShader != 0);
    
    shaderProgram = glCreateProgram();
    assert(shaderProgram != 0);
    
    glAttachShader(shaderProgram, vertexShader);
    assert(glGetError() == GL_NO_ERROR);
    
    glAttachShader(shaderProgram, fragmentShader);
    assert(glGetError() == GL_NO_ERROR);
    
    glLinkProgram(shaderProgram);

    // リンクエラーチェック
    {
        GLint linkSuccess = 0;
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linkSuccess);
        if(linkSuccess == GL_FALSE)
        {
            GLint infoLen = 0;
            glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLen);
            
            if(infoLen > 1)
            {
                GLchar* message = new GLchar[infoLen];
                glGetProgramInfoLog(shaderProgram, infoLen, NULL, message);
                fprintf(stderr, "%s", message);
                delete [] message;
            }
        }
        
        assert(linkSuccess == GL_TRUE);
    }
    
    // vertexシェーダ、fragmentシェーダはもう使わないので破棄
    glDeleteShader(vertexShader);
    assert(glGetError() == GL_NO_ERROR);
    glDeleteShader(fragmentShader);
    assert(glGetError() == GL_NO_ERROR);
}

Shader::~Shader()
{
    // シェーダの利用を終了
    glUseProgram(0);
    assert(glGetError() == GL_NO_ERROR);
    
    // シェーダプログラムの破棄
    glDeleteProgram(shaderProgram);
    assert(glGetError() == GL_NO_ERROR);
    assert(glIsProgram(shaderProgram) == GL_FALSE);
}

GLint Shader::getAttribute(const std::string& attribute) const
{
    return glGetAttribLocation(shaderProgram, attribute.c_str());
}

GLint Shader::getUniform(const std::string& fragment) const
{
    return glGetUniformLocation(shaderProgram, fragment.c_str());
}

void Shader::use()
{
    glUseProgram(shaderProgram);
    assert(glGetError() == GL_NO_ERROR);
}

namespace {
    /*
        シェーダのソースコードを読み込む
        @params shaderSourcePath 読み込むシェーダのソースコードパス
        @return シェーダオブジェクト番号
    */
    template<GLenum T>
    GLuint readShader(const std::string& shaderSourcePath)
    {
        // ソースコード読み取り
        const std::string source = std::move(fileRead(shaderSourcePath));
        if(source == "")
        {
            // 失敗処理
            fprintf(stderr, "source read failed");
            return 0;
        }
        
        // シェーダ作成
        GLuint shaderHandle = glCreateShader(T);
        const GLchar* source_c = source.c_str();
        const GLint length = source.length();
        glShaderSource(shaderHandle, 1, &source_c, &length);
        glCompileShader(shaderHandle);
        
        // コンパイルエラーチェック
        {
            GLint compileSuccess = 0;
            glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
            if(compileSuccess == GL_FALSE)
            {
                GLint infoLen = 0;
                glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &infoLen);
                if(infoLen > 1)
                {
                    GLchar* message = new GLchar[infoLen];
                    glGetShaderInfoLog(shaderHandle, infoLen, NULL, message);
                    fprintf(stderr, "%s", message);
                    delete [] message;
                }
                else {
                    fprintf(stderr, "complete error not info...");
                }
            }
            assert(compileSuccess == GL_TRUE);
        }
        
        return shaderHandle;
    }
    
    /*
        ファイルを読み取る
        @params filePath 読み取るファイルへのパス
     */
    std::string fileRead(const std::string& filePath)
    {
        std::ifstream ifs(filePath);
        if (ifs.fail())
        {
            return "";
        }

        std::istreambuf_iterator<char> it(ifs);
        std::istreambuf_iterator<char> last;
        std::string str(it, last);
        return str;
    }
}