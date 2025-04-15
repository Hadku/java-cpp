#ifndef COLOR_H
#define COLOR_H

#include "ansi.h"
#include "color_mode.h"
#include <stdexcept>

class Color : public ANSI 
{
    private:
        Color_mode _mode;
        int _red;
        int _green;
        int _blue;
        static const std::string RGB;

    public:
        Color();
        Color(int red, int green, int blue, Color_mode mode = Color_mode::FOREGROUND);
        Color operator+(const Color& other) const;
        void output(std::ostream& ost) const override;
};

#endif
