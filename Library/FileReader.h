#ifndef TRIANGLEPATH_FILEREADER_H
#define TRIANGLEPATH_FILEREADER_H

#include <iostream>
#include <vector>

using namespace std;

class FileReader
{
public:
    /** Method which is responsible for reading the contents of a given file path and returning a vector of strings
     *  consisting the text found in the file excluding the EOF token
     *
     * @param filePath the file path which is going to be read
     * @return a vector of strings each line is represented as an element in the vector
     */
    static vector<string> readFile(char *filePath);
};

#endif //TRIANGLEPATH_FILEREADER_H
