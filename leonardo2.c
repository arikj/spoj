#include<stdio.h>
const int dig = 26;
int check(int visit[])
{
int i;

for(i=0;i<dig;i++)
	{
	if(visit[i]==0)
		return i;
	}

return -1;
}


int main()
{
int i,t,j,res,flag,len,visit[dig],done,size;
char ch[26],fix[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char store[26];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	len=0;
	res=0;
	for(j=0;j<dig;j++)
		{visit[j]=0;}
	scanf("%s",ch);

	done=check(visit);
	while(done!=-1)
		{
		size=0;
		while(visit[done]==0)
			{
			store[size]=fix[done];
			size++;
			visit[done]=1;
			
			for(j=0;j<dig;j++)
				{
				if(fix[j]==ch[done])
					{
					done=j;
					break;
					}
				}
			}

	
//		for(j=0;j<size;j++)
//			printf("%c ",store[j]);

//		printf("%d\n",size);
		if(size%2==0)
			{

			if(res==1 && flag==1)
				res=0;

			else if(res==0 && flag==0)
				res=1;
			flag=1;
			}

		else
			flag=0;

		

		done=check(visit);
		}

	if(res==0)
		printf("Yes\n");		

	else	
		printf("No\n");	
	
	}

return 0;
}

