#include "MinimalTrianglePath.h"

MinimalTrianglePath::createTriangleTreeError MinimalTrianglePath::createTriangleTree(vector<string> treeToCreate)
{
    unsigned int numbersExpected = 0;

    for (const auto &aTreeLevel : treeToCreate)
    {
        string valueToAdd;
        vector<int> vectorToAdd;

        for(char character : aTreeLevel)
        {
            if (isdigit(character))     {   valueToAdd += character;                                        }
            else if (character == ' ')  {   vectorToAdd.push_back(stoi(valueToAdd));    valueToAdd = "";    }
            else                        {   return CONSISTS_OF_LETTERS;                                     }
        }

        if(!valueToAdd.empty() && vectorToAdd.size() != numbersExpected + 1)
        {
            vectorToAdd.push_back(stoi(valueToAdd));
        }

        if (vectorToAdd.size() == numbersExpected + 1)  {   triangleTree.push_back(vectorToAdd);    }
        else                                            {   return INCORRECT_NUMBER_OF_ELEMENTS;    }

        numbersExpected ++;
    }

    return SUCCESSFUL;
}

MinimalTrianglePath::minimalPath MinimalTrianglePath::calculateMinimalPath()
{
    int lowestCostIndex = 0;
    auto triangleTreeSize = (int) triangleTree.size() - 1;

    for (auto i = (int)(triangleTree[triangleTreeSize].size() - 1); i >= 0; i --)
    {
        MinimalPath minimalPath;
        minimalPath.pathCost = triangleTree[triangleTreeSize][i];
        minimalPath.path.push_back(triangleTree[triangleTreeSize][i]);

        calculateRecursivePath(minimalPath, i, triangleTreeSize - 1, !(i == 0 || i == triangleTree[triangleTreeSize].size() - 1));
    }

    for (int i = 0; i < minimalPathVector.size(); i ++)
    {
        if (minimalPathVector[i].pathCost < minimalPathVector[lowestCostIndex].pathCost)    {   lowestCostIndex = i;    }
    }

    return minimalPathVector[lowestCostIndex];
}

void MinimalTrianglePath::calculateRecursivePath(MinimalPath minimalPath, int valueIndex, int currentDepth, bool isWithinTree)
{
    if (currentDepth < 0)
    {
        minimalPathVector.push_back(minimalPath);
    }
    else
    {
        MinimalPath minimalPathInner = minimalPath;

        int leftIndex = 0;
        if (valueIndex > 0) {   leftIndex = valueIndex - 1;     }

        minimalPath.pathCost += triangleTree[currentDepth][leftIndex];
        minimalPath.path.push_back(triangleTree[currentDepth][leftIndex]);

        calculateRecursivePath(minimalPath, leftIndex, currentDepth - 1, !(leftIndex == 0 || leftIndex == triangleTree[currentDepth].size() - 1));

        if(isWithinTree)
        {
            minimalPathInner.pathCost += triangleTree[currentDepth][valueIndex];
            minimalPathInner.path.push_back(triangleTree[currentDepth][valueIndex]);

            calculateRecursivePath(minimalPathInner, valueIndex, currentDepth - 1, !(valueIndex == 0 || valueIndex == triangleTree[currentDepth].size() - 1));
        }
    }
}
