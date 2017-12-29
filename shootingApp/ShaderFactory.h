//
//  ShaderFactory.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/04.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__ShaderFactory__
#define __shootingApp__ShaderFactory__

#include "Shader.h"

struct PairEql {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        return h1 ^ h2;
    };
};

class ShaderFactory {
public:
    static const std::unique_ptr<ShaderFactory>& getInstance();
    std::shared_ptr<Shader> makeShader(const std::string& vertexShader, const std::string& fragmentShader);
private:
    ShaderFactory(){};
    // シェーダ情報を格納するハッシュマップ
    // vertexShaderとfragmentShaderのパスのペアをキーにして、値をShaderインスタンスへのweak_ptrにする
    // weak_ptrにする理由は、特定のシェーダがアタッチされたオブジェクトがすべて消去されたときに自動でシェーダを削除するため
    std::unordered_map< std::pair<std::string, std::string>, std::weak_ptr<Shader>, PairEql> map;
    static std::unique_ptr<ShaderFactory> factory;
};

#endif /* defined(__shootingApp__ShaderFactory__) */
