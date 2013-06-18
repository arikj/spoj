#include<stdio.h>

int p=10000007;
int store[101][101];
int compute(int n,int r)
{
int ans;
if(n<r)
	return 0;

if(store[n][r]!=0)
	return store[n][r];

ans = (compute(n-1,r-1)+compute(n-1,r))%p;
store[n][r]=ans;
return ans;
}

int main()
{
int n,r;
int i,j,ans;
scanf("%d %d",&n,&r);

if(n<r)
	printf("-1\n");

else if(n==r)
	printf("1\n");
else 
	{
	for(i=0;i<101;i++)
		for(j=0;j<101;j++)
			store[i][j]=0;
	for(i=0;i<101;i++)
		store[i][1]=i;
	ans = compute(n-1,n-r)%p;
	printf("%d\n",ans);	
		
	}
return 0;
}
