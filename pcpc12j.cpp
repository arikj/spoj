#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
int i,j,t,n,arr[10000],f,d,maxf,mind;
scanf("%d",&t);
for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)	
		scanf("%d",&arr[j]);
	sort(arr,arr+n);
	f = 1;
	d = arr[0];
	maxf = 0;
	mind = -1;
	for(j=1;j<n;j++)
		{
		if(arr[j] == arr[j-1])
			f++;
		else
			{
			if(f%d == 0 && f>maxf)
				{
				maxf = f;
				mind = d;
				}
			f = 1;
			d = arr[j];				
			}	
		}
	if(f%d == 0 && f>maxf)
		mind = d;
	printf("%d\n",mind);
	}
return 0;
}

