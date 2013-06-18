#include<stdio.h>
#include<string.h>

int main()
{
int k,t,i,j,stack[10005],leaf[10005],max,count;
char str[10005];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%s",str);
	for(j=0;j<strlen(str);j++)
		leaf[j]=0;	
	max=0;
	count=1;	
	stack[0]=1;
	for(j=1;j<strlen(str);j++)
		{
		if(str[j]=='n')
			{
			if(count>0)
			stack[count]=stack[count-1]+1;
			leaf[count]=0;
			if(stack[count]>max)
				max = stack[count];
			count++;
			}	

		else if(str[j]=='l')
			{
		
			if(max<stack[count-1]+1)
				max = stack[count-1]+1;
			while(leaf[count-1]==1)
				count--;
			if(count>0)			
			leaf[count-1]=1;
			}

	
		}
	if(str[0]=='l')
		max=1;
	printf("%d\n",max-1);
	}
return 0;
}

