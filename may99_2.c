#include<stdio.h>

int main()
{
int t,i,count,rem,j;
long long int n;
char str[50];
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count=0;
	scanf("%lld",&n);
	while(n>0)
		{
		rem = n%5;
		if(rem==0)
		n=(n/5)-1;
		else 	

		n = (n/5);
		switch(rem)
			{
			case 0:str[count]='u';
				break;
		
			case 1:str[count]='m';
                                break;


			case 2:str[count]='a';
                                break;


			case 3:str[count]='n';
                                break;


			case 4:str[count]='k';
                                break;

			}
		count++;
		}

	for(j=count-1;j>=0;j--)
	printf("%c",str[j]);
	printf("\n");
	}
return 0;
}
