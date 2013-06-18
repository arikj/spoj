#include<stdio.h>

long int rem = 1000000007;
long long int matrix[2][2];

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

a[0][0]=(((matrix[0][0]*matrix[0][0])%rem) +((matrix[0][1]*matrix[1][0])%rem))%rem ;
a[0][1]=(((matrix[0][0]*matrix[0][1])%rem) +((matrix[0][1]*matrix[1][1])%rem))%rem ;
a[1][0]=(((matrix[0][0]*matrix[1][0])%rem) +((matrix[1][0]*matrix[1][1])%rem))%rem ;
a[1][1]=(((matrix[0][1]*matrix[1][0])%rem) +((matrix[1][1]*matrix[1][1])%rem))%rem ;
	

if(n%2==1)
	{
	temp = a[0][0];
	a[0][0]=(a[0][0]+a[0][1])%rem; 
        a[0][1]=temp;
	temp = a[1][0];
        a[1][0]=(a[1][0]+a[1][1])%rem;
        a[1][1]=temp;

	}

matrix[0][0]=a[0][0];
matrix[0][1]=a[0][1];
matrix[1][0]=a[1][0];
matrix[1][1]=a[1][1];
}


int main()
{
int i,t;
long int ans;
long long int n;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%lld",&n);
	
	matrix[0][0]=1;
	matrix[0][1]=1;
	matrix[1][0]=1;
	matrix[1][1]=0;

	matrixmult(n+1);


	ans = (matrix[0][0] + matrix[0][1] - 2)%rem;
	printf("%ld\n",ans);
	}
return 0;
}
