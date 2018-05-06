#ifndef TRIANGLEPATH_TERMINALPROGRAM_H
#define TRIANGLEPATH_TERMINALPROGRAM_H

#define FIND_MINIMAL_INPUT  "#find"
#define HELP_INPUT          "#help"
#define QUIT_INPUT          "#quit"

#define CONTENT_READ_SPACE  "   "

#include <iostream>

using namespace std;

class TerminalProgram
{
private:
    // An enum to determine the type of command the user has inputted
    typedef enum commandType
    {
        FIND_MINIMAL_COMMAND,
        HELP_COMMAND,
        QUIT_COMMAND,
        INVALID_COMMAND
    } CommandType;

    /** Method which is responsible for determining the type of command the user has inputted and returning the type
     *  of command the user has inputted
     *
     * @param commandToProcess the entire string the user has inputted in the terminal program
     * @return the type of command the user has inputted
     */
    CommandType handleCommandType(string commandToProcess);

public:
    // Method which is responsible for booting a terminal like program
    void initialiseTerminal();
};

#endif //TRIANGLEPATH_TERMINALPROGRAM_H
