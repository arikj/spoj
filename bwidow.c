#include<stdio.h>

int main()
{
int i,j,t,n,arr1[1001],arr2[1001];
int maxa,maxb;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d %d",&arr1[j],&arr2[j]);
	
	maxa=0;	
	for(j=1;j<n;j++)
		{
		if(arr1[j]>arr1[maxa] || (arr1[j]==arr1[maxa] && arr2[j]>arr2[maxa]))
			maxa=j;
		}
	maxb=0;
	for(j=1;j<n;j++)
		{
		if(arr2[j]>arr2[maxb] && j!=maxa)
			maxb=j;
		}	
	if(n==2)
		maxb = (maxa+1)%2;
		
		
	if(arr1[maxa]>arr2[maxb])
		printf("%d\n",maxa+1);
	else
		printf("-1\n");
	}
return 0;
}

