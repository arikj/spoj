#include<stdio.h>

int main()
{
int t,i,j,n,k,flag,res,match;
char ch[20000];
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	flag=0;
	res=0;
	scanf("%d %d",&n,&k);
	scanf("%s",ch);
	match=1;
	for(j=1;j<n;j++)
		{
		if(ch[j]==ch[j-1] && match<k)
			match++;
		else
			{
			res++;
			if(match==k)
				flag=1;
			match=1;
			}
		}
	res++;
	if(match==k)
		flag=1;
	if(flag==1)
		printf("%d\n\n",res);
	else
		printf("-1\n\n");
	}
return 0;
}
