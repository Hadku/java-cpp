#include "puzzle.h"
#include <stdexcept>
#include <cctype>
#include <exception>
#include <algorithm>
#include <sstream>

//+Puzzle(solution : string)
Puzzle::Puzzle(const std::string& solution) : _solution(solution), _guesses(" ") 
{
    if (_solution.empty()) 
    {
        throw std::invalid_argument("Solution cannot be empty.");
    }

    for (char& c : _solution) 
    {
        c = std::tolower(c);
    }
}

//+~Puzzle() <<virtual>>
Puzzle::~Puzzle() { }

//+guess(c : char) : int
int Puzzle::guess(char c) 
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
    return std::count(_solution.begin(), _solution.end(), c);
}

//+solve(phrase : string) : bool
bool Puzzle::solve(const std::string& phrase) const 
{
    std::string lowered = phrase;
    for (char& c : lowered) c = std::tolower(c);
    return lowered == _solution;
}

//+board() : string
std::string Puzzle::board() const 
{
    std::ostringstream oss;
    std::istringstream iss(_solution);
    char c;

    while (iss.get(c)) 
    {
        if (!std::isalpha(c) || _guesses.find(c) != std::string::npos) 
        {
            oss << c;
        } 
        else 
        {
            oss << '_';
        }
    }

    return oss.str();
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




/*#include "puzzle.h"
#include <stdexcept>
#include <cctype>
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
*/