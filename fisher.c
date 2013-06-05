#include<stdio.h>

int main()
{
int i,j,n,t,time[50][50],toll[50][50];

scanf("%d %d",&n,&t);

for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&time[i][j]);

for(i=0;i<n;i++)
        for(j=0;j<n;j++)
                scanf("%d",&toll[i][j]);




return 0;
}
