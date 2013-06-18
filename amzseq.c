#include<stdio.h>

long long int matrix[2][2];

void matrixmult(long long int n)
{
if(n==1)
	return;
if(n==2)
	{
	matrix[0][0]=5;
	matrix[0][1]=2;
	matrix[1][0]=2;
	matrix[1][1]=1;
	return;
	}

else if(n==3)
	{
	matrix[0][0]=12;
        matrix[0][1]=5;
        matrix[1][0]=5;
        matrix[1][1]=2;
	return;
	}

matrixmult(n/2);
long long int a[2][2];
long long int temp;

a[0][0]=(((matrix[0][0]*matrix[0][0])) +((matrix[0][1]*matrix[1][0]))) ;
a[0][1]=(((matrix[0][0]*matrix[0][1])) +((matrix[0][1]*matrix[1][1]))) ;
a[1][0]=(((matrix[0][0]*matrix[1][0])) +((matrix[1][0]*matrix[1][1]))) ;
a[1][1]=(((matrix[0][1]*matrix[1][0])) +((matrix[1][1]*matrix[1][1]))) ;
	

if(n%2==1)
	{
	temp = a[0][0];
	a[0][0]=(2*a[0][0]+a[0][1]); 
        a[0][1]=temp;
	temp = a[1][0];
        a[1][0]=(2*a[1][0]+a[1][1]);
        a[1][1]=temp;

	}

matrix[0][0]=a[0][0];
matrix[0][1]=a[0][1];
matrix[1][0]=a[1][0];
matrix[1][1]=a[1][1];
}


int main()
{
	long long int n,ans;

	scanf("%lld",&n);
	matrix[0][0]=2;
	matrix[0][1]=1;
	matrix[1][0]=1;
	matrix[1][1]=0;

	if(n>=2){
	matrixmult(n-1);
	ans = matrix[0][0]*3 + matrix[0][1];
	}

	else if(n==1)
		ans=3;

	else 	ans=1;
	printf("%lld\n",ans);
	return 0;
}
