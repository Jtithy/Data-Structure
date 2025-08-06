#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // For Random Number Generation
    int randomNumbers[10000];
    int i;

    srand(time(NULL));

    for (i = 1; i <= 10000; i++) {
        randomNumbers[i] = (rand() % 10000) + 1;
    }

    for (i = 1; i <= 10000; i++) {
        printf("randomNumbers[%d] = %d\n", i, randomNumbers[i]);
    }

    // For Linear Search
    printf("Seaching with Linear Search.\n");
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    for(i = 1; i <= 10000; i++)
    {
        if(randomNumbers[i] == target)
        {
            printf("Element found at index: %d\n", i);
            break;
        }
    }
    printf("Element not found in the array.\n");

    // For Sorting
    printf("Sorting the array using Bubble Sort.\n");

    return 0;
}