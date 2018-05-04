#include "TerminalProgram.h"
#include "../Library/FileReader.h"
#include "MinimalPath.h"

void TerminalProgram::initialiseTerminal()
{
    bool requestToQuit = false;
    string commandToProcess;

    cout << "Input the command or #help to view the available commands" << endl;

    while (!requestToQuit)
    {
        cout << "terminal> ";
        getline(cin, commandToProcess);

        switch(handleCommandType(commandToProcess))
        {
            case FIND_MINIMAL_COMMAND:
            {
                string filePath;
                cout << "Calculating minimal path" << endl;

                if (commandToProcess.length() > 6)
                {
                    filePath = commandToProcess.substr(6, commandToProcess.length());
                    vector<string> contentOfFile = FileReader::readFile(const_cast<char *>(filePath.c_str()));

                    if (contentOfFile.empty())
                    {
                        cout << "The file path you have inputted was invalid" << endl;
                        break;
                    }

                    cout << "Contents of given file are: " << endl;
                    for(const auto &aFileLine : contentOfFile)  {   cout << CONTENT_READ_SPACE << aFileLine << endl;  }
                    cout << CONTENT_READ_SPACE << "EOF \n" << endl;

                    MinimalPath minimalPath;

                    switch(minimalPath.createTriangleTree(contentOfFile))
                    {
                        case MinimalPath::SUCCESSFUL:
                        {
                            cout << "The Triangle Tree was successfully created" << endl;
                            break;
                        }

                        case MinimalPath::INCORRECT_NUMBER_OF_ELEMENTS:
                        {
                            cout << "The given file has incorrect number of elements" << endl;
                            break;
                        }

                        case MinimalPath::CONSISTS_OF_LETTERS:
                        {
                            cout << "The given file consists of letters" << endl;
                            break;
                        }
                    }

                    // TODO Executing Minimal Path
                }
                else
                {
                    cout << "The triangle file was not found" << endl;
                }

                // TODO Calculate minimal path

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
    if (commandToProcess.substr(0, 5) == FIND_MINIMAL_INPUT)    {   return FIND_MINIMAL_COMMAND;    }
    else if (commandToProcess.substr(0, 5) == HELP_INPUT)       {   return HELP_COMMAND;            }
    else if (commandToProcess.substr(0, 5) == QUIT_INPUT)       {   return QUIT_COMMAND;            }
    else                                                        {   return INVALID_COMMAND;         }
}
