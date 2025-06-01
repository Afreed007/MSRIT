#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int a[1000],size,largest,i;
	clock_t start,end;
	double cpu_time_taken;
	printf("Enter the size of the array:");
	scanf("%d",&size);
	if(size>1000||size<=0){
		printf("siez must be between 1 and 999.\n");
		return 1;
	}
	srand(time(NULL));
	for(i=0;i<size;i++)
	{
		a[i]=rand()%100;
	}
	start = clock();
	largest=a[0];
	for(i=1;i<size;i++)
	{
		if(a[i]>=largest){
			largest=a[i];
		}
	}
	end =clock();
	cpu_time_taken=((double)(end-start))/CLOCKS_PER_SEC;

	printf("matrix:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nlarest number among the array is %d",largest);

	printf("\ntime taken to execute :%f",cpu_time_taken);
	return 0;
	


}
