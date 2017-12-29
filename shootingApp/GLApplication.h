//
//  GLApplication.h
//  shootingApp
//
//  Created by Tetsushi on 2017/09/30.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__GLApplication__
#define __shootingApp__GLApplication__

#include "Traiangle.h"
#include "Quad.h"
#include "Render.h"


// 各OSごとのOpenGLESコンテキスト格納するためのクラス
class GLContext;
class GLApplication {
public:
    GLApplication(std::unique_ptr<GLContext> context);
    void update(float tick);

    inline void setRenderBuffer(GLuint bufferId){ _renderBuffer = bufferId; };
    inline GLuint getRenderBuffer() const { return _renderBuffer; };

    inline void setFrameBuffer(GLuint bufferId){ _frameBuffer = bufferId; };
    inline GLuint getFrameBuffer() const { return _frameBuffer; };
private:
    std::unique_ptr<GLContext> _context;
    std::unique_ptr<Quad> _quad;
    std::unique_ptr<Render> _render;
    std::shared_ptr<Shader> _shader;
    GLuint _renderBuffer;
    GLuint _frameBuffer;
};

#endif /* defined(__shootingApp__GLApplication__) */
