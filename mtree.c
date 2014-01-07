#include<stdio.h>
#include<stdlib.h>

struct adj
	{
	int index;
	int weight;
	struct adj *next;
	};

struct adj graph[100001];
int visited[100001];
long long int p=1000000007;
long long int res,sum[100001];

void add(int v,int u, int w)
	{
	struct adj *temp=(struct adj*)malloc(sizeof(struct adj));
        temp->index=u;
	temp->weight=w;
	temp->next=NULL;
	struct adj *start = &graph[v];
	while(start->next!=NULL)
		{
		start=start->next;
		}
	start->next=temp;


	 struct adj *temp2=(struct adj*)malloc(sizeof(struct adj));
        temp2->index=v;
	temp2->weight=w;
        temp2->next=NULL;
        struct adj *start2 = &graph[u];
        while(start2->next!=NULL)
                {
                start2=start2->next;
                }
        start2->next=temp2;


	}


void dfs(int v,int w)
	{
	visited[v]=1;
	struct adj *start = &graph[v];
	start=start->next;
	while(start!=NULL)
		{
		if(visited[start->index]==0)
			{
              		dfs(start->index,start->weight);
			res=(res+((sum[v]*((start->weight)*(1+sum[start->index])))%p))%p;
			sum[v]=(sum[v]+(start->weight * (1+sum[start->index]))%p)%p;
			
			}
		start=start->next;
		}
	}


int main()
{
int n,i,j,u,v,w;
res=0;
scanf("%d",&n);

for(j=1;j<=n;j++)
		{
		graph[j].index=j;
		graph[j].next=NULL;
		graph[j].weight=0;
		visited[j]=0;
		sum[j]=0;
		}

for(i=0;i<n-1;i++)
	{
	scanf("%d %d %d",&u,&v,&w);
	add(u,v,w);
	}

dfs(1,0);

for(i=1;i<=n;i++)
	{
	res=(res+sum[i])%p;
	}
printf("%lld\n",res);
return 0;
}
