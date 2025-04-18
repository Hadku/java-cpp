//#ifndef FIRECRACKER_H
//#define FIRECRACKER_H


#include <string>


class Firecracker
{
    //-_length : int
    private:
        int _length;
    
    public:
        Firecracker();
        Firecracker(int length);

    //public:
        virtual ~Firecracker();
    
//    public:
        bool tic();

    //+firecracker() : string
  //  public:
        std::string firecracker() const;
};

//#endif
