#include<stdio.h>
#include<math.h>

long long int prime[30];
int count;


void evaluate(int n)
{
count=0;
int flag=1,j;
while(n%2==0)
	{	
	if(flag==1)
		{prime[count]=2;count++;flag=0;}
	n=n/2;
	}

	
	for(j=3;j<=sqrt(n);j+=2)
		{
		flag=1;
		while(n%j==0)
			{
			if(flag==1)
				{prime[count]=j;count++;flag=0;}

			n=n/j;
			}
		}

	if(n>2)
		{
		prime[count]=n;count++;
		}
}

int main()
{
int t,n,i,j;
long long int a,b;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count=0;
	scanf("%lld %lld %d",&a,&b,&n);

	evaluate(n);
	
		
	}

return 0; 
}
