// GCD using Euclid Algorithm
#include <stdio.h>
#include <time.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    clock_t start = clock();

    int result = gcd(num1, num2);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The GCD of %d and %d is: %d\n", num1, num2, result);

    printf("Time taken is %f ms\n", time_taken*1000);

    return 0;
}
