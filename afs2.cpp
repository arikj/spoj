#include<stdio.h>

int main()
{
long long int t,n,i,j,res;
scanf("%lld",&t);
for(i=0;i<t;i++)
	{
	scanf("%lld",&n);
	if(n==0)
		printf("0\n\n");
	else{
	res=n-1;
	for(i=2;i<=n/2;i++)
		res+= (n/i -1)*i;
	printf("%lld\n\n",res);	}
	}
return 0;
}
