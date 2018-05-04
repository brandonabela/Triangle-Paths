#ifndef TRIANGLEPATH_FILEREADER_H
#define TRIANGLEPATH_FILEREADER_H

#include <iostream>
#include <vector>

using namespace std;

class FileReader
{
public:
    vector<string> readFile(char *filePath);
};

#endif //TRIANGLEPATH_FILEREADER_H
