#include<stdio.h>

int main()
{
int n,b,a[100],check[100],i,j,flag;

scanf("%d %d",&n,&b);

while(n!=0 || b!=0)
	{
	for(i=0;i<b;i++)
		scanf("%d",&a[i]);

	for(i=0;i<=n;i++)
		check[i]=0;

	for(i=0;i<b;i++)
		{
		check[a[i]]=1;
		for(j=i+1;j<b;j++)
			{
			if(a[i]>a[j])
				check[a[i]-a[j]]=1;

			else
				check[a[j]-a[i]]=1;
			}
		}

	flag=0;
	for(i=0;i<=n;i++)
		{
		if(check[i]==0)
			{
			printf("N\n");
			flag=1;
			break;
			}
		}

	if(flag==0)
		printf("Y\n");		

	scanf("%d %d",&n,&b);
	}
return 0;
}
