//
//  Image.h
//  shootingApp
//
//  Created by Tetsushi on 2017/10/11.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#ifndef __shootingApp__Image__
#define __shootingApp__Image__

class Image {
public:
    Image(const std::string& fileName);
};

class Png : public Image
{
public:
    Png(const std::string& fileName);
    virtual ~Png();
    unsigned int getWidth();
    unsigned int getHeight();
    bool hasAlpha();
    unsigned char* imageBuffer();
private:
    const std::string _fileName;
    unsigned char* _data;
    png_uint_32 _width, _height;
    int _bitDepth, _colorType, _interlaceType;
    int _compressType, _filterMethod;
    
};


#endif /* defined(__shootingApp__Image__) */
