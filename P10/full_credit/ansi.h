#ifndef ANSI_H
#define ANSI_H

#include <iostream>

class ANSI 
{
    protected:
        static const std::string CSI;
    
    
    public:
        virtual ~ANSI() = default;
        virtual void output(std::ostream& ost) const = 0;
        friend std::ostream& operator<<(std::ostream& ost, const ANSI& ansi);
        auto operator<=>(const ANSI& rhs) const = default;
};

#endif
