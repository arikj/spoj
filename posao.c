#include<stdio.h>

int main()
{
long long int n,k,ans,rem;
scanf("%lld %lld",&n,&k);
if(k>n)
	k = n;
ans = n*n - (k*(k+1));
rem = ans%k;
if(rem!=0)
	ans = ans/k + 1;
else 
	ans = ans/k;


ans+=2*k;
printf("%lld\n",ans); 
return 0;
}
