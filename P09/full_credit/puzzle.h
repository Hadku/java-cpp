//#ifndef PUZZLE_H
//#define PUZZLE_H

#include <string>

class Puzzle 
{
    //-_solution : string
    //-_guesses : string
    private:
        std::string _solution;
        std::string _guesses;

    public:
        //+Puzzle(solution : string)
        Puzzle(const std::string& solution);

//    public:
        //~Puzzle() <<virtual>>
        virtual ~Puzzle();

  //  public:
        //+guess(c : char) : bool
        bool guess(char c);

    //public:
        //+solve(phrase string) : bool
        bool solve(const std::string& phrase) const;

//    public:
        //+board() : string
        std::string board() const;

  //  public:
        //+guesses() : string
        std::string guesses() const;

    //public:
        //+solution() : string
        std::string solution() const;


};

//#endif
