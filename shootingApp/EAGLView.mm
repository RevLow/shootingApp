//
//  EAGLView.m
//  shootingApp
//
//  Created by Tetsushi on 2017/09/28.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#import "EAGLView.h"
#import "GLApplication.h"
#import "GLContext-ios.h"

@implementation EAGLView
{
    std::unique_ptr<GLApplication> glApplication;
}

// OpenGLES用のレイヤーを使うことを明示
+(Class)layerClass
{
    return [CAEAGLLayer class];
}

-(id)initWithFrame:(CGRect)frame
{
    if(self = [super initWithFrame:frame]){
        [self setUp];
        // ゲームループ
        [NSTimer scheduledTimerWithTimeInterval:1.0/60.0f target:self selector:@selector(update:) userInfo:nil repeats:YES];
    }

    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    glViewport(0, 0, self.frame.size.width, self.frame.size.height);
}

-(void) setUp
{
    CAEAGLLayer* layer = (CAEAGLLayer*)self.layer;
    layer.opaque = YES;
    std::unique_ptr<GLContext> context(new GLContext());
    
    // レンダーバッファのセットアップ
    GLuint renderBuffer;
    glGenRenderbuffers(1, &renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, renderBuffer);
    [context->getContext() renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer];

    //フレームバッファのセットアップ
    GLuint frameBuffer;
    glGenFramebuffers(1, &frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, renderBuffer);

    std::unique_ptr<GLApplication> app(new GLApplication(std::move(context)));
    app->setFrameBuffer(frameBuffer);
    app->setRenderBuffer(renderBuffer);
    glApplication = std::move(app);
}

-(void)update: (NSTimer*)timer
{
    glApplication->update([timer timeInterval]);
}

@end
