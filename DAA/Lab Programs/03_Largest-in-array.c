#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[1000], size, largest;
    clock_t start, end;

    double cpu_time_used;

    printf("Enter size of array: ");
    scanf("%d", &size);

    if (size > 1000 || size <= 0)
    {
        printf("Size must be between 1 to 1000");
        return 1;
    }
    

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 10) * 18;
    }

    start = clock();
    largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i]>largest)
        {
            largest = arr[i];
        }
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    

    printf("\nLargest numeber in Array is: %d \n",largest);
    printf("\nTime taken to find is: %f ms \n", cpu_time_used/1000);
}
