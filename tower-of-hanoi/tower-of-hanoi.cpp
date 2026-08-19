// tower-of-hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// global variables
vector<int> tower[3];
int moves;

// function prototypes
void displayStacks();
void solve(int numberOfDisks, vector<int>& source, vector<int>& destination, vector<int>& temporary);
void moveTopDisk(vector<int>& source, vector<int>& destination);

int main()
{
    
    int init_size;

    // prompt for disk #
    cout << "Enter the starting number of disks: ";
    cin >> init_size;

    // initialize starting tower
    // to represent a stack, we will only access the back of the vector when performing moving operations
    for (int i = init_size; i > 0; --i)
    {
        tower[0].push_back(i);
    }

    // display starting point
    displayStacks();

    // game logic
    moves = 0;
    solve(init_size, tower[0], tower[2], tower[1]);


    //std::cout << "Hello World!\n";
    std::cout << "Total number of moves: " << moves << endl;
    std::cout << "End of program!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/*
    solve(numberOfDisks, source, destination, temporary)
    {
        // Base case: the current subproblem contains only one disk,
        // so it can be moved directly to its destination.
        if (numberOfDisks == 1)
        {
            moveTopDisk(source, destination);
            return;
        }

        // Move the top n - 1 disks out of the way and onto
        // the temporary tower.
        solve(numberOfDisks - 1, source, temporary, destination);

        // Move the largest/base disk of the current subproblem
        // to its final destination.
        moveTopDisk(source, destination);

        // Move the same n - 1 disks from the temporary tower
        // onto the base disk, completing the current subproblem.
        solve(numberOfDisks - 1, temporary, destination, source);
    }
*/

void displayStacks()
{
    
    // calculating tallest tower to determine display scaling
    //int size1 = tower[0].size(), size2 = tower[1].size(), size3 = tower[2].size(), max = 0;
    int tallest_size = 0;
    for (int i = 0; i < 3; i++)
    {
        if (tower[i].size() > tallest_size)
        {
            tallest_size = tower[i].size();
        }
    }

    // since prints start from top to bottom, use the size of each tower to determine when to start printing each one
    cout << "    >> Move " << moves << " <<" << endl;
    cout << "--------------------" << endl;
    for (int i = tallest_size; i > 0; i--)
    {
        cout << "|   ";
        // check if tower 1 reaches the current height to print; if so print it, if not leave empty space
        if (tower[0].size() >= i)
        {
            cout << setw(2) << tower[0][i-1] << "   ";
        }
        else
        {
            cout << "     ";
        }
        // same for tower 2
        if (tower[1].size() >= i)
        {
            cout << setw(2) << tower[1][i-1] << "   ";
        }
        else
        {
            cout << "     ";
        }
        // same for tower 3
        if (tower[2].size() >= i)
        {
            cout << setw(2) << tower[2][i-1] << "   |";
        }
        else
        {
            cout << "     |";
        }
        cout << endl;
    }
    cout << "|   " << "__   __   __   |" << endl;
    cout << "--------------------" << endl << endl;
}

// a solution using the recursive function
void solve(int numberOfDisks, vector<int>& source, vector<int>& destination, vector<int>& temporary)
{
    // base case
    if (numberOfDisks == 1)
    {
        moveTopDisk(source, destination);
        return;
    }

    // Move the top n - 1 disks out of the way and onto
    // the temporary tower.
    solve(numberOfDisks - 1, source, temporary, destination);

    // Move the largest/base disk of the current subproblem
    // to its final destination.
    moveTopDisk(source, destination);

    // Move the same n - 1 disks from the temporary tower
    // onto the base disk, completing the current subproblem.
    solve(numberOfDisks - 1, temporary, destination, source);
}

void moveTopDisk(vector<int>& source, vector<int>& destination)
{
    if (source.empty())
        return;
    
    int temp = source.back();
    source.pop_back();
    destination.push_back(temp);
    moves++;
    displayStacks();
}