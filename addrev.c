#include<stdio.h>

int main()
{
long long int i,t,a,b,sum,na,nb,ns;

scanf("%lld",&t);

for(i=0;i<t;i++)
{
na=0;nb=0;ns=0;
scanf("%lld %lld",&a,&b);
while(a>0)
	{
	na=na*10;
	na+=a%10;
	a=a/10;	
	}

while(b>0)
        {
        nb=nb*10;
        nb+=b%10;
        b=b/10;
        }

sum = na+nb;

while(sum>0)
        {
        ns=ns*10;
        ns+=sum%10;
        sum=sum/10;
        }

printf("%lld\n",ns);
}
return 0;
}
