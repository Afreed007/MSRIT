// Linear Search Algorithm and Time taken to Search an element
#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int main() {
    int n, key, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > 10000 || n <= 0)
    {
        printf("\nSize must be between 1 to 1000\n");
        return 1;
    }

    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 10) * (rand() % 180);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();
    for (i = 0; i < n; i++) {
        if (arr[i] == key) break;
    }
    clock_t end = clock();

    if (i < n) printf("Element found at index %d\n", i);
    else printf("Element not found\n");

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
