#include<stdio.h>

int main()
{
int t,n,i,j;
double arr[100001];

arr[1] = 1;
for(i=2;i<=100000;i++)
	arr[i] = arr[i-1] + 1.0/i;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	printf("%.14lf\n",arr[n]);
	}
return 0;
}
