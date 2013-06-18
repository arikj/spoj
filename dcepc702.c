#include<stdio.h>

int main()
{
int count,j,t,i;
long long int res,n,a1,r,a2,b1,b2,c1,c2,sum,a,b,c,store[10][2];


scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res=0;
	count=0;
	scanf("%lld",&n);

	scanf("%lld %lld",&a1,&a2);
	scanf("%lld %lld",&b1,&b2);
	scanf("%lld %lld",&c1,&c2);

	sum = n-(a1+b1+c1);	

	a=a2-a1+1;
	b=b2-b1+1;
	c=c2-c1+1;


	if(n>a2+b2+c2 || n<a1+b1+c1)
		{
		res=0;
		count=0;
		}
	

	else {
	store[0][0]=0;store[0][1]=1;
        store[1][0]=a;store[1][1]=-1;
        store[2][0]=b;store[2][1]=-1;
        store[3][0]=c;store[3][1]=-1;
        store[4][0]=a+b;store[4][1]=1;
        store[5][0]=b+c;store[5][1]=1;
        store[6][0]=a+c;store[6][1]=1;
        store[7][0]=a+b+c;store[7][1]=-1;
	count=8;
	}	

	for(j=0;j<count;j++)
		{
		r = sum - store[j][0];
		if(r>=0)
			{
			 res=(res+(store[j][1]*((r+1)*(r+2))/2)); 

			}	
		}

	res = res%1000000007;
	
	printf("%lld\n",res);

	}

return 0;

}
