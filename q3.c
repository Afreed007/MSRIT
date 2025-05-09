#include <stdio.h>

int mprimefact[50];
int mtop = 0;
int nprimefact[50];
int ntop = 0;

int isprime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void pushfactorsm(int m) {
    if (isprime(m)) {
        mprimefact[++mtop] = m;
        return;
    }
    for (int i = 2; i <= m; i++) {
        if (m % i == 0 && isprime(i)) {
            mprimefact[++mtop] = i;
            pushfactorsm(m / i);
            break;
        }
    }
}

void pushfactorsn(int n) {
    if (isprime(n)) {
        nprimefact[++ntop] = n;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isprime(i)) {
            nprimefact[++ntop] = i;
            pushfactorsn(n / i);
            break;
        }
    }
}

void gcd() {
    int used[50] = {0}; // To mark used elements in nprimefact
    int result = 1;
    for (int i = 1; i <= mtop; i++) {
        for (int j = 1; j <= ntop; j++) {
            if (mprimefact[i] == nprimefact[j] && !used[j]) {
                result *= mprimefact[i];
                used[j] = 1;
                break;
            }
        }
    }
    printf("\nGCD using prime factors: %d\n", result);
}

int main() {
    int m = 180;
    int n = 30;

    pushfactorsm(m);
    pushfactorsn(n);

    printf("Prime factors of %d: ", m);
    for (int i = 1; i <= mtop; i++) {
        printf("%d ", mprimefact[i]);
    }

    printf("\nPrime factors of %d: ", n);
    for (int i = 1; i <= ntop; i++) {
        printf("%d ", nprimefact[i]);
    }

    gcd(); 
    return 0;
}
