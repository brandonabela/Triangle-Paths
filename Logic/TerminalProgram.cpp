#include "TerminalProgram.h"

void TerminalProgram::initialiseTerminal()
{
    bool requestToQuit = false;
    string commandToProcess;

    cout << "Input the command or #help to view the available commands" << endl;

    while (!requestToQuit)
    {
        cout << "terminal> ";
        cin >> commandToProcess;

        switch(handleCommandType(commandToProcess))
        {
            case FIND_MINIMAL_COMMAND:
            {
                cout << "Calculating minimal path" << endl;
                // TODO Calculate program
                break;
            }

            case HELP_COMMAND:
            {
                cout << "1. " << FIND_MINIMAL_INPUT << " <triangleFile>: To calculate the minimal path of a given file" << endl;
                cout << "2. " << HELP_INPUT << " : To display all the help commands" << endl;
                cout << "3. " << QUIT_INPUT << " : To Exit the Terminal PRogram" << endl;
                break;
            }

            case QUIT_COMMAND:
            {
                requestToQuit = true;
                cout << "You have decided to exit the terminal program" << endl;
                break;
            }

            case INVALID_COMMAND:
            {
                cout << "Invalid input command. Input " << HELP_INPUT << " to view all the commands" << endl;
                break;
            }
        }

        cout << "------------------------------------------------------------\n" << endl;
    }
}

TerminalProgram::CommandType TerminalProgram::handleCommandType(string commandToProcess)
{
    if (commandToProcess.substr(0, 5) == FIND_MINIMAL_INPUT)
    {
        // TODO Process file command
        // TODO Validate given file
        return FIND_MINIMAL_COMMAND;
    }
    else if (commandToProcess.substr(0, 5) == HELP_INPUT)
    {
        return HELP_COMMAND;
    }
    else if (commandToProcess.substr(0, 5) == QUIT_INPUT)
    {
        return QUIT_COMMAND;
    }
    else
    {
        return INVALID_COMMAND;
    }
}
