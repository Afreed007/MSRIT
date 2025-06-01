#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int n,i,j,k;
	int a[100][100],b[100][100],c[100][100];
	clock_t start,end;
	double cpu_time_taken;
	printf("Enter the size of N for N*N Martices:");
	scanf("%d",&n);
	if(n>100){
		printf("Maximum allowed size if 100.\n");
		return 1;
	}
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		a[i][j]=rand()%10;
		b[i][j]=rand()%10;
		c[i][j]=0;
		}
	}
	start = clock();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	end =clock();
	cpu_time_taken=((double)(end-start))/CLOCKS_PER_SEC;

	printf("\nMatrix A:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
	printf("\n");
	}

	printf("\nMatrix B:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			printf("%d ",b[i][j]);
		}
	printf("\n");
	}

	printf("\nMatrix C:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			printf("%d ",c[i][j]);
		}
	printf("\n");
	}
	printf("time taken to execute :%f",cpu_time_taken);
	return 0;
	


}
