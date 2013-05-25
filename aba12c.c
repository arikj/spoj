#include<stdio.h>

int n,inf=100000000;
int v[101];
int f[201],g[201],count[201];

int main()
{
int i,j,k,t,p,W;
int res;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&p,&W);
	for(j=1;j<=W;j++)
		{
		scanf("%d",&v[j]);
		}

for(j=1;j<=W;j++)
	{
	f[j]=inf;
	g[j]=0;
	count[j]=0;
	}

f[0]=0;g[0]=1;count[0]=0;
for (k=1;k<=W;k++)
	if(v[k]!=-1)
	{
    for (j=0;j<=W;j++)
        if (g[j]) {
	    if(count[j]+1<=p)	
            	g[j+k]=1;

            if (f[j+k]==0||f[j+k]>f[j]+v[k] && count[j]+1<=p)
                {
		if(f[j+k]==0)
			count[j+k]=1;
	
		else
			count[j+k]=count[j]+1;

		f[j+k]=f[j]+v[k];
		}
        }
	}
	if(!g[W])
	printf("%d\n",-1);
	else
	printf("%d\n",f[W]);
	}
return 0;
}
