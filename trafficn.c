#include<stdio.h>

int main()
{
int i,t,n,j,arr[1000000],sum=0,rear,front,count;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	sum = 0;
	rear = -1;
	front = count = 0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d",&arr[j]);

	while(rear<n)
		{
		if(sum<47)
			{
			rear++;
			sum+=arr[rear];
			}
		else if(sum>=47)
			{
			sum-=arr[front];
			front++;
			}
		if(sum == 47)
			count++;
			
		}
	printf("%d\n",count);
	}
return 0;
}
