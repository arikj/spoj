#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
int t,i,j,flag,store[5],count;
char avg[100];
long int x,ans;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%s",avg);
	flag=0;
	count=0;
	for(j=0;j<strlen(avg);j++)
		{
		if(avg[j]=='.')
			flag=1;

		else if(flag==1)
			{
			store[count]=avg[j]-'0';
			count++;
			}
		}
	x=0;
	j=0;
	while(j<count)
		{
		x= x+store[j]*pow(10,3-j);
		j++;
		}

	for(j=1;j<10001;j++)
		{
		ans = x*j;
		if(ans%10000==0)
			{printf("%d\n",j);break;}
		}	
	}
return 0;
}
