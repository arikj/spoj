#include<stdio.h>

int main()
{
int t,i,j,n,arr[100001];
long long int sum,tmp,min;
scanf("%d",&t);

for(j=0;j<t;j++)
	{
	scanf("%d",&n);
	sum=0;
	for(i=0;i<n;i++)
		{
		scanf("%d",&arr[i]);
		sum+=arr[i];
		}
	tmp = sum-arr[0];
	min = tmp;
	for(i=0;i<n-1;i++)
		{
		tmp = tmp + 2*arr[i] - arr[i+1];
		if(min>tmp)
			min=tmp;
		}
	tmp = sum - arr[n-1];
	if(min>tmp)
		min=tmp;
	for(i=n-1;i>0;i--)
		{
		tmp = tmp + 2*arr[i] - arr[i-1];
		if(min>tmp)	
			min=tmp;
		}	
	printf("%lld\n",min);
	}
return 0;
}
