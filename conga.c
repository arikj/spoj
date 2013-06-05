#include<stdio.h>

int main()
{
long long int i,n,a[1000000],res,mid;

scanf("%lld",&n);

while(n!=0)
	{
	res=0;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);

	mid = n/2;
	if(n%2==0)
		{
		res=a[mid]-a[mid-1]-1;
		
		for(i=1;i<n/2;i++)
                        res+=a[mid+i]-a[mid-i-1]-2*i-1;
		}


	else
		{
		for(i=1;i<=n/2;i++)
			res+=a[mid+i]-a[mid-i]-2*i;							
		}		
			
	printf("%lld\n",res);
	scanf("%lld",&n);	
	}

return 0;
}
