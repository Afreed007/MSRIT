#include<stdio.h>
#include<time.h>
int gcd(int m,int n,int t){
	if(m%t==0 && n%t==0)
			return t;

	else
		gcd(m,n,--t);
}
void main(){
	clock_t end,start;
	int m=60;
	int n=108;
	int t;
	start=clock();
        if(m>n)
                t=n;
        else
                t=m;
	printf("gcd is %d\n",gcd(m,n,t));
	end=clock();
	printf("Time taken is %f second\n",((double)(end-start))/CLOCKS_PER_SEC);
	printf("Time taken is %f milisecond\n",(((double)(end-start))/CLOCKS_PER_SEC)*1000);
	printf("Time taken is %f microsecond\n",(((double)(end-start))/CLOCKS_PER_SEC)*1000000);
}
