#include "puzzle.h"
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <exception>

//+Puzzle(solution : string)
Puzzle::Puzzle(const std::string& solution) : _solution(solution), _guesses(" ") 
{
    if (_solution.empty()) 
    {
        throw std::invalid_argument("Solution cannot be empty.");
    }
}

//+~Puzzle() <<virtual>>
Puzzle::~Puzzle() { }

//+guess(c : char) : bool
bool Puzzle::guess(char c) 
{
    c = std::tolower(c);

    if (!std::isalpha(c)) 
    {
        throw std::invalid_argument("Guess must be a letter.");
    }

    if (_guesses.find(c) != std::string::npos) 
    {
        throw std::invalid_argument("Letter already guessed.");
    }

    _guesses += c;

    return _solution.find(c) != std::string::npos;
}

//+solve(phrase : string) : bool
bool Puzzle::solve(const std::string& phrase) const 
{
    return phrase == _solution;
}

//+board() : string
std::string Puzzle::board() const 
{
    std::string display;

    for (char c : _solution) 
    {
        if (c == ' ') 
        {
            display += ' ';
        } 
        else if (_guesses.find(std::tolower(c)) != std::string::npos) 
        {
            display += c;
        } 
        else 
        {
            display += '_';
        }
    }

    return display;
}

//+guesses() : string
std::string Puzzle::guesses() const 
{
    return _guesses;
}

//+solution() : string
std::string Puzzle::solution() const 
{
    return _solution;
}
