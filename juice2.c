#include<stdio.h>

long long int time[1001][2];

void sort(int n)
{
int i,j,min;
long long int temp;
for(i=0;i<n-1;i++)
	{
	min=i;
	for(j=i+1;j<n;j++)
		{
		if(time[min][0]>time[j][0])
			min=j;
		}

	if(min!=i)
		{
		temp = time[min][0];
		time[min][0] = time[i][0];
		time[i][0] = temp;

		temp = time[min][1];
                time[min][1] = time[i][1];
                time[i][1] = temp;

		}
	}	
}
int main()
{
int i,j,k,t,n,dp[1001],count;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);

	for(j=0;j<n;j++)
		{
		scanf("%lld %lld",&time[j][0],&time[j][1]);
		dp[j]=0;
		}

	sort(n);

	for(j=1;j<n;j++)
		{
		count = 0;
		k = j-1;
		dp[j]=dp[j-1];
		while(k>=0)
			{
			if(time[k][0]!=time[k+1][0])
				{
				if(dp[j]<count+dp[k]+1 && count>1)
					dp[j] = count+dp[k]+1;
				}

			if(time[k][1]>=time[j][0])
				count++;
			k--;
			}

		if(dp[j]<count+1 && count>1)
			dp[j]=count+1;
		}
	printf("Case #%d: %d\n",i+1,dp[n-1]);
	}
return 0;
}
