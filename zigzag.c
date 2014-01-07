#include<stdio.h>
#include<string.h>

int n,i,j,k;
long long int last;

long long int value(char abc)
{
int ch;
if(abc=='U')
	{
	if((i+j)%2==0)
		last = last - 2*i +1;
		
		

	else
		last = last - 2*j +2;
	j--;
	}

else if(abc=='R')
	{
	if((i+j)%2==0)
		last = last+2*j-1;

        else
                last = last+2*i;

	i++;
	}

else if(abc=='D')
	{
	if((i+j)%2==0)
                last=last+2*j;

        else
                last=last+2*i-1;

	j++;
	}
	
else
	{
	if((i+j)%2==0)
                last=last-2*i+2;

        else
                last=last-2*j+1;

	i--;
	}
ch = i+j-n-1;

if(ch>0)
	return last - ch*ch;
else 
	return last;
}

int main()
{
long long int sum=1;
char inst[300001];
int x;
scanf("%d %d",&n,&k);
if(k==0)
	printf("1\n");
else{
scanf("%s",inst);
i=1;j=1;last=1;
 
for(x=0;x<strlen(inst);x++)
	sum+=value(inst[x]);
	

printf("%lld\n",sum);
}
return 0;
}
