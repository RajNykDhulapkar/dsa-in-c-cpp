#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int arr[], int size);
void scanner(int *size, int arr[], int *shift);

/*
Time complexity: O(N)
Auxiliary Space: O(N)
*/
void rotate(int arr[], int size, int shift)
{
    int *temp = (int *)malloc(size * sizeof(int));
    int i;
    for (i = shift; i < size; i++)
        temp[i - shift] = arr[i];

    for (int j = 0; j < shift; j++)
        temp[i - shift + j] = arr[j];

    for (i = 0; i < size; i++)
        arr[i] = temp[i];
}

/*Function to left rotate arr[] of size n by d*/
/*
Time Complexity: O(N * d)
Auxiliary Space: O(1)
*/
void rotate2(int arr[], int n, int d)
{
    int p = 1;
    while (p <= d)
    {
        int last = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = last;
        p++;
    }
}

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

/*
Approach 3 (A Juggling Algorithm): This is an extension of method 2.
Time complexity : O(N)
Auxiliary Space : O(1)
*/
void leftRotate(int arr[], int d, int n)
{
    int i, j, k, temp;
    d = d % n; // if d >= n
    int gcd = GCD(d, n);
    for (i = 0; i < gcd; i++)
    {
        temp = arr[i];
        j = i;
        while (true)
        {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
        printArray(arr, n);
    }
}
// TODO Block swap algorithm for array rotation
// TODO Reversal algorithm for array rotation

int main(int argc, char const *argv[])
{
    int n = 0;
    int arr[20];
    int shift;
    scanner(&n, arr, &shift);
    printArray(arr, n);
    rotate(arr, n, shift);
    printArray(arr, n);
    rotate2(arr, n, shift);
    printArray(arr, n);

    printf("initial arr : ");
    printArray(arr, n);
    leftRotate(arr, shift, n);
    printf("final arr : ");
    printArray(arr, n);

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    printf("{ ");
    for (i = 0; i < size - 1; i++)
    {
        printf(" %d,", arr[i]);
    }
    printf(" %d }\n", arr[i]);
}

void scanner(int *size, int arr[], int *shift)
{
    printf("Enter the size of array : ");
    scanf(" %d", size);
    printf("Enter shift : ");
    scanf(" %d", shift);
    printf("Enter the array : ");
    for (int i = 0; i < *size; i++)
        scanf(" %d", &arr[i]);
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 1 2 3 4 5 6 7 8 9 10 11 12