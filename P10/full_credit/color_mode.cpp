//enum class Color_mode {FOREGROUND, BACKGROUND, RESET};



#include "color_mode.h"
#include <map>

std::ostream& operator<<(std::ostream& ost, const Color_mode& cm) 
{
    static std::map<Color_mode, std::string> text 
    {
        {Color_mode::FOREGROUND, "foreground"},
        {Color_mode::BACKGROUND, "background"},
        {Color_mode::RESET, "reset"}
    };
    ost << text.at(cm);
    return ost;
}
