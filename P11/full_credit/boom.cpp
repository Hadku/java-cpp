#include "firecracker.h"
#include "puzzle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <iterator>
#include <exception>

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        std::cerr << "Use ./boom [file name]\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) 
    {
        std::cerr << "Could not open file.\n";
        return 1;
    }

    std::set<std::string> quotes;
    std::string line;
    while (std::getline(file, line)) 
    {
        if (!line.empty())
        {
            quotes.insert(line);
        }
    }

    if (quotes.empty()) 
    {
        std::cerr << "No puzzles found in the file.\n";
        return 1;
    }

    srand(time(NULL));
    int index = rand() % quotes.size();
    auto it = quotes.begin();
    std::advance(it, index);
    std::string selected = *it;

    Firecracker firecracker(8);
    Puzzle puzzle(selected);
    bool playing = true;

    while (playing) 
    {
        std::cout << puzzle.board() << "\n\n";
        std::cout << firecracker.firecracker() << std::endl;
        std::cout << "Guesses: " << puzzle.guesses() << "\n\n";
        std::cout << "Enter a letter (! to guess solution, 0 to quit): " << std::endl;

        char input;
        std::cin >> input;

        if (input == '0') 
        {
            std::cout << "You gave up\nThe answer was: " << puzzle.solution() << "\n\n";
            break;
        }

        if (input == '!') 
        {
            std::cout << "Enter your full guess: " << std::endl;
            std::string attempt;
            std::cin.ignore();
            std::getline(std::cin, attempt);
            if (puzzle.solve(attempt)) 
            {
                std::cout << "You win\n" << std::endl;
            } 
            else 
            {

                std::cout << R"(

                _.-^^---....,,--
            _--                  --_
           <                        >)
           |                         |
            \\._                   _./
               ```--. . , ; .--'''
                     | |   |
                  .-=||  | |=-.
                  `-=#$%&%$#=-'
                     | ;  :|
            _____.,-#%&$@%#&#~,._____ )" << 
                            std::endl; 
                std::cout << "Wrong guess\nYou lose!\n";
                std::cout << "The correct phrase was: " << puzzle.solution() << "\n\n";
            }
            break;
        }

        try 
        {
            int matches = puzzle.guess(input);
            std::cout << "Matches found: " << matches << "\n";

            if (matches == 0) 
            {
                if (!firecracker.tic()) 
                {
                    std::cout << R"(

                    _.-^^---....,,--
                _--                  --_
               <                        >)
               |                         |
                \\._                   _./
                   ```--. . , ; .--'''
                         | |   |
                      .-=||  | |=-.
                      `-=#$%&%$#=-'
                         | ;  :|
                _____.,-#%&$@%#&#~,._____ )" << 
                                std::endl; 
                    std::cout << "You lose!\n";
                    std::cout << "The correct phrase was: " << puzzle.solution() << "\n\n";
                    break;
                }
            } 
            else if (puzzle.board() == puzzle.solution()) 
            {
                std::cout << puzzle.board() << "\n";
                std::cout << "You win\n";
                break;
            }
        } 
        catch (std::invalid_argument& e) 
        {
            std::cout << "Invalid guess: " << e.what() << "\n";
        }
    }

    return 0;
}




/*#include "firecracker.h"
#include "puzzle.h"
#include <iostream>
#include <string>
#include <exception>


//+main(argc : int, argv : char*) : int
int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        std::cerr << "Use ./boom '__________[your phrase]___________'\n";
        return 1;
    }

    std::string secret = argv[1];
    Firecracker firecracker(8);
    Puzzle puzzle(secret);
    bool playing = true;


    while (playing) 
    {
        std::cout << puzzle.board() << "\n" << std::endl;
        std::cout << firecracker.firecracker() << std::endl;
        std::cout << "Guesses: " << puzzle.guesses() << "\n" << std::endl;
        std::cout << "Enter a letter (! to guess solution, 0 to quit): " << std::endl;

        char input;
        std::cin >> input;

        if (input == '0') 
        {
            std::cout << "You gave up\n The answer was: " << puzzle.solution() << "\n" << std::endl;
            break;
        }

        if (input == '!') 
        {
            std::cout << "Enter your full guess: " << std::endl;
            std::string attempt;
            std::cin.ignore(); 
            std::getline(std::cin, attempt);
            if (puzzle.solve(attempt)) 
            {
                std::cout << "You win\n" << std::endl;
            } 
            else 
            {
                std::cout << "Wrong guess\n" << std::endl;
            }
            break;
        }

        try 
        {
            if (!puzzle.guess(input)) 
            {
                if (!firecracker.tic()) 
                {
                    std::cout << "You lose!\n" << std::endl;
                    std::cout << "The correct phrase was: " << puzzle.solution() << "\n" << std::endl;
                    break;
                }
            } 
            else if (puzzle.board() == puzzle.solution()) 
            {
                std::cout << puzzle.board() << "\n" << std::endl;
                std::cout << "You win\n" << std::endl;
                break;
            }
        } 
        catch (std::invalid_argument& e) 
        {
            std::cout << "Invalid guess: " << e.what() << "\n" << std::endl;
        }
    }

    return 0;

}*/