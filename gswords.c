#include<stdio.h>
#include<math.h>

unsigned long long int rem=1000000007;

unsigned long long int compute(unsigned long long int n)
{

if(n==0)
	return 1;
if(n==2)
        return 2*2;

if(n==1)
        return 2;

unsigned long long int x=compute(n/2);

if(n%2==0)
        return (x*x)%rem;

else
        return (((x*x)%rem)*(2))%rem;
}


int main()
{
unsigned long long i,n,ans;
int flag=1;
scanf("%llu",&n);
//printf("%llu",n*n);
if(n==1)
	printf("2\n");
else if(n==2)
	printf("3\n");
else{
for(i=2;i<=sqrt(n);i++)
	{
	if(n%i==0)
		{
		flag=0;
		break;
		}
	}

if(flag==0)
	{ans=compute(n);}

else
	{ans=compute(n-1);}

printf("%llu\n",ans);
}
return 0;
}
