#include<stdio.h>

int main()
{
long long int i,t,n,r,temp;
scanf("%lld",&t);

for(i=0;i<t;i++)
{
scanf("%lld",&n);
temp=5;
r=0;
while(temp<=n)
{
r+=n/temp;
temp*=5;
}

printf("%lld\n",r);
}
return 0;
}
