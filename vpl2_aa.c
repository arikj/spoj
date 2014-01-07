#include<stdio.h>
#include<math.h>

int main()
{
double p0,p1,t,p;
int i,n;
double dec;
scanf("%d",&n);

for(i=0;i<n;i++)
	{
	scanf("%lf %lf %lf %lf",&p0,&p1,&t,&p);
 	dec=(log(p/p0)/log(p1/p0))*t;
	printf("Scenario #%d: %.2lf\n",i+1,dec);
	}
return 0;
}
