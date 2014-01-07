#include<stdio.h>
#include<stdlib.h>

struct adj
	{
	int index;
	struct adj *next;
	};

struct adj graph[100001];
int path,visited[100001];
int count=0, stack[100001], flag;

void add(int u,int v)
	{
	struct adj *temp=(struct adj*)malloc(sizeof(struct adj));
        temp->index=v;
	struct adj *start = &graph[u];
	temp->next = start->next;
	start->next = temp;	
	}


void dfs(int v)
	{
	int i;
	visited[v]=1;
	struct adj *start = &graph[v];
	start=start->next;
	while(start!=NULL)
		{
		for(i=0;i<count;i++)
			{
			if(stack[i] == start->index)
				{
				flag=1;
				return;	
				}
			}

		if(visited[start->index]==0)
			{
			dfs(start->index);
			path++;
			}
		if(flag==1)
			return;
		start=start->next;
		}
	}

int main()
{
int i,j,m,n,u,v;

scanf("%d %d",&n,&m);

for(i=1;i<=n;i++)
        {
        graph[i].index=i;
        graph[i].next=NULL;
        }

for(i=0;i<m;i++)
	{
	scanf("%d %d",&v,&u);
	add(u,v);
	}


for(i=1;i<=n;i++)
	{
	path = 0;
	for(j=1;j<=n;j++)
		visited[j]=0;
	flag=0;
	dfs(i);
	if(path == n-1 || flag==1)
		{
		stack[count]=i;
		count++;		
		}
	}
printf("%d\n",count);
for(i=0;i<count-1;i++)
	printf("%d ",stack[i]);
printf("%d\n",stack[count-1]);
	 
return 0;
}
