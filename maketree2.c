#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,n,k,num,j,degree[100001]={0};
int **list,count=0,stack[100001],left,right,final[100001],up=0;
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

for(i=1;i<=n;i++)
	{
	if(degree[i]==0)
		{
		stack[count]=i;
		count++;
		}
	}	

left = 0;
right = count-1;

while(left<=right)
	{
	final[up]=stack[left];
	up++;

	if(stack[left]>k)
		{
		left++;
		continue;
		}

	for(j=1;j<=list[stack[left]][0];j++)
			{
			degree[list[stack[left]][j]]--;
			if(degree[list[stack[left]][j]]==0)
				{
				stack[right+1]=list[stack[left]][j];
				right++;
				}


			
			}
	left++;
	}


stack[final[0]]=0;
for(i=1;i<n;i++)
	{
	stack[final[i]]=final[i-1];
	}

for(i=1;i<=n;i++)
	printf("%d\n",stack[i]);
return 0;
}
