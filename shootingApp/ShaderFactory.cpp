//
//  ShaderFactory.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/04.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "ShaderFactory.h"

std::unique_ptr<ShaderFactory> ShaderFactory::factory = nullptr;

const std::unique_ptr<ShaderFactory>& ShaderFactory::getInstance() {
    if(factory == nullptr)
    {
        factory = std::unique_ptr<ShaderFactory>(new ShaderFactory());
    }

    return factory;
}

std::shared_ptr<Shader> ShaderFactory::makeShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    std::pair<std::string, std::string> shaderPair = {vertexShader, fragmentShader};
    if (map.count(shaderPair) != 0)
    {
        auto ptr = map[shaderPair];
        // まだ失効したシェーダでない場合はそれを返す
        if (!ptr.expired())
        {
            return ptr.lock();
        }
    }
    
    //std::shared_ptr<Shader> shader = std::make_shared<Shader>(shaderPair.first, shaderPair.second);
    struct impl : Shader {
        impl(const std::string& str1, const std::string& str2) : Shader(str1, str2) {}
    };
    auto p = std::make_shared<impl>(shaderPair.first, shaderPair.second);
    std::shared_ptr<Shader> shader = std::move(p);
    map[shaderPair] = shader;
    return shader;
}