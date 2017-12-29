//
//  iOS用のOpenGL処理クラス
//  GLApplication-ios.mm
//  shootingApp
//
//  Created by Tetsushi on 2017/09/30.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "GLApplication.h"
#include "GLContext-ios.h"
#include "ShaderFactory.h"


GLApplication::GLApplication(std::unique_ptr<GLContext> context) :
_renderBuffer(0),
_frameBuffer(0),
_context(std::move(context)),
_quad(new Quad({ -1.0f, 1.0f, 0.0f,
                 -1.0f, -1.0f, 0.0f,
                  1.0f, 1.0f,  0.0f,
                  1.0f, -1.0f, 0.0
               },
               {   255,     0,    0, 255,
                     0,   255,    0, 255,
                     0,     0,  255, 255,
                   255,   255,    0, 255
               },
               { 0.20f, 0.1f,
                 0.20f, 1.0f,
                 0.80f, 0.1f,
                 0.80f, 1.0f
               }))

{
    _shader = ShaderFactory::getInstance()->makeShader("/Users/tetsushi2/Library/Application Support/iPhone Simulator/7.1/Applications/04B54CE7-9EF0-444D-B6C7-1CFC637FD1BA/shootingApp.app/shader.vs", "/Users/tetsushi2/Library/Application Support/iPhone Simulator/7.1/Applications/04B54CE7-9EF0-444D-B6C7-1CFC637FD1BA/shootingApp.app/shader.fs");
    _shader->use();
    
    _render = std::unique_ptr<Render>(new Render());
    _render->addShape(*_quad);
    std::unique_ptr<Texture> texture =std::unique_ptr<Texture>(new Texture("/Users/tetsushi2/Desktop/ch_ms_001_002.texb.png"));
    _render->setTexture(texture);
}

void GLApplication::update(float tick)
{
    // 背景色を初期化
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // カラーバッファを塗りつぶし
    glClear(GL_COLOR_BUFFER_BIT);

    _render->draw(*_shader);
    
    // フレームバッファの内容を描画する(iOS用)
    glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffer);
    [_context->getContext() presentRenderbuffer:GL_RENDERBUFFER];
}