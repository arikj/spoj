#include<stdio.h>

int a[120][120];
int left[120],right[120];
int seen[120];


int bpm(int u)
{
int v;

for(v=0;v<120;v++)
	{
	if(!a[u][v] || seen[v])
		continue;

	seen[v]=1;

	if(right[v]==-1 || bpm(right[v]))
		{
		left[u]=v;
		right[v]=u;
		return 1;
		}
	}
return 0;
}


int main()
{
int t,n,i,j,x,y,count;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);

	for(x=0;x<120;x++)
		for(y=0;y<120;y++)
			a[x][y]=0;

	for(j=0;j<n;j++)
		{
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		}

	for(j=0;j<120;j++)
		{
		left[j]=-1;
		right[j]=-1;	
		}	
	count=0;

	for(j=0;j<120;j++)
		{
		for(x=0;x<120;x++)
			seen[x]=0;

		if(bpm(j))
			count++;
		}
	printf("%d\n",count);
	}
return 0;
}
