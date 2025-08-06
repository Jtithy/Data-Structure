#include<stdio.h>

int main()

{
    char arr[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'};
    int n = 20;
    printf("Sorting the array in descending order using Bubble Sort.\n");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            char temp = 0;
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array in descending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
    return 0;
}