#include<stdio.h>

int main()
{
int i,x,j,a[10],count=0,flag;
for(i=3;i<203;i++)
	{
	x = 495*i;
	for(j=0;j<10;j++)
		a[j] = 0;
	flag = 0;
	while(x>0)
		{
		if(a[x%10]==1 || (i<=20 && x%10 == 0))
			{
			flag = 1;
			break;
			}
		a[x%10] = 1;
		x = x/10;		
		}
	if(flag == 0)
		count++;
	}
printf("%d\n",count);
return 0;
}
