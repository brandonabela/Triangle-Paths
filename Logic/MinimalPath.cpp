#include "MinimalPath.h"

MinimalPath::createTriangleTreeError MinimalPath::createTriangleTree(vector<string> treeToCreate)
{
    bool addValue = false;
    vector<int> vectorToAdd;
    unsigned int numbersExpected = 0;

    for (const auto &aTreeLevel : treeToCreate)
    {
        string valueToAdd;

        for(char character : aTreeLevel)
        {
            if (isdigit(character))     {   valueToAdd += character;        }
            else if (character == ' ')  {   addValue = true;                }
            else                        {   return CONSISTS_OF_LETTERS;     }
        }

        if(!valueToAdd.empty() || addValue)
        {
            vectorToAdd.push_back(stoi(valueToAdd));
            valueToAdd = "";
        }

        if (vectorToAdd.size() == numbersExpected + 1)
        {
            triangleTree.push_back(vectorToAdd);
            vectorToAdd.empty();
        }
        else
        {
            return INCORRECT_NUMBER_OF_ELEMENTS;
        }

        numbersExpected ++;
    }

    return SUCCESSFUL;
}

vector<vector<int>> &MinimalPath::getTriangleTree()
{
    return triangleTree;
}
