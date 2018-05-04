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
    typedef enum commandType
    {
        FIND_MINIMAL_COMMAND,
        HELP_COMMAND,
        QUIT_COMMAND,
        INVALID_COMMAND
    } CommandType;

    CommandType handleCommandType(string commandToProcess);

public:
    void initialiseTerminal();
};

#endif //TRIANGLEPATH_TERMINALPROGRAM_H
