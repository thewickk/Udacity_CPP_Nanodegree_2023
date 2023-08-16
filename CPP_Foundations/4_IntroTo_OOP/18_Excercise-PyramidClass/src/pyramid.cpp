#include <stdexcept>
#include "../inc/pyramid.h"

Pyramid::Pyramid(int length, int width, int height)
    : length_{length}, width_{width}, height_{height} 
{
    Validate();
}

// Accessors
int Pyramid::GetLength() const { return length_; }
int Pyramid::GetWidth() const { return width_; }
int Pyramid::GetHeight() const { return height_; }

// Mutators
void Pyramid::SetLength(int length)
{
    length_ = length;
    Validate();
}

void Pyramid::SetWidth(int width)
{
    width_ = width;
    Validate();
}

void Pyramid::SetHeight(int height)
{
    height_ = height;
    Validate();
}

// Public member functions
float Pyramid::Volume() const { return GetLength() * GetWidth() * GetHeight() / 3.0; }

// Private member functions
void Pyramid::Validate()
{
    if (length_ <= 0 || width_ <= 0 || height_ <= 0)
    throw std::invalid_argument("negative dimensioin");
}


