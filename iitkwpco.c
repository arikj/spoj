#include<stdio.h>

void sort(int *arr,int n)
	{
	int i,j,min,temp;
	for(i=0;i<n;i++)
		{
		min=i;
		for(j=i+1;j<n;j++)
			{
			if(arr[min]>arr[j])
				min=j;
			}
		if(min!=i)
			{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
			}
		}
	}

int main()
{
int t,n,i,j,k,count;
int arr[101],check[101];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count=0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%d",&arr[j]);
		check[j]=0;
		}
	sort(arr,n);
	for(j=1;j<n;j++)
		{
		if(arr[j]%2==0)
			{	
			for(k=0;k<j;k++)
				{
				if(check[k]==0 && arr[k]==arr[j]/2)
					{
					count++;
					check[k]=1;
					check[j]=1;
					break;
					}		
				}
			}	
		}
	printf("%d\n",count);
			
		
	}
return 0;
}
