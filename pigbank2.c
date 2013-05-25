#include<stdio.h>

int n,tw,inf=100000000;
int v[501],w[501];
int f[20001],g[20001];

int main()
{
int i,j,k,t,e,fo;
int res;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&e,&fo);
	tw=fo-e;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%d %d",&v[j],&w[j]);
		}

for(j=1;j<=tw;j++)
	{
	f[j]=inf;
	g[j]=0;
	}

f[0]=0;g[0]=1;
for (k=0;k<n;k++)
    for (j=0;j<tw;j++)
        if (g[j]) {
            g[j+w[k]]=1;
            if (f[j+w[k]]==0||f[j+w[k]]>f[j]+v[k])
                f[j+w[k]]=f[j]+v[k];
        }

	if(!g[tw])
	printf("This is impossible.\n");
	else
	printf("The minimum amount of money in the piggy-bank is %d.\n",f[tw]);
	}
return 0;
}
