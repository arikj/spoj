#include<stdio.h>
#include<math.h>

double f(int n,long int a){
     return ( (n*log(n))-n+(.5*(log(2*3.14159*n)) )-(n*(log (a)) ));
}

long int search(long int a)
{
long int l=4,h=a*3,mid;
double x;
while(l<h)
	{

	mid = (l+h)/2;
	x=f(mid,a);
	if(x<0)
		{
		l=mid+1;
		}

	else if(x>0)
		{
		h=mid;
		}

	else
		{
		l=mid+1;
		break;
		}
	}

return l;

}

int main()
{
long int i,j,t,a,res;

scanf("%ld",&t);

for(i=0;i<t;i++)
	{
	scanf("%ld",&a);
	res = search(a);

	printf("%ld\n",res);	
	}
return 0;
}
