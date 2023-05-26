#include <iostream>
#include <time.h>
using namespace std;
const int SIZE = 100;

void randomly_populate_array(int input_array[], int size_of_array);
void display_array(int input_array[], int size_of_array);
void bubble_sort(int input_array[], int size_of_array);
void insertion_sort(int input_array[], int size_of_array);
void swap_array(int input_array[], int a, int b);

int main()
{
    int array[SIZE];
    randomly_populate_array(array, SIZE);
    display_array(array, SIZE);
    bubble_sort(array, SIZE);
    // insertion_sort(array,SIZE);
    display_array(array, SIZE);

    return 0;
}

void randomly_populate_array(int input_array[], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        srand(i * clock());
        int r = rand() % 1000;

        input_array[i] = r;
    }
}
void display_array(int input_array[], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        cout << input_array[i] << " ";
    }
    cout << "\n \n";
}

void bubble_sort(int input_array[], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        for (int j = 0; j < size_of_array - 1; j++)
        {
            if (input_array[j] > input_array[j + 1])
            {
                swap_array(input_array, j, j + 1);
            }
        }
    }
}

void insertion_sort(int input_array[], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        for (int j = i + 1; j < size_of_array; j++)
        {
            if (input_array[j] < input_array[i])
            {
                swap_array(input_array, i, j);
            }
        }
    }
}
void swap_array(int input_array[], int a, int b)
{
    int temp;
    temp = input_array[a];
    input_array[a] = input_array[b];
    input_array[b] = temp;
}