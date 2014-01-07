#include<stdio.h>
#include<stdlib.h>

struct adj
	{
	int index;
	struct adj *next;
	};

struct adj graph[100001];
int visited[100001],max,store[100001];

void add(int v,int u)
	{
	struct adj *temp=(struct adj*)malloc(sizeof(struct adj));
        temp->index=u;
	struct adj *start = &graph[v];
	temp->next = start->next;
	start->next=temp;

	struct adj *temp2=(struct adj*)malloc(sizeof(struct adj));
        temp2->index=v;
        struct adj *start2 = &graph[u];
	temp2->next = start2->next;
        start2->next=temp2;
	}


void dfs(int v)
	{
	visited[v]=1;
	struct adj *start = &graph[v];
	start=start->next;
	while(start!=NULL)
		{
		if(visited[start->index]==0)
			{
			dfs(start->index);

			if(max<store[v]+store[start->index]+1)
				max = store[v]+store[start->index]+1;

			if(store[v]<store[start->index]+1)
				store[v]=store[start->index]+1;
			}
		start=start->next;
		}

	}



int main()
{
int t,n,i,j,u,v;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	max=0;
	
	for(j=0;j<n;j++)
		{
		graph[j].index=j;
		graph[j].next=NULL;
		visited[j]=0;
		store[j]=0;
		}

	for(j=0;j<n-1;j++)
		{
		scanf("%d %d",&u,&v);
		add(u,v);
		}

	dfs(0);
	if(max%2==0)
		max = max/2;

	else
		max = max/2 +1;
	printf("%d\n",max);	
	}
return 0;
}
