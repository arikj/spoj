#include<stdio.h>

int p = 1000000007;

long long int matrix[2][2];


long long int compute(long long int n)
{
if(n==2)
	return 2*2;

if(n==1)
	return 2;

long long int x=compute(n/2);

if(n%2==0)
	return (x*x)%p;

else
	return (((x*x)%p)*(2))%p;
}


void matrixmult(long long int n)
{
if(n==2)
	{
	matrix[0][0]=2;
	matrix[0][1]=1;
	matrix[1][0]=1;
	matrix[1][1]=1;
	return;
	}

else if(n==3)
	{
	matrix[0][0]=3;
        matrix[0][1]=2;
        matrix[1][0]=2;
        matrix[1][1]=1;
	return;
	}

matrixmult(n/2);
long long int a[2][2];
long long int temp;

a[0][0]=(((matrix[0][0]*matrix[0][0])%(p-1)) +((matrix[0][1]*matrix[1][0])%(p-1)))%(p-1) ;
a[0][1]=(((matrix[0][0]*matrix[0][1])%(p-1)) +((matrix[0][1]*matrix[1][1])%(p-1)))%(p-1) ;
a[1][0]=(((matrix[0][0]*matrix[1][0])%(p-1)) +((matrix[1][0]*matrix[1][1])%(p-1)))%(p-1) ;
a[1][1]=(((matrix[0][1]*matrix[1][0])%(p-1)) +((matrix[1][1]*matrix[1][1])%(p-1)))%(p-1) ;
	

if(n%2==1)
	{
	temp = a[0][0];
	a[0][0]=(a[0][0]+a[0][1])%(p-1); 
        a[0][1]=temp;
	temp = a[1][0];
        a[1][0]=(a[1][0]+a[1][1])%(p-1);
        a[1][1]=temp;

	}

matrix[0][0]=a[0][0];
matrix[0][1]=a[0][1];
matrix[1][0]=a[1][0];
matrix[1][1]=a[1][1];
}



int main()
{
int t,i;
long long int ans,n;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%lld",&n);

	matrix[0][0]=1;
	matrix[0][1]=1;
	matrix[1][0]=1;
	matrix[1][1]=0;
	if(n>=3){
	matrixmult(n-1);	

	ans = (matrix[1][0] + matrix[1][1])%(p-1);

	ans = compute(ans);
	}

	else if(n==0)	ans = 1;
	else 		ans = 2; 
	printf("%lld\n",ans);
	}
return 0;
}
