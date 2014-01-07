#include<stdio.h>

long long int gcd(long long int m,long long int n)
{

long long int rem; 
while(n!=0) 
	{ rem=m%n; m=n; n=rem; }
return(m);
}


int main()
{
int t,i;
long long int num;
long long int max,j;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%lld",&num);
	if(num==1)
		printf("0\n");
	else{
	max=num/2;
	for(j=max;j>=1;j--)
		{
		if(gcd(j,num)==1)
			{
			printf("%lld\n",j);
			break;
			}
		}
	}
	}
return 0;
}
