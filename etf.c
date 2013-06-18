#include<stdio.h>
#include<math.h>

int main()
{
int i,t,j,n,x,flag;
long long int up,down,ans;
scanf("%d",&t);
for(i=0;i<t;i++)
	{
	scanf("%d",&n);

	up=1;
	down=1;
	flag=1;
	x=n;
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

		ans=(x*up)/down;

	printf("%lld\n",ans);
	}
return 0;
}
