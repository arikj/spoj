#include<stdio.h>
#include<stdlib.h>

int visited[1001],list[1001],count;
int set[1001];
int n,id;
void add(int u,int v)
	{
	int i,temp;
	if(set[u]==0 && set[v]==0)
		{
		set[u]=id;
		set[v]=id;
		id++;
		}

	else if(set[u]==0 && set[v]!=0)
		set[u]=set[v];

	else if(set[u]!=0 && set[v]==0)
		set[v]=set[u];

	else
		{
		temp=set[u];
		for(i=1;i<=n;i++)
			{
			if(set[i]==temp)
				set[i]=set[v];
			}	
		}
		
	}

void sort(int *arr,int n)
	{
	int i,j,min,temp;
	for(i=0;i<n;i++)
		{
		min=i;
		for(j=i+1;j<n;j++)
			{
			if(arr[min]>arr[j])
				min=j;
			}
		if(min!=i)
			{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
			}
		}
	}


int main()
{
int t,m,i,j,k,u,v;
int a[1001],new[1001];
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&m);

	for(j=1;j<=n;j++)
		{
		scanf("%d",&a[j]);
		set[j]=0;
		}

	id=1;
	
	for(j=1;j<=m;j++)
		{
		scanf("%d %d",&u,&v);
		add(u,v);
		}


	for(j=1;j<id;j++)
		{
		count=0;
		for(k=1;k<=n;k++)
			{
			if(set[k]==j)
				{
				list[count]=k;
				new[count]=a[k];	
				count++;
				}
			}
		if(count>1)
			{
			sort(new,count);
			for(k=0;k<count;k++)
				a[list[k]]=new[k];	
			}	
		}

	for(j=1;j<n;j++)
		printf("%d ",a[j]);
	printf("%d\n",a[n]);
	}
return 0;
}
