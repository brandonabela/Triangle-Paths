#include <iostream>
#include "Logic/TerminalProgram.h"

using namespace std;

int main()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "|              Running Triangle Path Program               |" << endl;
    cout << "------------------------------------------------------------" << endl;

    TerminalProgram terminalProgram;
    terminalProgram.initialiseTerminal();

    cout << "------------------------------------------------------------" << endl;
    cout << "|           Stopped Running Triangle Path Program           |" << endl;
    cout << "------------------------------------------------------------" << endl;

    return 0;
}
