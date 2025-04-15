#include <iostream>
#include "font.h"

/*private:
//-_font : int

public:
//+Font(font : int)

//+red : int, green : int, blue : int, mode : Color_mode <<default>>

//+output(ost : ostream&) <<const>> <<overide>>*/


Font::Font(int font) : _font(font) {}

void Font::output(std::ostream& ost) const 
{
    ost << CSI << _font << 'm';
}
