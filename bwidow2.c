#include<stdio.h>

int main()
{
int t,n,i,j,k,in[1001],out[1001];
int count;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d %d",&in[j],&out[j]);
	for(j=0;j<n;j++)
		{
		count=0;
		for(k=0;k<n;k++)
			{
			if(k!=j && in[j]>out[k])
				count++;
				
			}
		if(count==n-1)
			break;
		}
	if(count==n-1)
		printf("%d\n",j+1);
	else
		printf("-1\n");
	}
return 0;
}
