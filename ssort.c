#include<stdio.h>

int main()
{
int x,y,i,n,arr[1001],len,count,min,index, glb,sum,tot,num=1;
int visited[1001],sort[1001],pos[1001];
scanf("%d",&n);

while(n!=0)
	{
	for(i=0;i<1001;i++)
		{
		visited[i] = 0;
		sort[i] = 0;
		}
	glb = 1001;
	sum = 0;
	tot = 0;
	for(i=1;i<=n;i++)
		{
		scanf("%d",&arr[i]);
		if(arr[i] < glb)
			glb = arr[i];
		sort[arr[i]] = 1;
		}
	for(i=1;i<1001;i++)
		sort[i] = sort[i] + sort[i-1];

	for(i=1;i<=n;i++)
		{
		pos[i] = sort[arr[i]];
		}
	count = 0;
	index = 1;
	len = 0;
	min = index;
	while(count<n)	
		{
		if(visited[index]==0)
			{
			count++;
			len++;
			visited[index] = 1;
			sum+=arr[index];
			index = pos[index];
			if(arr[min]>arr[index])
				min = index;
			}

		else
			{
			if(len>1)
				{
				x = sum+(len-2)*arr[min];
				y = sum + arr[min] + glb + len*glb;
				if(x>y)
					tot+=y;
				else
					tot+=x;
				}
			for(i=1;i<=n;i++)
				{
				if(visited[i] == 0)
					{
					index = i;
					len = 0;
					sum = 0;
					min = index;
					break;
					}
				}	
			}
		}
	if(len>1)
	{
	x = sum+(len-2)*arr[min];
 	y = sum + arr[min] + glb + len*glb;
        if(x>y)
		tot+=y;
        else
	        tot+=x;
	}
	printf("Case %d: %d\n\n",num,tot);
	scanf("%d",&n);
	num++;
	}
return 0;
}
