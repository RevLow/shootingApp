//
//  GLContext.h
//  shootingApp
//
//  Created by Tetsushi on 2017/09/30.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef shootingApp_GLContext_h
#define shootingApp_GLContext_h

class GLContext {
public:
    GLContext() {
        // iOS用のコンテキストオブジェクトを生成
        _context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES3];
        [EAGLContext setCurrentContext:_context];
    }

    EAGLContext* getContext(){
        return _context;
    }
private:
    EAGLContext* _context;
};

#endif
