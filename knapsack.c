#include<stdio.h>

int max(int a,int b)
{
if(a>b)
	return a;
else
	return b;
}

int main()
{
int i,j,s,n,dp[2001][2],val[2001],size[2001];
scanf("%d %d",&s,&n);

for(i=0;i<n;i++)
	scanf("%d %d",&size[i],&val[i]);

for(i=0;i<n;i++)
	{
	for(j=0;j<=s;j++)
		{
		if(j==0)
			dp[j][1]=0;

		else if(j-size[i]<0)
			dp[j][1]=dp[j][0];

		else
			dp[j][1] = max(dp[j][0], dp[j-size[i]][0]+val[i]);
			
		}

	for(j=0;j<=s;j++)
		dp[j][0] = dp[j][1];
	}
printf("%d\n",dp[s][0]);	
	
return 0;
}
