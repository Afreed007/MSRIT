#include<stdio.h>
#include<time.h>
int gcd(int m,int n){
	if(n==0)
		return m;
	else
		gcd(n,(m%n));
}


int main() {
    clock_t start, end;
    double cpu_time_used;
    int m = 60;
    int n = 108;

    start = clock();

    printf("GCD of %d and %d is %d\n", m, n, gcd(m, n));

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to compute GCD: %f seconds\n", cpu_time_used);
    printf("Time Taken to compute GCD :%f miliseconds\n", cpu_time_used*1000);
    printf("Time Taken to compute GCD :%f microsecond\n",cpu_time_used*1000000);
    return 0;
}
