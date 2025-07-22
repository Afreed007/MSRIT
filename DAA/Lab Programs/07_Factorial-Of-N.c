#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long factorial_non_recursive(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main() {
    int n;

    printf("Enter a value for n: ");
    scanf("%d", &n);

    clock_t start, end;
    double time1, time2;

    start = clock();
    long long res = factorial_recursive(n);
    end = clock();
    time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    long long res1 = factorial_non_recursive(n);
    end = clock();
    time2 = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nn = %d\n", n);
    printf("Recursive factorial: %lld\n", res);
    printf("Recursive time: %.6f seconds\n", time1);

    printf("Non-recursive factorial: %lld\n", res1);
    printf("Non-recursive time: %.6f seconds\n", time2);

    return 0;
}
