#include<stdio.h>

int main()
{
unsigned long long int i,j,n,m,u,v,a[100000],s[100000],x[100000];
unsigned long long int res;
scanf("%lld",&n);
for(i=0;i<n;i++)
	{
	scanf("%lld",&a[i]);
	if(i==0)
		{
		s[i] = a[i];
		x[i] = a[i]*a[i];
		}
	else
		{
		s[i] = s[i-1]+a[i];
		x[i] = x[i-1] + s[i]*a[i];
		}
	}
scanf("%lld",&m);
for(i=0;i<m;i++)	
	{
	scanf("%lld %lld",&u,&v);
	if(u>0)
		res = x[v] - x[u-1] - (s[u-1]*(s[v] - s[u-1]));
	else
		res = x[v];
	printf("%lld\n",res);
	}
return 0;
}
