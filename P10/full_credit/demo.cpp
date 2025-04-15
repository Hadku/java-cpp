#include <iostream>
#include "ansi.h"
#include "color.h"
#include "font.h"


int main() 
{
    
    std::cout << Color(0x00, 0x64, 0xB1) << "This is UTA blue \033[0m" << std::endl;
    std::cout << Color(0xF5, 0x80, 0x25) << "This is UTA orange \033[0m" << std::endl;
    std::cout << Color(0xFA, 0x94, 0x40) << "This is UTA alt orange \033[0m" << std::endl;
    std::cout << Color(0xFF, 0xFF, 0xFF) << "This is UTA white \033[0m" << std::endl;
    std::cout << std::endl;

    std::cout << (Color(255, 0, 0) + Color(0, 255, 0)) << "yellow\033[0m" << std::endl;
    std::cout << (Color(255, 0, 0) + Color(0, 0, 255)) << "magenta\033[0m" << std::endl;
    std::cout << (Color(0, 255, 0) + Color(0, 0, 255)) << "cyan\033[0m" << std::endl;
    std::cout << std::endl;

    std::cout << Font(1) << "Style bold" << "\033[0m" << std::endl;
    std::cout << Font(5) << "Style slow blink" << "\033[0m" << std::endl;
    std::cout << Font(9) << "Style strikeout" << "\033[0m" << std::endl;
    std::cout << Font(4) << "Style underline" << "\033[0m" << std::endl;
    std::cout << Font(8) << "Style font #8" << "\033[0m" << std::endl;
    std::cout << Font(3) << "Style italic" << "\033[0m" << std::endl;
    std::cout << Font(7) << "Style reverse" << "\033[0m" << std::endl;
    std::cout << Font(21) << "Style double underline" << "\033[0m" << std::endl;
    std::cout << Font(51) << "Font framed" << "\033[0m" << std::endl;
    std::cout << Font(52) << "Font encircled" << "\033[0m" << std::endl;
    std::cout << Font(53) << "Font overlined" << "\033[0m" << std::endl;
    std::cout << Font(73) << "Script superscript" << "\033[0m" << std::endl;
    std::cout << Font(74) << "Script subscript" << "\033[0m" << std::endl;
    std::cout << std::endl;

    std::cout << Color(0, 0, 0) << "Color black\033[0m" << std::endl;
    std::cout << "\033[48;2;0;0;0m" << "Bkgnd black" << "\033[0m" << std::endl;
    std::cout << Color(0, 0, 255) << "Color blue\033[0m" << std::endl;
    std::cout << "\033[48;2;0;0;255m" << "Bkgnd blue" << "\033[0m" << std::endl;
    std::cout << Color(255, 0, 0) << "Color red\033[0m" << std::endl;
    std::cout << "\033[48;2;255;0;0m" << "Bkgnd red" << "\033[0m" << std::endl;
    std::cout << Color(255, 0, 255) << "Color magenta\033[0m" << std::endl;
    std::cout << "\033[48;2;255;0;255m" << "Bkgnd magenta" << "\033[0m" << std::endl;
    std::cout << Color(0, 255, 0) << "Color green\033[0m" << std::endl;
    std::cout << "\033[48;2;0;255;0m" << "Bkgnd green" << "\033[0m" << std::endl;
    std::cout << Color(0, 255, 255) << "Color cyan\033[0m" << std::endl;
    std::cout << "\033[48;2;0;255;255m" << "Bkgnd cyan" << "\033[0m" << std::endl;
    std::cout << Color(255, 255, 0) << "Color yellow\033[0m" << std::endl;
    std::cout << "\033[48;2;255;255;0m" << "Bkgnd yellow" << "\033[0m" << std::endl;
    std::cout << Color(255, 255, 255) << "Color white\033[0m" << std::endl;
    std::cout << "\033[48;2;255;255;255m" << "Bkgnd white" << "\033[0m" << std::endl;
    std::cout << std::endl;


    std::cout << Font(1) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(2) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(3) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(4) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(5) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(6) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(7) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(8) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(9) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(10) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(51) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(52) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(53) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(73) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(74) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Font(21) << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(0, 0, 0) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;0;0;0m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(0, 0, 255) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;0;0;255m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(255, 0, 0) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;255;0;0m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(255, 0, 255) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;255;0;255m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(0, 255, 0) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;0;255;0m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(0, 255, 255) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;0;255;255m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(255, 255, 0) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;255;255;0m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << Color(255, 255, 255) << "Polymorphic demo\033[0m" << std::endl;
    std::cout << "\033[48;2;255;255;255m" << "Polymorphic demo" << "\033[0m" << std::endl;
    std::cout << std::endl;

    return 0;
}
