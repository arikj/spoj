#include<stdio.h>
#include<math.h>

long long int prime(long long int n)
	{
	if(n==1)
		return 0;

	if(n==2 || n==3 || n==5)
		return 1;

	if(n%2==0 || n%3==0 || n%5==0)
		return 0;

	long long int i;
	for(i=7;i<=sqrt(n);i++)
		{
		if(n%i==0)
			return 0;
		}
	return 1;
	}

void sort(long long int *arr,long long int n)
	{
	long long int i,j,min,temp;
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
long long int t,i,j,store[100000],count;
long long int n;

scanf("%lld",&t);

for(i=0;i<t;i++)
	{
	scanf("%lld",&n);
	count=0;
	if(n%2==1)
		printf("0\n");
	else
		{
		n=n/2;
		for(j=1;j<=sqrt(n);j++)
			{
			if(n%j==0)
				{
				if(prime(j)==0)
					{
					store[count]=j;
					count++;
					}
				if(prime(n/j)==0 && j*j!=n)
					{
					store[count]=n/j;
					count++;
					}
				}	
			}
		sort(store,count);
		printf("%lld ",count);
		for(j=0;j<count-1;j++)
			printf("%lld ",store[j]);
		printf("%lld\n",store[count-1]);
		}
	
	
	}
return 0;
}
