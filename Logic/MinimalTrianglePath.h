#ifndef TRIANGLEPATH_MINIMALTRIANGLEPATH_H
#define TRIANGLEPATH_MINIMALTRIANGLEPATH_H

#include <iostream>
#include <vector>

using namespace std;

class MinimalTrianglePath
{
public:
    // Enum which stores if method was executed successfully or an error while creating the triangle
    typedef enum createTriangleTreeError
    {
        SUCCESSFUL,
        INCORRECT_NUMBER_OF_ELEMENTS,
        CONSISTS_OF_LETTERS
    } CreateTriangleTreeError;

    // Responsible for storing a minimal path structure
    typedef struct minimalPathStructure
    {
        vector<int> path; // Stores the path

        // Constructor
        explicit minimalPathStructure(int path)
        {
            MinimalPath::path.push_back(path);
        }

        // Method which is responsible for computing the path cost of the path
        int computePathCost()
        {
            int pathCost = 0;
            for (int aPathValue : path) {   pathCost += aPathValue; }
            return pathCost;
        }
    } MinimalPath;

private:
    // The triangle tree will be represented example [[1], [2, 3], [4, 5, 6]] where each element represents a level in the triangle
    vector<vector<int>> triangleTree; // Stores the triangle of numbers

public:
    /** Method which is responsible for converting the read file into a tree of numbers
     *
     * @param treeToCreate a vector of strings which are going to be converted into triangle of numbers
     * @return if the method was successfully run or if the tree to create consisted of unexpected tokens like letters
     */
    CreateTriangleTreeError createTriangleTree(vector<string> treeToCreate);

    /** Method which is responsible for the computation of the minimal path
     *
     * @return a structure which consists of the path chosen and within the structure a method computes the path cost
     */
    MinimalPath calculateMinimalPath();
};

#endif //TRIANGLEPATH_MINIMALTRIANGLEPATH_H
