/* Write a function in C called my2DAlloc which allocates a two-dimensional array. Minimize the number of call to malloc
and make sure that memory is accessible by notation arr[i][j]*/
#include <iostream>
#include <stdlib.h>

int** my2DAlloc(int rows, int cols)
{
    // int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int** rowptr = (int**)malloc(data); // allocating a consecutive piece of memory with a size of rows * cols
    if (rowptr == nullptr)
        return nullptr;
    for (int i = 0; i < rows; ++i)
    {
        rowptr[i] = (int*)rowptr + i * cols; // pointer to every row
    }
    return rowptr;
}

int main()
{
    int** arr = my2DAlloc(5, 4);
    arr[4][3] = 12;
    std::cout << arr[4][3] << std::endl;
    return 0;
}