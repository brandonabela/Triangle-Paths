#ifndef TRIANGLEPATH_MINIMALTRIANGLEPATH_H
#define TRIANGLEPATH_MINIMALTRIANGLEPATH_H

#include <iostream>
#include <vector>

using namespace std;

class MinimalTrianglePath
{
public:
    typedef enum createTriangleTreeError
    {
        SUCCESSFUL,
        INCORRECT_NUMBER_OF_ELEMENTS,
        CONSISTS_OF_LETTERS
    } CreateTriangleTreeError;

    typedef struct minimalPath
    {
        int pathCost;
        vector<int> path;
    } MinimalPath;

private:
    vector<vector<int>> triangleTree;
    vector<MinimalPath> minimalPathVector;

public:
    CreateTriangleTreeError createTriangleTree(vector<string> treeToCreate);

    MinimalPath calculateMinimalPath();
    void calculateRecursivePath(MinimalPath minimalPath, int valueIndex, int currentDepth, bool isWithinTree);
};


#endif //TRIANGLEPATH_MINIMALTRIANGLEPATH_H
