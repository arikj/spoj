#include<stdio.h>

int main()
{
int t,n,i,j,count;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count = 1;
	scanf("%d",&n);
	for(j=1;j<n;j++)
		{
		if((n-j)%(j+1)==0)
			count++;		
		}
	printf("%d\n",count);
	}
return 0;
}
