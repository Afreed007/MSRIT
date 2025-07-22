#include <stdio.h>
#include <string.h>

int main() {
    char text[] = "Hello world";
    char pattern[] = "world";

    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }

    return 0;
}
