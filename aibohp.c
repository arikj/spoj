#include<stdio.h>
#include<string.h>

int max(int a,int b)
	{
	if(a>b)
		return a;

	else 
		return b;
	}

int main()
{
int n,i,j,k,t;
char str[5005],rev_str[5005];
int store[5001][2];
scanf("%d",&t);

for(k=0;k<t;k++)
{
scanf("%s",str);
n=strlen(str);
for(i=0;i<n;i++)
	rev_str[i]=str[n-i-1];
	

for(i=0;i<=n;i++)
	{
	for(j=0;j<=n;j++)
		{
		if(i==0 || j==0)
			store[j][1]=0;

		else if(str[i-1]==rev_str[j-1])
			store[j][1] = store[j-1][0]+1;

		else
			store[j][1] = max(store[j][0],store[j-1][1]);
		}

	for(j=0;j<=n;j++)
		store[j][0]=store[j][1];
	}

printf("%d\n",n-store[n][0]);
}
return 0;
}
