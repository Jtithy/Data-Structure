#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // For Random Number Generation
    int randomNumbers[10000];
    int i, target;

    srand(time(NULL));

    for (i = 0; i < 10000; i++) {
        randomNumbers[i] = (rand() % 10000) + 1;
    }

    for (i = 0; i < 10000; i++) {
        printf("randomNumbers[%d] = %d\n", i, randomNumbers[i]);
    }

    // For Linear Search
    printf("\nSeaching with Linear Search.\n");

    int found=0,inx=0;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    for(int i = 0; i < 10000; i++)
    {
        if(randomNumbers[i] == target)
        {
            found=1;
            inx=i;
            break;
        }
    }
    if(found){
        printf("%d Element found at index: %d\n", target,inx);
    }
    else{
        printf("%d Element not found in the array.\n",target);
    }



    printf("Sorting the array using Bubble Sort.\n");


    int n=10000;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n -i- 1; j++)
        {
            int temp = 0;
            if (randomNumbers[j] > randomNumbers[j + 1])
            {
                temp = randomNumbers[j + 1];
                randomNumbers[j + 1] = randomNumbers[j];
                randomNumbers[j] = temp;
            }
        }
    }

    // For Binary Search
    int low = 0, high = 10000, found2 = 0,mid, target2;

    printf("Enter the number to search: ");
    scanf("%d", &target2);
    printf("Searching with Binary Search.\n");
    while(low <= high)
    {
        mid = (low + high) / 2;

        if(randomNumbers[mid] == target2)
        {
            found2=1;
            inx=i;
            break;
        }
        else if(randomNumbers[mid] < target2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if(found2){
        printf("%d Element found at index: %d\n", target2,inx);
    }
    else{
        printf("%d Element not found in the array.\n",target2);
    }

    // Find one element and delete
    printf("Enter the number to delete: ");
    int deleteTarget, deleteFound = 0, deleteIndex = -1;
    scanf("%d", &deleteTarget);
    for (int i = 0; i < n; i++) {
        if (randomNumbers[i] == deleteTarget) {
            deleteFound = 1;
            deleteIndex = i;
            break;
        }
    }
    if (deleteFound) {
        printf("%d Element found at index: %d\n", deleteTarget, deleteIndex);

        for (int i = deleteIndex; i < n - 1; i++) {
            randomNumbers[i] = randomNumbers[i + 1];
        }
        n--;
        printf("Deleted successfully.\n");
    } else {
        printf("Not found.\n");
    }

    // Delete three elements sequentially
    printf("Deleting three elements sequentially.\n");
    for (int j = 0; j < 3; j++) {
        printf("Enter the number to delete: ");
        int deleteTargetSeq;
        scanf("%d", &deleteTargetSeq);
        deleteFound = 0;
        deleteIndex = -1;

        for (int i = 0; i < n; i++) {
            if (randomNumbers[i] == deleteTargetSeq) {
                deleteFound = 1;
                deleteIndex = i;
                break;
            }
        }
        if (deleteFound) {
            printf("%d Element found at index: %d\n", deleteTargetSeq, deleteIndex);

            for (int i = deleteIndex; i < n - 1; i++) {
                randomNumbers[i] = randomNumbers[i + 1];
            }
            n--;
            printf("Deleted successfully.\n");
        } else {
            printf("Not found in the array.\n");
        }
    }
    
return 0;
}