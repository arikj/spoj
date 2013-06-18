#include<stdio.h>

int main()
{
int i,n,a[300001],max1=0,max2=0,ans=0;

scanf("%d",&n);

for(i=0;i<n;i++)
	scanf("%d",&a[i]);
max2 = a[0];
for(i=1;i<n;i++)
	{
	if(a[i]>max2)
		{
		if(max1<a[i])
			max1=a[i];

		else
			max2=a[i];
		
		}
	}
//printf("%d\n",max2);
if(max2!=a[0])
	ans+=1;

ans+=max2-1;
printf("%d\n",ans);
return 0;

}
