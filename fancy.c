#include<stdio.h>
#include<string.h>

int power[30];

void powfunc()
{
int i;
power[0]=1;
for(i=1;i<30;i++)
	power[i]=power[i-1]*2;
}

int main()
{
int i,j,t,x,res,tmp;
char num[31];
powfunc();
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res = 1;
	scanf("%s",num);
	x = strlen(num);
	tmp=1;
	for(j=1;j<x;j++)
		{
		if(num[j] == num[j-1])
			tmp++;
		else
			{
			res*=power[tmp-1];
			tmp=1;
			}
		}
	res*=power[tmp-1];
	printf("%d\n\n",res);
	}
return 0;
}
