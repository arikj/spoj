#include<stdio.h>
#include<math.h>


int main()
{
int i,j,t,n,a[10001],flag;
long long int up,down,res;
scanf("%d",&t);
a[1]=1;
a[2]=1;

for(i=3;i<10001;i++)
	{
	up=1;
	down=1;
	flag=1;
	n=i;
	while(n%2==0)
		{
		if(flag==1)
			{down*=2;flag=0;}

		n=n/2;
		}

	
	for(j=3;j<=sqrt(n);j+=2)
		{
		flag=1;
		while(n%j==0)
			{
			if(flag==1)
				{up*=j-1;down*=j;flag=0;}

			n=n/j;
			}
		}

	if(n>2)
		{
		up*=n-1;
		down*=n;
		}

		a[i]=(i*up)/down;
	}


for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	res=0;
	for(j=1;j<=n;j++)
		res+=a[j];

	res = res*res;

	printf("%lld\n",res);	
	}
return 0;
}
