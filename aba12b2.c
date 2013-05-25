#include<stdio.h>
#include<string.h>

int main()
{
int i,t,j,k,l,x,cl;
char s[100000];
int count[100000]={-1};
int check=0,done;
int res=0;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%s",s);
	for(j=0;j<100000;j++)
		count[j]=-1;

	count[0]=0;
	res=0;
	check=0;	
	for(j=1;j<strlen(s);j++)
		{
//		printf("j=%d\n",j);
		for(k=check;k>=0;k--)
			{
			x=j;
			done=1;
			cl=1;
			for(l=count[k];l<j;l++)
				{
				if(s[x]!=s[l])
					{
					done=0;
					break;
					}

				if(x==l)
					{
					done=0;					
					cl=0;
					break;
					}

				else
					{
					x++;
					}
			
				}

			if(done!=0)
				{
				check++;
				count[check]=x;
				j=x;	
				if(cl==0)
					res+=2;
				else
				res+=2-2*(check-k-1);
//				printf("%d\n",res);
				break;
				}
			
			}			
		}	
	printf("%d\n",res);
	}
return 0;
}

