#include<stdio.h>
#include<stdlib.h>

void sort(int *array,int *x,int n)
{
int c,d,t,t2;
for (c = 1 ; c <= n - 1; c++) {
    d = c;
 
    while ( d > 0 && array[d] < array[d-1]) {
      t          = array[d];
      array[d]   = array[d-1];
      array[d-1] = t;
 	t2 = x[d];
	x[d]=x[d-1];
	x[d-1]=t2;
      d--;
    }
  }
}

int lis( int arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] >= arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   /* Free memory to avoid memory leak */
   free( lis );
 
   return max;
}


int main()
{
int t,i,j,res,n,a[1000],b[1000],k,count,c[1000],d[1000];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	
	scanf("%d",&n);

	for(j=0;j<n;j++)
		{
		scanf("%d",&a[j]);
		
		}

	for(j=0;j<n;j++)
                scanf("%d",&b[j]);

			
	sort(a,b,n);

	j=1;
	count=1;
	c[0]=b[0];
	while(j<n)
		{
		if(a[j-1]==a[j])
			{
			c[count]=b[j];
			count++;
			}

		else
			{
			if(count>1)
				{
				sort(c,d,count);
				for(k=0;k<count;k++)
					b[k+j-count] = c[k];
				}
			count=1;
			c[0]=b[j];			
			}
		j++;
		}

				if(count>1)
                                {
                                sort(c,d,count);
                                for(k=0;k<count;k++)
                                        b[k+j-count] = c[k];
                                }


	res = lis(b,n);

	printf("%d\n",res);
	}
return 0;
}
