#include<stdio.h>

int a[120][120];

int check()
{
int i,j;

for(i=0;i<120;i++)
	{
	for(j=0;j<120;j++)
		{
		if(a[i][j]==1)
			return 0;
		}
	}
return 1;
}

int main()
{
int num1,num2,t,i,j,n,x,y,ans,max1,max2,sum,index1,index2;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	ans=0;
	scanf("%d",&n);

	for(x=0;x<120;x++)
		for(y=0;y<120;y++)
			a[x][y]=0;

	for(j=0;j<n;j++)
		{
		scanf("%d %d",&x,&y);
		a[x][y]=1;
		}
	while(check()==0)
	{
	max1=0;
	for(x=0;x<120;x++)
		{
		sum=0;
		for(y=0;y<120;y++)
			{
			sum+=a[x][y];
			}

		if(sum>0)
			num1+=1;
		if(max1<sum)
			{
			max1=sum;
			index1=x;
			}	
		}

	max2=0;
        for(x=0;x<120;x++)
                {
                sum=0;
                for(y=0;y<120;y++)
                        {
                        sum+=a[y][x];
                        }
		if(sum>0)
			num2+=1;
                if(max2<sum)
			{
                        max2=sum;
			index2=x;
			}
                }

	if(num1<num2)
		{
		for(x=0;x<120;x++)
			a[index1][x]=0;
	
		}

	else if(num2<num1)
		{
		 for(x=0;x<120;x++)      
                        a[x][index2]=0;
		}

	else
		{
		if(max1>max2)
			{
			 for(x=0;x<120;x++)
                        a[index1][x]=0;
			}

		else 	
			{
			for(x=0;x<120;x++)
                        a[x][index2]=0;

			}
		}
	ans+=1;
	}

	printf("%d\n",ans);
	}

return 0;
}
