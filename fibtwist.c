#include<stdio.h>
#include<math.h>


long long int compute(double a,long long int n,long long int rem)
{
if(n==2)
        return a*a;

if(n==1)
        return a;

long long int x=compute(a,n/2,rem);

if(n%2==0)
        return (x*x)%rem;

else
        return (((x*x)%rem)*(a))%rem;
}


int main()
{

int i,t;
long long int n,res1,res2,res3,m;
scanf("%d",&t);

for(i=0;i<t;i++)
{
scanf("%lld %lld",&n,&m);

res1 =(2.3416*pow(1.618,n));
res2= -1*0.3416*pow(-.618,n)-n-2;
res3 = 2.3416*compute(1.618,n,m);
if(n==0)
	printf("0\n");

else
	printf("%lld %lld\n",res1,res3);
}

return 0;	
}
