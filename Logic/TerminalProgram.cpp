#include "TerminalProgram.h"

#include "../Library/FileReader.h"
#include "MinimalTrianglePath.h"

void TerminalProgram::initialiseTerminal()
{
    bool requestToQuit = false;
    string commandToProcess;

    cout << "Input the command or #help to view the available commands" << endl;

    while (!requestToQuit)
    {
        cout << "C:\\> ";
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

                    MinimalTrianglePath minimalTrianglePath;

                    switch(minimalTrianglePath.createTriangleTree(contentOfFile))
                    {
                        case MinimalTrianglePath::SUCCESSFUL:
                        {
                            cout << "The Triangle Tree was successfully created" << endl;

                            MinimalTrianglePath::MinimalPath minimalPath = minimalTrianglePath.calculateMinimalPath();

                            cout << "Minimal Path is: ";
                            for(auto i = (int)(minimalPath.path.size() - 1); i >= 0; i --)
                            {
                                cout << minimalPath.path[i];
                                if (i != 0) {   cout << ", ";   }
                            }
                            cout << "\nThe minimal Path has a weight of: " << minimalPath.computePathCost() << endl;

                            break;
                        }

                        case MinimalTrianglePath::INCORRECT_NUMBER_OF_ELEMENTS:
                        {
                            cout << "The given file has incorrect number of elements" << endl;
                            break;
                        }

                        case MinimalTrianglePath::CONSISTS_OF_LETTERS:
                        {
                            cout << "The given file consists of letters" << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "The triangle file was not found" << endl;
                }

                break;
            }

            case HELP_COMMAND:
            {
                cout << "1. " << FIND_MINIMAL_INPUT << " <triangleFile> : To calculate the minimal path of a given text file" << endl;
                cout << "2. " << HELP_INPUT << " : To display all the help commands" << endl;
                cout << "3. " << QUIT_INPUT << " : To Exit the Terminal Program" << endl;
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
