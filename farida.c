#include<stdio.h>

int main()
{
int t,n,i,j;
long long int max1,max2,max3,x,temp,max;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	max=0;
	scanf("%d",&n);

	for(j=0;j<n;j++)
		{

		scanf("%lld",&x);

		if(j==0)
			{
			max1=x;max=max1;
			}

		else if(j==1)
			{max2=x; if(max<max2) max=max2;}

		else if(j==2)
			max3=max1+x; 

		else
			{
			if(max1>max2)
				temp = max1+x;
				

			else
				temp=max2+x;
				

			 max1=max2;
                         max2=max3;
                         max3=temp;

		
			}	

		if(j>=2 && max<max3)
			max=max3;
					
		}

	printf("Case %d: ",i+1);

        printf("%lld\n",max);

                
	
	}
return 0;
}


