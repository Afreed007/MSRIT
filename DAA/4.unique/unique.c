#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int size,uniq,i,j,f=0;
	int a[1000];
	clock_t start,end;
	double time_taken;
	printf("Enter the size of the list:");
	scanf("%d",&size);
	if(size>1000||size<=0){
		printf("Size must be between 1 and 1000");
		return 1;
	}
	srand(time(NULL));
	for(i=0;i<size;i++)
		a[i]=rand()%100;

	start=clock();

	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size-1;j++)
		{
			if(a[i]==a[j])
			{
				f=1;
				printf("duplicate found: %d\n",a[i]);
				break;
			}
		}
		if(f==1){
			break;
		}
	}
	if(f==1){
		printf("Duplicate is present.\n");
	}else{
		printf("Duplication is not present.\n");
	}

	end=clock();
	time_taken=(double)(end-start)/CLOCKS_PER_SEC;

	printf("Elements in the list are:\n");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);


	printf("\nTime Taken: %.6f seeconds\n",time_taken);
}
