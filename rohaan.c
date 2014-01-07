#include<stdio.h>

int main()
{
int sum,s,i,j,k,t,n,r,dist[51][51];

scanf("%d",&t);

for(s=0;s<t;s++)
	{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&dist[i][j]);

	for(k=1;k<=n;k++)
		{
		for(i=1;i<=n;i++)
			{
			for(j=1;j<=n;j++)
				{
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	scanf("%d",&r);
	sum = 0;
	for(k=0;k<r;k++)
		{
		scanf("%d %d",&i,&j);
		sum+= dist[i][j];
		}
	printf("Case #%d: %d\n",s+1,sum);
	}
return 0;
}
