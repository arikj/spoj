#include<stdio.h>

int main()
{
int i,j,k,t,n,m,peaks[1001],dp[1001],max;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&m);

	for(j=0;j<n;j++)
		{
		scanf("%d",&peaks[j]);
		dp[j]=0;
		}

	for(j=0;j<n;j++)
		{
		dp[j]=1;
		for(k=0;k<j;k++)
			{
			if((peaks[k]>peaks[j] || k==m) && dp[j]<dp[k]+1)
				dp[j]=dp[k]+1;
				
			}
		}

	max=dp[0];
	for(j=1;j<n;j++)
		{
		if(max<dp[j])
			max=dp[j];
		}

	printf("%d\n",max);
	}
return 0;
}  
