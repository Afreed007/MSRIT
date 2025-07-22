// GCD using prime factorization
#include <stdio.h>
#include <time.h>


int gcd(int a, int b) {
    int gcd = 1;
    int i = 2;

    while (a > 1 && b > 1) {
        if (a % i == 0 && b % i == 0) {
            gcd *= i;
            a /= i;
            b /= i;
        } else if (a % i == 0) {
            a /= i;
        } else if (b % i == 0) {
            b /= i;
        } else {
            i++;
        }
    }
    return gcd;
}

int main() {
    int num1, num2;

    clock_t start = clock();


    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken is %f ms\n", time_taken*1000);

    return 0;
}
