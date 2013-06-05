#include<stdio.h>

int main()
{
int i,j,n,t,e,x,y,res,k,count=1,a[100000];

scanf("%d",&t);

for(i=0;i<t;i++)
	{

	scanf("%d",&n);
	scanf("%d",&e);

	res = n;

	for(j=0;j<n;j++)
		a[j]=-1;

	for(j=0;j<e;j++)
		{
		scanf("%d %d",&x,&y);
		
		if(a[x]==-1 && a[y]==-1)
			{
			a[x]=count;
			a[y]=count;
			count++;
			res-=1;
			}

		else if(a[x]==-1 && a[y]!=-1)
			{
			a[x]=a[y];
			res-=1;
			}

		 else if(a[x]!=-1 && a[y]==-1)
                        {
                        a[y]=a[x];
                        res-=1;
                        }

		else
			{
			if(a[x]!=a[y])
				{
				res-=1;
				for(k=0;k<n;k++)
					{
					if(a[k]==a[y])
						a[k]=a[x];	
					}
				}

			
			}

		}



	printf("%d\n",res);
	}

return 0;
}
