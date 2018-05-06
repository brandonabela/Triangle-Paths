#include <iostream>
#include "Logic/TerminalProgram.h"

using namespace std;

// Method responsible for starting the entire program
int main()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "|              Running Triangle Path Program               |" << endl;
    cout << "------------------------------------------------------------" << endl;

    TerminalProgram terminalProgram;
    terminalProgram.initialiseTerminal(); // Loading the terminal program

    cout << "------------------------------------------------------------" << endl;
    cout << "|           Stopped Running Triangle Path Program           |" << endl;
    cout << "------------------------------------------------------------" << endl;

    return 0;
}
