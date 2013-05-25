#include<stdio.h>
#include<math.h>

int p[1001];

int prime(int n)
{
int i,res;
int h=n*n;
res=h;
if(p[n]!=-1)
	return p[n];
for(i=1;i<=h/2;i++)
	{
	if(h%i==0)
		res+=i;	
	}
for(i=2;i<=sqrt(res);i++)
	{
		if(res%i==0)
			{p[n]=0;
			return 0;}
	}
printf("%d\n",n);
p[n]=1;
return 1;
}

int main()
{
int t,k,j,ans=0,a,b;
float in;
int ini;

scanf("%d",&t);
for(k=2;k<=1000;k++)	
	p[k]=-1;

p[1]=0;
for(k=0;k<t;k++)
	{
	scanf("%d %d",&a,&b);
	ans=0;
	in = sqrt(a);
	ini = sqrt(a);
	if(in!=ini)
		ini+=1;
	for(j=ini;j<=sqrt(b);j++)
		{
		ans+=prime(j);
		}
	if(a<=2)
		ans+=1;
	printf("%d\n",ans);
	}
return 0;
}
