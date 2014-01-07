#include<stdio.h>

#define max 10000000
bool prime[max];
long long int list[max];
void sieve()
{
long long int i,num,j;
for(i=2;i<max;i++)
	{
	if(prime[i]==0)
		{
		j=2;
		list[i]=i;	
		while((num = j*i) < max)
			{
			if(prime[num]==0)
				list[num]=i;
			prime[num]=1;
			j++;
			}
		}
	}
}

long long int compute(int n)
{
long long int i;
long long int res=0;
for(i=2;i<=n;i++)
	res+=list[i];
return res;
}

int main()
{
long long int t,i,n,j;
long long int res;
sieve();
scanf("%lld",&t);
for(i=0;i<t;i++)
	{
	scanf("%lld",&n);
	res = compute(n);
	printf("%lld\n\n",res);
	}
return 0;
}
