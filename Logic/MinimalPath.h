#ifndef TRIANGLEPATH_MINIMALPATH_H
#define TRIANGLEPATH_MINIMALPATH_H

#include <iostream>
#include <c++/4.8.3/vector>

using namespace std;

class MinimalPath
{
private:
    vector<vector<int>> triangleTree;

public:
    typedef enum createTriangleTreeError
    {
        SUCCESSFUL,
        INCORRECT_NUMBER_OF_ELEMENTS,
        CONSISTS_OF_LETTERS
    } CreateTriangleTreeError;

    CreateTriangleTreeError createTriangleTree(vector<string> treeToCreate);

    vector<vector<int>> &getTriangleTree();
};


#endif //TRIANGLEPATH_MINIMALPATH_H
