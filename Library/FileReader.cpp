#include "FileReader.h"

vector<string> FileReader::readFile(char *filePath)
{
    vector<string> contentsOfFile;

    ifstream fileStream;
    fileStream.open(filePath);

    if (fileStream)
    {
        string contentsOfCurrentLine;

        while (getline(fileStream, contentsOfCurrentLine))
        {
            contentsOfFile.push_back(contentsOfCurrentLine);
        }
    }

    fileStream.close();

    return contentsOfFile;
}
