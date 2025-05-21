#include <stdio.h>
#include<time.h>
int mprimefact[50];
int mtop = 0;
int nprimefact[50];
int ntop = 0;

int isprime(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            break;
        }
    }
    return count == 0 && n > 1;
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
    int result = 1;
    for (int i = 1; i <= mtop; i++) {
        for (int j = 1; j <= ntop; j++) {
            if (mprimefact[i] == nprimefact[j]) {
                result *= mprimefact[i];
                nprimefact[j] = 0;
                break;
            }
        }
    }
    printf("GCD is: %d\n", result);
}

int main() {
    int m = 60;
    int n = 108;
    clock_t end,start;
    double computedtime;
    start=clock();
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
    printf("\n");
    gcd();
    end=clock();
    computedtime=((double)(end-start)/CLOCKS_PER_SEC);
    printf("time taken is %f second\n",computedtime);
    printf("time taken is %f milisecond\n",computedtime*1000);
    printf("time taken is %f microsecond\n",computedtime*1000000);
    return 0;
}
