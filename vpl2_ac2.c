#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
int i,t,c,x,j,k,flag;
char str[1000001],ch;
int list[1000001];
int color[5][5];
int left,right,max;
// 0-G    1-R     2-Y     3-B      4-O
   
for(i=0;i<5;i++)
	{
	for(j=0;j<5;j++)	
		{
		if(i>j)
			color[i][j]=i-j;
		else
			color[i][j]=j-i;
		}
	}

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&c);
	scanf("%[^\n]",str);
	for(j=1;j<strlen(str);j++)
		{
		
		
			if(str[j]=='G') list[j] = 0;
				
			else if(str[j]=='R')  list[j] = 1;
                                
			else if(str[j]=='Y') list[j] = 2;
                                
			else if(str[j]=='B') list[j] = 3;
               	                 
			else if(str[j]=='O') list[j] = 4;
			
                               
		}

	max=0;	
	left=1;
	right=1;

	if(strlen(str)==2)
		max=1;

	else{
	while(right<strlen(str)-1)
		{
		while(c-color[list[right]][list[right+1]]<0 && left<=right)
			{
			c+=color[list[left]][list[left+1]];
			left++;	
			}
		
		c-=color[list[right]][list[right+1]];
		right++;

		if(max<right-left+1)
			max=right-left+1;
		}
	}
	printf("Scenario #%d: %d\n",i+1,max);
	}
return 0;
}
