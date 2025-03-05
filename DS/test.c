#include <stdio.h>

// Function to merge two sorted queues (arrays)
void merge_sorted_queues(int queue1[], int size1, int queue2[], int size2, int merged_queue[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements while both queues have items
    while (i < size1 && j < size2) {
        if (queue1[i] <= queue2[j]) {
            merged_queue[k++] = queue1[i++];
        } else {
            merged_queue[k++] = queue2[j++];
        }
    }

    // Copy remaining elements of queue1 (if any)
    while (i < size1) {
        merged_queue[k++] = queue1[i++];
    }

    // Copy remaining elements of queue2 (if any)
    while (j < size2) {
        merged_queue[k++] = queue2[j++];
    }
}

int main() {
    int queue1[] = {1, 3, 5, 7};
    int queue2[] = {2, 4, 6, 8, 10};
    
    int size1 = sizeof(queue1) / sizeof(queue1[0]);
    int size2 = sizeof(queue2) / sizeof(queue2[0]);
    
    int merged_queue[size1 + size2]; // Resultant merged queue
    
    // Call merge function
    merge_sorted_queues(queue1, size1, queue2, size2, merged_queue);
    
    // Print the merged queue
    printf("Merged Sorted Queue: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged_queue[i]);
    }
    
    return 0;
}
