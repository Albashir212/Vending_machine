#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b);
void shuffleRecursive(int array[], int start, int end);
void shuffleIterative(int array[], int length);
void printArray(int array[], int length);

int main()
{
    // Initialize the random seed
    srand(time(NULL));

    // initiaize an array of integers
    int array[] = { 10, 5, 8, 3, 1, 9, 2, 7, 4, 6 };

    // Getting the size of the array
    int n = sizeof(array) / sizeof(array[0]);

    // Print the original array before reshuffling
    printf("Original array: \n");
    printArray(array, n);

    // Shuffle the array using the recursive function
    shuffleRecursive(array, 0, n - 1);

    // Print the shuffled recursive array
    printf("\nShuffled array: \n");
    printArray(array, n);

    // Shuffle the array using the iterative function
    shuffleIterative(array, n);

    // Print the shuffled iterative array
    printf("\nIterative array: \n");
    printArray(array, n);

    return 0;
}

// A utility function to print an array of size n
void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// A temporary function to swap two elements by taking advantage of pointers
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* A recursive function to shuffle an array of integers such that the odd values are in the first part and 
the even values are in the second part */

void shuffleRecursive(int array[], int start, int end)
{
    // Base case: if the starting index is greater than or equal to the ending index, return nothing
    if (start >= end)
    {
        return;
    }   
    
    else 
    {
        if (array[start] % 2 == 1) 
        { // getting the odd values
        start = start + 1;
        shuffleRecursive(array, start, end);
        }
    else { // getting even values
      // swap array[start] and array[end]
      int temp = array[start];
      array[start] = array[end];
      array[end] = temp;
      end = end - 1;
      shuffleRecursive(array, start, end);
    }
  }
}

/* An iterative function to shuffle an array of integers such that the odd values are in the first part and
the even values are in the second part */

void shuffleIterative(int array[], int length)
{
    // Initialize the end index to be the last index of the array
    int end = length - 1;

    // Loop from start = 0 to end
    int start = 0;
    while (start < end) 
    {// Move the start index to the right until an even number is found
        while (array[start] % 2 != 0 && start < end)
            start++;

        // Move the end index to the left until an odd number is found
        while (array[end] % 2 == 0 && start < end)
            end--;

        // Swap the elements at start and end
        swap(&array[start], &array[end]);
    }
}

