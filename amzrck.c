#include<stdio.h>

int main()
{
int t,i,n,fib[45];
scanf("%d",&t);
fib[0] = 1;
fib[1] = 2;
for(i=2;i<=43;i++)
	fib[i] = fib[i-1]+fib[i-2];
for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	printf("%d\n\n",fib[n]);
	}
return 0;
}
