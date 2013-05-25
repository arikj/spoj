#include<stdio.h>

int main()
{
int i,n,j;
long long int a[10001],x;
long long int l=0,r=0;
int p[10001];
scanf("%d",&n);

for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	p[i]=i;
}
int t;
long long int temp;
for(i=1;i<=n;i++){
      temp=a[i];
	t=p[i];
      j=i-1;
      while((temp<a[j])&&(j>=0)){
      a[j+1]=a[j];
	p[j+1]=p[j];
	j-=1;
      }
      a[j+1]=temp;
	p[j+1]=t;
  }


for(i=1;i<=n;i++){
		if(i==1)
			{
			l=a[i];
			printf("%d\n",p[i]);	
			}

		else if(i==2)
			r=a[i];

		else
			{
				if(l+a[i]<r)
					{
					l+=a[i];
					printf("%d\n",p[i]);}

				else
					r+=a[i];
			}		
	}
return 0;
}
