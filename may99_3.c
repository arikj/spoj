#include<stdio.h>


int gcd(int a,int b)
{
    if(b>a)
    return gcd(b,a);
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int main()
{
int t,i,x,y,z,a;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d %d",&x,&y,&z);

	if(x<z && y<z)
		printf("NO\n");

	else
		{
		a=gcd(x,y);
		if(z%a==0)
			printf("YES\n");

		else
			printf("NO\n");	
		}
	}
return 0;
}
