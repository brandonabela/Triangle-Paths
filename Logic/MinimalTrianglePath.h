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

    typedef struct minimalPathStructure
    {
        vector<int> path;

        explicit minimalPathStructure(int path)
        {
            MinimalPath::path.push_back(path);
        }

        int computePathCost()
        {
            int pathCost = 0;
            for (int aPathValue : path) {   pathCost += aPathValue; }
            return pathCost;
        }
    } MinimalPath;

private:
    vector<vector<int>> triangleTree;

public:
    CreateTriangleTreeError createTriangleTree(vector<string> treeToCreate);

    MinimalPath calculateMinimalPath();
};


#endif //TRIANGLEPATH_MINIMALTRIANGLEPATH_H
