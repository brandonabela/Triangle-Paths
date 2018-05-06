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

MinimalTrianglePath::MinimalPath MinimalTrianglePath::calculateMinimalPath()
{
    vector<MinimalPath> minimalPath;

    for (int bottomTriangleValue : triangleTree[triangleTree.size() - 1])
    {
        minimalPath.emplace_back(minimalPathStructure(bottomTriangleValue));
    }

    for (int i = triangleTree.size() - 2; i >= 0; --i)
    {
        vector<int> usedIndexVector;

        for (int j = 0; j < triangleTree[i].size(); ++j)
        {
            int indexToUse = (minimalPath[j].computePathCost() < minimalPath[j + 1].computePathCost()) ? j : j + 1;

            if (0 < j && usedIndexVector[j - 1] == indexToUse)
            {
                indexToUse ++;
                minimalPath[indexToUse].path = minimalPath[indexToUse - 1].path;
            }

            minimalPath[indexToUse].path.emplace_back(triangleTree[i][j]);
            usedIndexVector.push_back(indexToUse);
        }

        for (int j = 0; j < triangleTree[i].size() ; j++)
        {
            if(usedIndexVector[j] != j)
            {
                minimalPath.erase(minimalPath.begin() + j);
                break;
            }
        }
    }

    return minimalPath[0];
}
