#include<stdio.h>

int main()
{
int i,n;
long long int w[10000],x;
long long int l=0,r=0;

scanf("%d",&n);

for(i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(i==0)
			{
			l=x;
			printf("%d\n",i);	
			}

		else if(i==1)
			r=x;

		else
			{
				if(l<r)
					{l+=x;
					printf("%d\n",i);}

				else
					r+=x;
			}		
	}
return 0;
}
