#include <iostream>


int main(int argc, char* argv[]) 
{
    std::string s1;
    std::cout << "What is your name? ";
    std::getline(std::cin, s1);
    std::cout << "Hello, " << s1 << std::endl;
}
