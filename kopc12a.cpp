#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
int i,j,t,n,height[10000],cost[10000],sum,hgt,cst;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d",&height[j]);
	sort(height, height+n);

	for(j=0;j<n;j++)
		scanf("%d",&cost[j]);

	sum = 0;
	hgt = arr[0]; 
	cst = cst[0];

	for(j=1;j<n;j++)
		{
		if(cst > cost[j])
			{
			sum+= (height[j]-hgt)*cost[j];
			cst+=cost[j];
			}
		else
			{
			
			}		
		}
	
	}
return 0;
}
