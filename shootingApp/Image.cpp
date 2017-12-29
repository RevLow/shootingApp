//
//  Image.cpp
//  shootingApp
//
//  Created by Tetsushi on 2017/10/11.
//  Copyright (c) 2017年 RevLow. All rights reserved.
//

#include "Image.h"

namespace {
    std::unique_ptr<unsigned char> readBuffer(const std::string& filename);
}



Image::Image(const std::string& filename)
{
}


Png::Png(const std::string& filename) : Image(filename),
_fileName(filename),
_data(nullptr),
_width(0),
_height(0),
_bitDepth(0),
_colorType(0),
_interlaceType(0),
_compressType(0),
_filterMethod(0)
{
    std::unique_ptr<unsigned char> data = std::move(readBuffer(filename));
}

/*
{

    
    
    FILE* fp = fopen(filename.c_str(), "rb");
    if (fp == nullptr)
    {
        fclose(fp);
        return;
    }
    
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if(png == nullptr)
    { 
        fclose(fp);
        return;
    }
    
    png_infop info = png_create_info_struct(png);
    if (info == nullptr) {
        png_destroy_read_struct(&png, nullptr, nullptr);
        fclose(fp);
        return;
    }
    
    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, nullptr);
        fclose(fp);
        return;
    }
    
    png_init_io(png, fp);
    
    unsigned int sig_bytes = 0;
    png_set_sig_bytes(png, sig_bytes);
    
    png_read_png(png, info, (PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND), nullptr);
    png_get_IHDR(png, info, &_width, &_height, &_bitDepth, &_colorType, &_interlaceType, &_compressType, &_filterMethod);
    
    unsigned int row_bytes = png_get_rowbytes(png, info);
    if (_data != nullptr) {
        delete [] _data;
    }
    
    _data = new unsigned char[row_bytes * _height];
    
    png_bytepp rows = png_get_rows(png, info);
    for (int i = 0; i< _height; i++)
    {
        memcpy(_data + (row_bytes * i), rows[i], row_bytes);
    }
    
    png_destroy_read_struct(&png, &info, nullptr);
    fclose(fp);
}*/

Png::~Png()
{
    if(_data) delete [] _data;
}

unsigned int Png::getWidth()
{
	return _width;
}

unsigned int Png::getHeight()
{
	return _height;
}

unsigned char* Png::imageBuffer()
{
	return _data;
}

bool Png::hasAlpha()
{
	if (_colorType == PNG_COLOR_TYPE_RGBA) {
		return true;
	}
	return false;
}

