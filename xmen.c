#include<stdio.h>

int find_lis( int* a, int N ) {
   int best[100001], i, j, max =-1;

 
   for ( i = 1; i <= N; i++ ) best[i] = 1;
 
   for ( i = 2; i <= N; i++ )
      for ( j = 1; j < i; j++ )
         if ( a[i] > a[j] && best[i] < best[j] + 1 ){
		    best[i] = best[j] + 1;
			if(max < best[i])
				max = best[i];
		 }         
 
if(max==-1)		 
   return 1;

else
	return max;
}

int main()
{
int i,t,j,n,a[100001],b[100001],c[100001],res;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);

	for(j=1;j<=n;j++)
		{
		scanf("%d",&a[j]);
		c[a[j]]=j;
		}

	 for(j=1;j<=n;j++)
		{
                scanf("%d",&b[j]);
		a[j]=c[b[j]];
		}

	res = find_lis(a,n);
	
	printf("%d\n",res);

	
	}

return 0;
}
