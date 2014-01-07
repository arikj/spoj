#include<stdio.h>
#include<algorithm>

using namespace std;

int cost[100][100];
bool row[100];
int n,m,c;

int max(int a,int b)
{
if(a>b)
	return a;
else
	return b;
}

int minimum()
{
int min=1000000000,index,i,j,st;
for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
		{
		if(min>cost[i][j])
			{
			min = cost[i][j];
			index = j;
			st = i;
			}
		}
	}
if(row[index]==0)
	{
	row[index]=1;
	for(i=0;i<n;i++)
		cost[i][index]=max(c+min,cost[i][index]);
	}
else
	{
	for(i=0;i<n;i++)
		cost[i][index]=1000000001;
	}

for(i=0;i<m;i++)
	cost[st][i] = 1000000001;

return min;
}

int main()
{
int x,t,i,j,k;
int res;
scanf("%d",&t);
for(x=0;x<t;x++)
	{
	res=0;
	scanf("%d %d %d %d",&n,&m,&k,&c);
	for(i=0;i<m;i++)
		row[i] = 0;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&cost[i][j]);

	while(k>0)
		{
		res = minimum();
		k--;
		}
	printf("%d\n",res);
	}
return 0;
}
