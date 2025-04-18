#include "firecracker.h"
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

}