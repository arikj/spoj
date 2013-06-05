#include<stdio.h>



int find_lis(int *a,int n)
{
int i,j,len=0,M[100001],lo,hi,mid;


len=1;
M[1]=1;

for(i=2;i<=n;i++)
	{
	lo=1;hi=len;


	if(a[M[lo]]>a[i])
                        {
                        lo=0;
                        }

        else if(a[M[hi]]<a[i])
                        {
                        lo=hi;
                        }

	else{	
	while(lo<hi)
		{

		mid=(lo+hi)/2;


		if(a[M[mid]]<a[i] && a[M[mid+1]]<a[i])
			{
			lo = mid+1;
			}

		 else if(a[M[mid]]<a[i] && a[M[mid+1]]>a[i])
                        {
			lo=mid;
                        break;
                        }



		else
			{
			hi = mid-1;
			}
		}
	}
	j = lo;

	if(j==len || a[i]<a[M[j+1]])
		{
		M[j+1]=i;
		if(len<j+1)
			len=j+1;
		}
	}
return len;
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
