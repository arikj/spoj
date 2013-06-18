#include<stdio.h>
long long int matrix[3][3];
long long int p=1000000007;
void matrixmult(long long int n)
{
if(n==1)
	return;
if(n==2)
	{
	matrix[0][0]=1;
	matrix[0][1]=1;
	matrix[0][2]=1;
	matrix[1][0]=1;
	matrix[1][1]=0;
	matrix[1][2]=1;
	matrix[2][0]=1;
        matrix[2][1]=0;
        matrix[2][2]=0;

	return;
	}

else if(n==3)
	{
	matrix[0][0]=2;
        matrix[0][1]=1;
        matrix[0][2]=1;
        matrix[1][0]=1;
        matrix[1][1]=1;
        matrix[1][2]=1;
        matrix[2][0]=1;
        matrix[2][1]=0;
        matrix[2][2]=1;

	return;
	}

matrixmult(n/2);
long long int a[3][3]={0};
long long int temp;
int i,j,k;

for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
		{
		temp=0;
		for(k=0; k<3; k++)
			temp=(temp+matrix[i][k]*matrix[k][j])%p;
		a[i][j]=(temp)%p;
		}
	}
/*
a[0][0]=(((matrix[0][0]*matrix[0][0])) +((matrix[0][1]*matrix[1][0]))) ;
a[0][1]=(((matrix[0][0]*matrix[0][1])) +((matrix[0][1]*matrix[1][1]))) ;
a[1][0]=(((matrix[0][0]*matrix[1][0])) +((matrix[1][0]*matrix[1][1]))) ;
a[1][1]=(((matrix[0][1]*matrix[1][0])) +((matrix[1][1]*matrix[1][1]))) ;
	
*/
if(n%2==1)
	{
	temp = a[0][0];
	a[0][0]=(a[0][0]+a[0][1])%p;
	a[0][1]=a[0][2]; 
        a[0][2]=temp;

	temp = a[1][0];
        a[1][0]=(a[1][0]+a[1][1])%p;   
        a[1][1]=a[1][2];
        a[1][2]=temp;

	temp = a[2][0];
        a[2][0]=(a[2][0]+a[2][1])%p;   
        a[2][1]=a[2][2];
        a[2][2]=temp;

	}

for(i=0;i<3;i++)
	for(j=0;j<3;j++)
		matrix[i][j]=a[i][j];
}

int main()
{
	long long int n,ans;
	scanf("%lld",&n);
	
	 matrix[0][0]=1;
        matrix[0][1]=0;
        matrix[0][2]=1;
        matrix[1][0]=1;
        matrix[1][1]=0;
        matrix[1][2]=0;
        matrix[2][0]=0;
        matrix[2][1]=1;
        matrix[2][2]=0;

	if(n>3){
	matrixmult(n-3);

	ans = (matrix[0][0]*4 + matrix[0][1]*3 + matrix[0][2]*2)%p;
	}

	else if(n==1)
		ans=2;

	else if(n==2)
		ans=3;

	else
		ans=4;

	printf("%lld\n",ans);
return 0;
}
	
