#include<stdio.h>


int main()
{
long long int i,j,t,n,arr[100000],sum[100000],min[100000][2],max,count;
scanf("%lld",&t);
for(i=0;i<t;i++)
	{
	scanf("%lld",&n);
	scanf("%lld",&arr[0]);
	sum[0] = arr[0];
	min[0][0] = 0;
	min[0][1] = 1;
	for(j=1;j<n;j++)
		{
		scanf("%lld",&arr[j]);
		sum[j] = sum[j-1]+arr[j];
		if(min[j-1][0]<sum[j-1])
			{
			min[j][0] = min[j-1][0];
			min[j][1] = min[j-1][1];
			}
		else if(sum[j-1]<min[j-1][0])
			{
			min[j][0] = sum[j-1];
			min[j][1] = 1;
			}
		else
			{
			min[j][0] = min[j-1][0];
			min[j][1] = min[j-1][1]+1;
			}
		}
	max = sum[0];
	for(j=1;j<n;j++)
		{
		if(max < sum[j]-min[j][0])
			max = sum[j] - min[j][0];	
		}
	if(sum[0] == max)
		count = 1;
	else
		count = 0;
	for(j=1;j<n;j++)
		{
		if(max == sum[j] - min[j][0])
			count+=min[j][1];
		}
	printf("%lld %lld\n",max,count);
	}
return 0;
}
