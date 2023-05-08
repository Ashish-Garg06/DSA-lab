#include <iostream>  
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int &moves)
{ // define the towerOfHanoi function that takes in four parameters: the number of disks (n), the rod the disks are currently on (from_rod), the rod the disks need to be moved to (to_rod), a spare rod that can be used to temporarily hold disks (aux_rod), and a reference to an integer that keeps track of the total number of moves (moves)
    if (n == 1)
    {                                                                                // if there is only one disk to be moved
        moves++;                                                                     // increment the total number of moves
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl; // print out the instruction to move the disk from the 'from' rod to the 'to' rod
        return;                                                                      // exit the function
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, moves);                                 // recursively call the towerOfHanoi function, moving n-1 disks from the 'from' rod to the 'auxiliary' rod, using the 'to' rod as the temporary rod, and passing in the same integer reference for moves
    moves++;                                                                               // increment the total number of moves
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl; // print out the instruction to move the nth disk from the 'from' rod to the 'to' rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, moves);                                 // recursively call the towerOfHanoi function, moving n-1 disks from the 'auxiliary' rod to the 'to' rod, using the 'from' rod as the temporary rod, and passing in the same integer reference for moves
}

int main()
{                                                       
    int n;                                              // declare an integer variable to store the number of disks
    cout << "Enter the number of disks: ";              // prompt the user to enter the number of disks
    cin >> n;                                           // read in the number of disks from the user
    int moves = 0;                                      // initialize the total number of moves to 0
    towerOfHanoi(n, 'A', 'C', 'B', moves);              // call the towerOfHanoi function with the number of disks, the 'from' rod as A, the 'to' rod as C, the 'auxiliary' rod as B, and the integer reference for moves
    cout << "Total number of moves: " << moves << endl; // print out the total number of moves
    return 0;                                           // exit the function
}