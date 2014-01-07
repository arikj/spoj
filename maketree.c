#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,k,i,num,degree[100001]={0};
int **list,boss[100001],stack[100001];
int left,right,main,j,count,last,mark,flag;

scanf("%d %d",&n,&k);

list = (int**)malloc((k+1)*sizeof(int *));

for(i=1;i<=k;i++)
	{
	scanf("%d",&num);
	
	list[i]=(int*)malloc((num+1)*sizeof(int));
	list[i][0]=num;
	for(j=1;j<=num;j++)
		{
		scanf("%d",&list[i][j]);	
		degree[list[i][j]]+=1;
		}	
	}
	count=0;
	for(j=1;j<=k;j++)
		{
		if(degree[j]==0)
			{
			stack[count]=j;
			count++;
			}
		}

	left=0;
	right=count-1;
	main = stack[0];
	last=main;
	mark=right+1;
	flag=main;
	while(left<=right)	
		{
		
		if(left==mark)
			{	
			boss[stack[left]]=flag;
			last = stack[left];
			flag=last;
			}
		else
			{
			boss[stack[left]]=last;
                        last = stack[left];
	
			}

	
		for(j=1;j<=list[stack[left]][0];j++)
			{
			degree[list[stack[left]][j]]--;
			if(degree[list[stack[left]][j]]==0)
				{
				boss[list[stack[left]][j]]=stack[left];

				if(list[stack[left]][j]<=k)
					{
					stack[right+1]=list[stack[left]][j];
					right++;
					}
				}
			}
		left++;
		if(left==mark)
			mark = right+1;
		}
	
	for(j=1;j<=n;j++)
		{
		if(boss[j]!=0 || j==main)	
			printf("%d\n",boss[j]);

		else
			printf("%d\n",main);
		}
	
return 0;
}
