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
                std::cout << R"(
                                   .''.
       .''.      .        *''*    :_\/_:     .
      :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.
  .''.: /\ :    /)\   ':'* /\ *  : '..'.  -=:o:=-
 :_\/_:'.:::.  | ' *''*    * '.\'/.'_\(/_'.':'.'
 : /\ : :::::  =  *_\/_*     -= o =- /)\    '  *
  '..'  ':::' === * /\ *     .'/.\'.  ' ._____
      *        |   *..*         :       |.   |' .---"|
        *      |     _           .--'|  ||   | _|    |
        *      |  .-'|       __  |   |  |    ||      |
     .-----.   |  |' |  ||  |  | |   |  |    ||      |
 ___'       ' /"\ |  '-."".    '-'   '-.'    '`      |____
jgs~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  &                    ~-~-~-~-~-~-~-~-~-~   /|
 ejm97    )      ~-~-~-~-~-~-~-~  /|~       /_|\
        _-H-__  -~-~-~-~-~-~     /_|\    -~======-~
~-\XXXXXXXXXX/~     ~-~-~-~     /__|_\ ~-~-~-~
~-~-~-~-~-~    ~-~~-~-~-~-~    ========  ~-~-~-~

                )" << std::endl;
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
                       .,-#%&$@%#&#~,.
                    ..-:"''         ''"-..
                 .-'                      '-.
               .'              .     .       '.
             .'   .          .    .      .    .''.
           .'  .    .       .   .   .     .   . ..:.
         .' .   . .  .       .   .   ..  .   . ....::.
        ..   .   .      .  .    .     .  ..  . ....:IA.
       .:  .   .    .    .  .  .    .. .  .. .. ....:IA.
      .: .   .   ..   .    .     . . .. . ... ....:.:VHA.
      '..  .  .. .   .       .  . .. . .. . .....:.::IHHB.
     .:. .  . .  . .   .  .  . . . ...:.:... .......:HIHMM.
    .:.... .   . ."::"'.. .   .  . .:.:.:II;,. .. ..:IHIMMA
    ':.:..  ..::IHHHHHI::. . .  ...:.::::.,,,. . ....VIMMHM
   .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM
  .:.:V.:IVHHHHHHHMHMHHH::..:" .:HIHHHHHHHHHHHHHMHHA. .VMMM.
  :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:VMMI
  ::V..:VIHHHHHHMMMHHHHHH. .   .I":IIMHHMMHHHHHHHHHHHAPI:WMM
  ::". .:.HHHHHHHHMMHHHHHI.  . .:..I:MHMMHHHHHHHHHMHV:':H:WM
  :: . :.::IIHHHHHHMMHHHHV  .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW
  '.  ..:..:.:IHHHHHMMHV" .AVMHMA.:.'VHMMMMHHHHHV:' .  :IHWV
   :.  .:...:".:.:TPP"   .AVMMHMMA.:. "VMMHHHP.:... .. :IVAI
  .:.   '... .:"'   .   ..HMMMHMMMA::. ."VHHI:::....  .:IHW'
  ...  .  . ..:IIPPIH: ..HMMMI.MMMV:I:.  .:ILLH:.. ...:I:IM
: .   .'"' .:.V". .. .  :HMMM:IMMMI::I. ..:HHIIPPHI::'.P:HM.
:.  .  .  .. ..:.. .    :AMMM IMMMM..:...:IV":T::I::.".:IHIMA
'V:.. .. . .. .  .  .   'VMMV..VMMV :....:V:.:..:....::IHHHMH
  "IHH:.II:.. .:. .  . . . " :HB"" . . ..PI:.::.:::..:IHHMMV"
   :IP""HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM"
   :V:. VIMA:I..  .     .  . .. . .  .:.I:I:..:IHHHHMMHHMMM
   :"VI:.VWMA::. .:      .   .. .:. ..:.I::.:IVHHHMMMHMMMMI
   :."VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI
   :..VIHIHMMMI...::.,:.,:!"I:!"I!"I!"V:AI:VAMMMMMMHMMMMMM'
   ':.:HIHIMHHA:"!!"I.:AXXXVVXXXXXXXA:."HPHIMMMMHHMHMMMMMV
     V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM
       'I::IVA ASSSSXSSSSBBSBMBSSSSSSBBMMMBS.VVMMHIMM'"'
        I:: VPAIMSSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI
       .I::. "H:XIIXBBMMMMMMMMMMMMMMMMMBXIXXMMPHIIMM'
       :::I.  ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM
       :::I:.  .VSSSSSISISISSSBII:ISSSSBMMB:MI:..:MM
       ::.I:.  ':"SSSSSSSISISSXIIXSSSSBMMB:AHI:..MMM.
       ::.I:. . ..:"BBSSSSSSSSSSSSBBBMMMB:AHHI::.HMMI
       :..::.  . ..::":BBBBBSSBBBMMMB:MMMMHHII::IHHMI
       ':.I:... ....:IHHHHHMMMMMMMMMMMMMMMHHIIIIHMMV"
         "V:. ..:...:.IHHHMMMMMMMMMMMMMMMMHHHMHHMHP'
          ':. .:::.:.::III::IHHHHMMMMMHMHMMHHHHM"
            "::....::.:::..:..::IIIIIHHHHMMMHHMV"
              "::.::.. .. .  ...:::IIHHMMMMHMV"
                "V::... . .I::IHHMMV"'
                  '"VHVHHHAHHHHMMV:"')" << 
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
                        .,-#%&$@%#&#~,.
                     ..-:"''         ''"-..
                  .-'                      '-.
                .'              .     .       '.
              .'   .          .    .      .    .''.
            .'  .    .       .   .   .     .   . ..:.
          .' .   . .  .       .   .   ..  .   . ....::.
         ..   .   .      .  .    .     .  ..  . ....:IA.
        .:  .   .    .    .  .  .    .. .  .. .. ....:IA.
       .: .   .   ..   .    .     . . .. . ... ....:.:VHA.
       '..  .  .. .   .       .  . .. . .. . .....:.::IHHB.
      .:. .  . .  . .   .  .  . . . ...:.:... .......:HIHMM.
     .:.... .   . ."::"'.. .   .  . .:.:.:II;,. .. ..:IHIMMA
     ':.:..  ..::IHHHHHI::. . .  ...:.::::.,,,. . ....VIMMHM
    .:::I. .AHHHHHHHHHHAI::. .:...,:IIHHHHHHMMMHHL:. . VMMMM
   .:.:V.:IVHHHHHHHMHMHHH::..:" .:HIHHHHHHHHHHHHHMHHA. .VMMM.
   :..V.:IVHHHHHMMHHHHHHHB... . .:VPHHMHHHMMHHHHHHHHHAI.:VMMI
   ::V..:VIHHHHHHMMMHHHHHH. .   .I":IIMHHMMHHHHHHHHHHHAPI:WMM
   ::". .:.HHHHHHHHMMHHHHHI.  . .:..I:MHMMHHHHHHHHHMHV:':H:WM
   :: . :.::IIHHHHHHMMHHHHV  .ABA.:.:IMHMHMMMHMHHHHV:'. .IHWW
   '.  ..:..:.:IHHHHHMMHV" .AVMHMA.:.'VHMMMMHHHHHV:' .  :IHWV
    :.  .:...:".:.:TPP"   .AVMMHMMA.:. "VMMHHHP.:... .. :IVAI
   .:.   '... .:"'   .   ..HMMMHMMMA::. ."VHHI:::....  .:IHW'
   ...  .  . ..:IIPPIH: ..HMMMI.MMMV:I:.  .:ILLH:.. ...:I:IM
 : .   .'"' .:.V". .. .  :HMMM:IMMMI::I. ..:HHIIPPHI::'.P:HM.
 :.  .  .  .. ..:.. .    :AMMM IMMMM..:...:IV":T::I::.".:IHIMA
 'V:.. .. . .. .  .  .   'VMMV..VMMV :....:V:.:..:....::IHHHMH
   "IHH:.II:.. .:. .  . . . " :HB"" . . ..PI:.::.:::..:IHHMMV"
    :IP""HHII:.  .  .    . . .'V:. . . ..:IH:.:.::IHIHHMMMMM"
    :V:. VIMA:I..  .     .  . .. . .  .:.I:I:..:IHHHHMMHHMMM
    :"VI:.VWMA::. .:      .   .. .:. ..:.I::.:IVHHHMMMHMMMMI
    :."VIIHHMMA:.  .   .   .:  .:.. . .:.II:I:AMMMMMMHMMMMMI
    :..VIHIHMMMI...::.,:.,:!"I:!"I!"I!"V:AI:VAMMMMMMHMMMMMM'
    ':.:HIHIMHHA:"!!"I.:AXXXVVXXXXXXXA:."HPHIMMMMHHMHMMMMMV
      V:H:I:MA:W'I :AXXXIXII:IIIISSSSSSXXA.I.VMMMHMHMMMMMM
        'I::IVA ASSSSXSSSSBBSBMBSSSSSSBBMMMBS.VVMMHIMM'"'
         I:: VPAIMSSSSSSSSSBSSSMMBSSSBBMMMMXXI:MMHIMMI
        .I::. "H:XIIXBBMMMMMMMMMMMMMMMMMBXIXXMMPHIIMM'
        :::I.  ':XSSXXIIIIXSSBMBSSXXXIIIXXSMMAMI:.IMM
        :::I:.  .VSSSSSISISISSSBII:ISSSSBMMB:MI:..:MM
        ::.I:.  ':"SSSSSSSISISSXIIXSSSSBMMB:AHI:..MMM.
        ::.I:. . ..:"BBSSSSSSSSSSSSBBBMMMB:AHHI::.HMMI
        :..::.  . ..::":BBBBBSSBBBMMMB:MMMMHHII::IHHMI
        ':.I:... ....:IHHHHHMMMMMMMMMMMMMMMHHIIIIHMMV"
          "V:. ..:...:.IHHHMMMMMMMMMMMMMMMMHHHMHHMHP'
           ':. .:::.:.::III::IHHHHMMMMMHMHMMHHHHM"
             "::....::.:::..:..::IIIIIHHHHMMMHHMV"
               "::.::.. .. .  ...:::IIHHMMMMHMV"
                 "V::... . .I::IHHMMV"'
                   '"VHVHHHAHHHHMMV:"')" << 
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
                std::cout << R"(
                                   .''.
       .''.      .        *''*    :_\/_:     .
      :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.
  .''.: /\ :    /)\   ':'* /\ *  : '..'.  -=:o:=-
 :_\/_:'.:::.  | ' *''*    * '.\'/.'_\(/_'.':'.'
 : /\ : :::::  =  *_\/_*     -= o =- /)\    '  *
  '..'  ':::' === * /\ *     .'/.\'.  ' ._____
      *        |   *..*         :       |.   |' .---"|
        *      |     _           .--'|  ||   | _|    |
        *      |  .-'|       __  |   |  |    ||      |
     .-----.   |  |' |  ||  |  | |   |  |    ||      |
 ___'       ' /"\ |  '-."".    '-'   '-.'    '`      |____
jgs~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  &                    ~-~-~-~-~-~-~-~-~-~   /|
 ejm97    )      ~-~-~-~-~-~-~-~  /|~       /_|\
        _-H-__  -~-~-~-~-~-~     /_|\    -~======-~
~-\XXXXXXXXXX/~     ~-~-~-~     /__|_\ ~-~-~-~
~-~-~-~-~-~    ~-~~-~-~-~-~    ========  ~-~-~-~


                )" << std::endl;
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




