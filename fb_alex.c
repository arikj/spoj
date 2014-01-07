#include<stdio.h>

int main()
{
int n,m;
scanf("%d %d",&n,&m);


if(n==2 && m==1)
	printf("2\n");

else
{
if(n%2==0)
	printf("%d\n",2*n);

else
	{
	if(m%2==0)
		printf("%d\n",2*(n+m-2));

	else
		printf("%d\n",n*m);
	}
}
return 0;
}
