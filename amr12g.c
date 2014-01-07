#include<stdio.h>

int state[50];
int n,m;


void min()
{
int i;
int min=0;
for(i=1;i<n;i++)
	{
	if(state[min]>state[i])
		min = i;
	}
state[min]=m-state[min];
}


int main()
{
int t,i,j,k,x,res;
char ch[51];
scanf("%d",&t);

for(x=0;x<t;x++)
	{
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++)
		state[i]=0;
	for(i=0;i<n;i++)
		{
		scanf("%s",ch);
		for(j=0;j<m;j++)
			{
			if(ch[j]=='*')
				state[i]++;
			}
		}
	while(k>0)
		{
		min();
		k--;
		}
	res=0;
	for(i=0;i<n;i++)
		res+=state[i];
	printf("%d\n\n",res);
	}
return 0;
}
