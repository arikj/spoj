#include<stdio.h>

int mincost[501][10001]; 
int n,tw,inf=100000000;
int v[501],w[501];

int min(int a,int b)
{
if(a<b)
	return a;
else
	return b;
}

int min_cost(int i, int W)
{

//printf("%d %d\n",i,W);
if(i>=n || W<0)
	return inf;

if(W==0)
	return 0;

int a,b;


if(mincost[i+1][W]!=-1)
	a = mincost[i+1][W];
else		
 	{
	a = min_cost(i+1,W);
		
	mincost[i+1][W] = a;}

if(W-w[i]>=0) 
	{
	if(mincost[i][W-w[i]]!=-1)
		b = mincost[i][W-w[i]];
	else
	{
	b = min_cost(i,W-w[i])+v[i];
	mincost[i][W-w[i]]=b;}
}

else
	b = inf;
//printf("%d\n",min(a,b));
return min(a,b); 

}

int main()
{
int i,j,k,t,e,f;
int res;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&e,&f);
	tw=f-e;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%d %d",&v[j],&w[j]);
		}

	for(j=0;j<501;j++)
		for(k=0;k<10001;k++)
			mincost[j][k]=-1;

	res = min_cost(0,tw);
	if(res==inf)
	printf("This is impossible.\n");
	else
	printf("The minimum amount of money in the piggy-bank is %d.\n",res);
	}
return 0;
}
