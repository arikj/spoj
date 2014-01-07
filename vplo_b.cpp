#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
int i,j,t,n,m,curr;
int arr[100000];
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&m);
	for(j=0;j<n;j++)
		scanf("%d",&arr[j]);
	sort(arr,arr+n);

	printf("Scenario #%d:\n\n",i+1);
	
	for(j=0;j<n;j++)
		{
		if(j==0)
			{
			curr = arr[j]/m;
			printf("%d | %d",curr,arr[j]%m);
			}	

		else
			{
			if(arr[j]/m == curr)
				{
				printf(" %d",arr[j]%m);
				}

			else
				{
				curr = arr[j]/m;
				printf("\n\n%d | %d",curr,arr[j]%m);
				}
			}
		}
	printf("\n\n\n\n");
	}
return 0;
}
