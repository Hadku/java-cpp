#include <iostream>
#include "color.h"
#include <stdexcept>
#include <map>
#include <algorithm>


const std::string Color::RGB = ";2;";

Color::Color() : _mode(Color_mode::RESET), _red(0), _green(0), _blue(0) {}

Color::Color(int red, int green, int blue, Color_mode mode) : _mode(mode), _red(red), _green(green), _blue(blue) 
{
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
    {
        throw std::invalid_argument("Color component out of range");
    }
}

Color Color::operator+(const Color& other) const 
{
    auto blend = [](int a, int b) -> int 
    {
        return 255 - (255 - a) * (255 - b) / 255;
    };
    return Color(blend(_red, other._red), blend(_green, other._green), blend(_blue, other._blue));
}

void Color::output(std::ostream& ost) const 
{
    static std::map<Color_mode, int> code 
    {
        {Color_mode::FOREGROUND, 38},
        {Color_mode::BACKGROUND, 48},
        {Color_mode::RESET, 0}
    };

    ost << CSI << code[_mode];
    if (_mode != Color_mode::RESET)
    {
        ost << RGB << _red << ';' << _green << ';' << _blue;
    }
    ost << 'm';
}
