#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char* argv[]) 
{
    std::vector<std::string> words;
    for (int i = 1; i < argc; ++i) 
    {
        words.push_back(std::string(argv[i]));
    }



    std::sort(words.begin(), words.end());


    for ( int i = 0; i < words.size(); ++i) 
    {
        std::cout << words[i] << std::endl;
    }

}
