#include<stdio.h>

/*
void radixsort(int *a, int *b, int *c, int n, int k)
{
int i,output[20000],b1[20000],c1[20000];
int count[100];

for(i=0;i<=k;i++)
	count[i]=0;

for(i=0;i<n;i++)
	count[a[i]]+=1;

for(i=1;i<=k;i++)
	count[i] = count[i] + count[i-1];

for(i=n-1;i>=0;i--)
	{
	output[count[a[i]]-1] = a[i];
	b1[count[a[i]]-1] = b[i];
	c1[count[a[i]]-1] = c[i];
	count[a[i]]--;
	}
for(i=0;i<n;i++)
	{
	b[i] = b1[i];
	c[i] = c1[i];
	a[i] = output[i];	
	}
	
}*/

int main()
{
int n,t,i,j,k,time,h,m,s,rear,front,ans,min,newh,newm,news;
int hr[20000],min[20000], sec[20000],arr[20000];
char ch[10];

scanf("%d",&t);
for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%s",ch);
		k=0;
		hr[j] = min[j] = sec[j] = 0;
		while(ch[k]!=':')
			{
			hr[j] = hr[j]*10 + (ch[k] - '0');
			k++;
			}
		k++;
		while(ch[k]!=':')
			{
			min[j] = min[j]*10 + (ch[k] - '0');
			k++;
			}
		k++;
		while(ch[k]!='\0')
			{
			sec[j] = sec[j]*10 + (ch[k] - '0');
			k++;
			}
		}
		scanf("%d",&time);
	}
return 0;
}
