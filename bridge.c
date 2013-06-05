#include<stdio.h>

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

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(int *X, int *Y, int m, int n )
{
   int L[1001][1001];
   int i, j;
  
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}


int main()
{
int t,i,j,n,a[1000],b[1000],visit[1000]k,res,max,c[1000],d[1000];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res=1;
	max=1;
	scanf("%d",&n);

	for(j=0;j<n;j++)
		{
		scanf("%d",&a[j]);
		c[j]=j;
		d[j]=j;
		
		}

	for(j=0;j<n;j++)
                scanf("%d",&b[j]);

			
	sort(a,c,n);
	sort(b,d,n);

	res = lcs(c,d,n,n);

	printf("%d\n",res);
	}
return 0;
}
