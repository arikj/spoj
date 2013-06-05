#include<stdio.h>

int main()
{
int i,t,n,j,a[1000],val,count,res;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count=0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d",&a[j]);

	val=a[0];
	for(j=1;j<n;j++)
		val=val^a[j];

	if(val==0)
		printf("Case %d: 0\n",i+1);

	else
		{
		for(j=0;j<n;j++)
			{
			res = a[j]^val;
			if(res < a[j])
				count++;
			}
		printf("Case %d: %d\n",i+1,count);
		}
	}
return 0;
}
