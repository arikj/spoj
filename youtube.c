#include<stdio.h>


void compute(int start[], int cycle[], int k)
{
int index=1,count = 0,len;
int visited[100001];

while(count<k)
	{
	if(visited[index]!= 0)
		{
		len = 1;
		visited[index] = -1;
		index = start[index];
		while(visited[index]!=-1)
			{
			len++;
			visited[index] = -1;
			index = start[index];
			}
		cycle[index] = len;
		visited[index] = 1;
		index = start[index];
		while(visited[index]!= 1)
			{
			cycle[index] = len;
			visited[index] = 1;
			index = start[index];
			}
		index = 1;
		while(visited[index]!=0)
			index++;
		}

	else
		{
		visited[index]=1;
		index = start[index];
		count++;
		}
	}
}


int main()
{
int i,n,k,m,index,s;
int start[100001];
int cycle[100001];
int list[100001];
int res[100001];

scanf("%d %d %d",&n,&k,&m);

for(i=1;i<=n;i++)
	scanf("%d",&start[i]);

for(i=1;i<=k;i++)
	scanf("%d",&list[i]);

compute(list,cycle,k);
s = m;
for(i=1;i<=n;i++)
	{
	if(res[start[i]]!=0)
		printf("%d ",res[start[i]]);

	else{
	m = s;
	index = start[i];
	m--;
	while(cycle[index] == 0 && m>0)
		{
		index = list[index];
		m--;
		}
	if(m>0)
		{
		m = m%cycle[index];
		while(m>0)
			{
			index = list[index];
			m--;
			}
		}
	res[start[i]] = index;
	printf("%d ",index);
	}
	}
printf("\n");
return 0;
}
