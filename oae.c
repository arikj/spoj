#include<stdio.h>

long long int rem = 314159;

long long int compute(long long int a,long long int n)
{
if(n==2)
	return a*a;

if(n==1)
	return a;

long long int x=compute(a,n/2);

if(n%2==0)
	return (x*x)%rem;

else
	return (((x*x)%rem)*(a))%rem;
}


int main()
{
long long int t,n,i,res1,res2;

scanf("%lld",&t);

for(i=0;i<t;i++)
	{
	scanf("%lld",&n);

	res1=compute(10,n-1);
	res2=compute(8,n-1);
	res1=(5*res1)%rem;
	res2=(4*res2)%rem;
        res1=((res1+res2)%rem);
	printf("%lld\n",res1);
	}

return 0;
}


