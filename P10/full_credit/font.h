#ifndef FONT_H
#define FONT_H

#include "ansi.h"

class Font : public ANSI 
{
    private:
        int _font;

    public:
        Font(int font);
        void output(std::ostream& ost) const override;
        auto operator<=>(const Font& rhs) const = default;
};

#endif
