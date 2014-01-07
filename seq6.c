#include<stdio.h>
#include<math.h>


int main()
{
int i,n,res;
float x;
scanf("%d",&n);

while(n!=0)
	{
	res = 0;
	n = 2*n;
	x= sqrt(n);
	for(i=1;i<x;i++)
		{
		if(n%i == 0)
			res+= i%2 + (n/i)%2;
				
		}
	if(n%i == 0 && i*i == n)
		res+= i%2;
	printf("%d\n",2*res);	
	scanf("%d",&n);
	}
return 0;
}
