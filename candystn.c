#include<stdio.h>

int main()
{
int t,n,m,i,j,a[10001],b[10000],minx,miny,x,y;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&m);
	minx=n;
	miny=0;
	x=n;
	y=0;
	for(j=0;j<m;j++){
		scanf("%d",&a[j]);
		if(j>=1)
		{
		b[j-1]=a[j]-a[j-1];

		if(b[j-1]!=0)
			{
			x-=b[j-1];
			y+=b[j-1];
			}

		else
			y-=1;

			if(y<miny)
				miny=y;		
		
			if(x<minx)
				minx=x;
		}
		}

	if(minx+miny-1>=0)
		printf("%d\n",-1*miny+1);

	else
		printf("%d\n",-1);

	
	}

return 0;
}
