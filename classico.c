#include<stdio.h>

int max(int arr[],int left,int right)
{
int i,max = left;
for(i=left+1;i<=right;i++)
	{
	if(arr[max]<arr[i])
		max = i;
	}
return max;
}

int main()
{
int index,i,j,t,n,arr[2000],count,left,right;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	count =0 ;
	for(j=0;j<n;j++)
		scanf("%d",&arr[j]);
	printf("Case %d: ",i+1);
	if(n<11)
		printf("go home!\n");
	else
		{
		left=0;
		right=n-11;
		while(count<10)
			{
			index = max(arr,left,right);
			printf("%d ",arr[index]);
			left = index+1;
			right++;
			count++;
			}
		index = max(arr,left,right);
		printf("%d\n",arr[index]);	
		}
	}
return 0;
}
