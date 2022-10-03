#include <stdio.h>

void printArray(int arr[], int size)
{
    printf("{ ");
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            printf(" %d,", arr[i]);
        else
            printf(" %d", arr[i]);
    }
    printf("}\n");
}

int main(int argc, char const *argv[])
{
    int arr_1[3];
    printArray(arr_1, 3);

    int arr_2[3] = {1, 2, 3};
    printArray(arr_2, 3);

    int arr_3[3] = {}; // array init with 0
    printArray(arr_3, 3);

    int arr_4[3] = {1}; // {1 0 0 }
    printArray(arr_4, 3);

    int arr_5[3] = {[0 ... 1] = 5};
    printArray(arr_5, 3);

    int arr_6[] = {[0 ... 1] = 3};
    printArray(arr_6, 3);

    int *arr_7;
    printArray(arr_7, 3);

    return 0;
}
