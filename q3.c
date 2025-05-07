#include<stdio.h>
int mprimefact[50];
int mtop=0;
int nprimefact[50];
int ntop=0;
int isprime(int n){
	int count =0;
	for(int i=2;i<n;i++){
		if(n%i==0)
			count++;
	}
	if(count>0)
		return 0;
	else
		return 1;
}
void pushfactorsm(int m){
	if(isprime(m)){
		mprimefact[++mtop]=m;
		return;
		}
	for(int i=2;i<=m;i++)
	{
		if(m%i==0 && isprime(i)){
			mprimefact[++mtop]=i;
			pushfactorsm(m/i);
			break;
		}
	}
}
void pushfactorsn(int n){
	if(isprime(n)){
		nprimefact[++ntop]=n;
		return;
		}
	for(int i=2;i<=n;i++)
	{
		if(n%i==0 && isprime(i)){
			nprimefact[++ntop]=i;
			pushfactorsn(n/i);
			break;
		}
	}
}
void gcd(){
	int result=1;
	for(int i=1;i<mtop;i++){
		for(int j=1;j<ntop;j++){
			if(mprimefact[i]==nprimefact[j]){
				result=result*mprimefact[m];
				mprimefact[i];
			}

	}
	}
}

void main(){
	int m=30;
	int n=180;
	pushfactorsm(m);
	pushfactorsn(n);
	printf("factors of 30 :");
	for(int i=1;i<=mtop;i++)
	{
		printf("%d \t",mprimefact[i]);
	}

	printf("\nfactors of 180 :");
	for(int i=1;i<=ntop;i++)
	{
		printf("%d \t",nprimefact[i]);
	}
	printf("\n");
}
