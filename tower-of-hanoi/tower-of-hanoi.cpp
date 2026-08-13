// tower-of-hanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> tower1, tower2, tower3;
    
    int init_size;

    // prompt for disk #
    cout << "Enter the starting number of disks: ";
    cin >> init_size;

    // initialize starting tower
    for (int i = init_size; i > 0; i--)
    {
        tower1.push_back(i);
    }


    std::cout << "Hello World!\n";
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