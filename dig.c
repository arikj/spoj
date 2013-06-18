#include<stdio.h>

int main()
{
long long int t,i,n;
long long int p = 1000000007;
long long int ans;
scanf("%lld",&t);
for(i=0;i<t;i++)
	{
	scanf("%lld",&n);
	ans = (((((n*(n-1))%p)*(((n-2)*(n-3))%p))%p)*41666667)%p;

	printf("%lld\n",ans); 
	}
return 0;
}
