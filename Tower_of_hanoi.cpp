#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int &moves)
{
    if (n == 1)
    {
        moves++;
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, moves);
    moves++;
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, moves);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    int moves = 0;
    towerOfHanoi(n, 'A', 'C', 'B', moves);
    cout << "Total number of moves: " << moves << endl;
    return 0;
}