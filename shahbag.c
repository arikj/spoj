#include<stdio.h>

int main()
{
int i,n,a[20002],x,j,count=1,res=0;

scanf("%d",&n);

for(i=0;i<20002;i++)
	a[i]=-1;

for(i=0;i<n;i++)
	{
	scanf("%d",&x);
	
	if(a[x-1]==-1 && a[x+1]==-1)
		{
		a[x]=count;
		res+=1;
		count++;
		}

	else if(a[x-1]==-1 && a[x+1]!=-1)
		{
		a[x]=a[x+1]; 
		}
	
	 else if(a[x-1]!=-1 && a[x+1]==-1)
                {
                a[x]=a[x-1];
                }

	else if(a[x-1]!=-1 && a[x+1]!=-1)
		{
		a[x]=a[x-1];
		j=x+1;
		while(j<=n && a[j]!=-1)
			{
			a[j]=a[x-1];
			j++;
			}

		res-=1;
		}

	//for(j=0;j<n+2;j++)
	//	printf("%d ",a[j]);

	printf("%d\n",res);
	}

printf("Justice\n");
return 0;
}
