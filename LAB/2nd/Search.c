#include<stdio.h>

int main()

{
    int array[1000], i;

    for(i = 0; i < 1000; i++)
    {
        array[i] = i + 1; 
    }

    for(i = 0 ; i < 1000; i++)
    {
        printf("%d\n", array[i]);
    }

    int low = 0, high = 1000, mid, target;

    printf("Enter the number to search: ");
    scanf("%d", &target);
    printf("Searching with Binary Search.\n");
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(array[mid] == target)
        {
            printf("Element found at index: %d\n", mid);
            return 0;
        }
        else if(array[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    printf("Element not found in the array.\n");

    printf("Seaching with Linear Search.\n");

    for(i = 0; i < 1000; i++)
    {
        if(array[i] == target)
        {
            printf("Element found at index: %d\n", i);
            return 0;
        }
    }
    printf("Element not found in the array.\n");
    
    return 0;
}