#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10000], size;
    clock_t start, end;

    double cpu_time_used;

    printf("\nEnter size of array: ");
    scanf("%d", &size);

    if (size > 10000 || size <= 0)
    {
        printf("\nSize must be between 1 to 1000\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 10) * (rand() % 180);
    }
    int flag = 1;
    start = clock();
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 0;
            }
        }
    }

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }

    if (flag == 1)
        printf("\nArray is unique\n");
    else
        printf("\nArray is not unique \n");
    printf("\nTime taken to find is: %f ms \n", cpu_time_used / 1000);
}
