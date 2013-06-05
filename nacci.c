#include<stdio.h>
#include<math.h>

int main()
{
int n,t,i,k;
long long int l,j,f[50],sum,digit,drop;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d %lld",&n,&k,&l);

	for(j=0;j<n;j++)
		f[j]=j;

	digit = pow(10,k);

	sum=(((n)*(n-1))/2) % digit;
	drop=0;
	for(j=0;j<=l-n;j++)
		{
		drop=f[0];
		for(k=0;k<n-1;k++)
			f[k]=f[k+1];

		f[n-1]=sum;
		sum=(2*sum-drop) % digit;	

//		for(k=0;k<n;k++)
//			printf("%lld ",f[k]);

//		printf("\n");
		}

	printf("%lld\n",f[n-1]);
		
	}
return 0;
}
