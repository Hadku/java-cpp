#include <iostream>
#include "firecracker.h"
#include <stdexcept>
#include <exception>



//+Firecracker(length : int)

Firecracker::Firecracker(int length) : _length(length) 
{
    if (_length < 3) 
    {
        throw std::invalid_argument("Fuse length must be at least 3.");
    }
}

/*Firecracker(int length) { std::cout << "  ____________            (\n" <<
                                    " /           /\\           )\\\n" <<
                                    "|    BOOM   | -|----------{,}\n" <<
                                    " \\___________\\/\n" << std::endl; }*/


//+~Firecracker() <<virtual>>
Firecracker::~Firecracker() { }

//+tic() : bool
bool Firecracker::tic()
{
    if (_length > 0)
    {
        --_length;
    }
    return _length > 0;
}

//+firecracker() : string
std::string Firecracker::firecracker() const
{
    //std::ostringstream oss;
    std::string BOOM; 

    BOOM += "  ____________            (\n";
    BOOM += " /           /\\           )\\\n";
    BOOM += "|    BOOM   | -|----------{,}\n";
    BOOM += " \\___________\\/\n";

    BOOM += "  Fuse: ";
    BOOM += std::string(_length, '-');
    BOOM += "\n";

    return BOOM;


}