#include<stdio.h>

int main()
{
long long int t,n,i,x,j,res,ans;

scanf("%lld",&t);

for(i=0;i<t;i++)
	{
	res=0;
	ans=10000001;
	scanf("%lld",&n);

	for(j=0;j<n;j++)
		{
		scanf("%lld",&x);

		res+=x;

		if(res<0 && res<ans)
			ans=res;
		}

	if(ans<0)
		printf("Scenario #%lld: %lld\n",i+1,-1*ans +1);

	else
		 printf("Scenario #%lld: %d\n",i+1,1);
	}
return 0;
}
