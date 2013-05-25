#include<stdio.h>

long int fact(int m,int i)
{
int j;
long long int res=1,t=1;
for(j=1;j<=i;j++){
	res=res*(m+j-1);
	t=t*j;
	}
return (res/t);
}

int main()
{
int n,m,a[101],b[101];
long int p[101],t[101],q[101],r[101];
int x,y,i=0,j;
int suma=0,sumb=0;
long int c;
int len_p;
scanf("%d %d",&m,&n);

scanf("%d %d",&x,&y);
while(x!=0 || y!=0)
	{
	a[i]=x;b[i]=y;i++;
	suma+=x;sumb+=y;
	scanf("%d %d",&x,&y);	
	}

len_p=n-suma;
p[0]=1;
for(i=1;i<=len_p;i++)
	{
	p[i]=fact(m,i);
	}


for(i=0;i<m;i++)
	{

	for(j=0;j<=len_p;j++)
		r[j]=0;
	for(j=0;j<=len_p;j++)
		{
		q[j]=p[j];
		r[j+b[i]-a[i]+1]=p[j]*(-1);
		}

	for(j=0;j<=len_p;j++)
		p[j]=q[j]+r[j];

	}
printf("%ld\n",p[len_p]);
return 0;
}
