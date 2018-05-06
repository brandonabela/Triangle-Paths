# Triangle Paths

This project aims to find the minimal path of numbers in form of a triangle, by starting at the top of the triangle and moving to adjacent numbers on the row below. Consider, the below example:

<p align="center"> <img width="auto" height="200" alt="Triangle of Numbers" src="../master/GitHubResources/TriangleOfNumbers.JPG"> </p>

If such a problem had to be solved using brute force by checking every possible path such an attempt would be time-consuming. An example of a valid path using the above diagram is 7 → 6 → 3 → 11 and such a path has a path cost of 7+6+3+11 = 18. The program takes a text file as input and based on this text file the minimal path will be computed and returning the shortest path together with the cost of the chosen path.

The program is controlled like a terminal were the user is allowed to input one of the commands listed below:

| Command                 | Description                                         |
| -------------           | -------------                                       |
| #find <source program>  | To calculate the minimal path of a given text file  |
| #help                   | To display all the help commands                    |
| #quit                   | To Exit the Terminal Program                        |

The program makes a number of validations before performing the minimal path of the numbers in the form of a triangle. Some of the validations made is checking whether the text file consists of letters and checks if the source file is given together with the command. An example of the program solving the minimal path is shown below:

<p align="center"> <img width="auto" height="250" alt="Program Example 1" src="../master/GitHubResources/Program01Example.JPG"> </p>
