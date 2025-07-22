#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n,i,j,k;
    int a[100][100], b[100][100], c[100][1000];
     clock_t start,end;

     double cpu_time_used;

     printf("Enter size N for n x n matrices: ");
     scanf("%d",&n);

     if(n>100){
        printf("Max allowed size is 100");

        return 1;
     }

     srand(time(NULL));

     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand()%10;
            b[i][j] = rand()%10;
            c[i][j] = 0;
        }
     }

     start = clock();
     for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++)
        {
            c[i][j] += a[i][j] * b[i][j];
        }
     }
     end = clock();

     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

     printf("\nMatrix A:");

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix b:");

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix c:");

     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("\n Time taken tofo multiplication: %f ms\n", cpu_time_used*1000);
}
