#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

struct node{
int index;
int cost;
struct node *next;
};

struct node graph[5001];
int maxval=1000000001;

void add(int u,int v,int w)
{
	int flag=0;
	struct node *start = &graph[u];
	while(start->next!=NULL)
		{
		if((start->next)->index == v)
			{
			(start->next)->cost+=w;
			flag=1;
			break;
			}
		start=start->next;
		}
	if(flag==0)
		{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
        	temp->index=v;
        	temp->cost=w;
        	temp->next=NULL;
		start->next=temp;
		}
	flag=0;

	struct node *start2 = &graph[v];
        while(start2->next!=NULL)
                {
                if((start2->next)->index == u)
                        {
                        (start2->next)->cost+=w;
                        flag=1;
                        break;
                        }
                start2=start2->next;
                }
        if(flag==0)
                {
                struct node *temp2=(struct node*)malloc(sizeof(struct node));
                temp2->index=u;
                temp2->cost=w;
                temp2->next=NULL;
                start2->next=temp2;
                }

}

int min(int val, int u,int v)
	{
	int cost;
	struct node *start2 = &graph[u];
        while(start2->next!=NULL)
                {
                if((start2->next)->index == v)
                        {
                        cost = (start2->next)->cost;
        
                        break;
                        }
                start2=start2->next;
                }
	
	if(cost<val)
		return cost;
	else
		return val;
	}

void insert(int u,int v,int flow)
	{
	struct node *start = &graph[u];
        while(start->next!=NULL)
                {
                if((start->next)->index == v)
                        {
                        ((start->next)->cost)-=flow;
                       
                        break;
                        }
                start=start->next;
                }

	struct node *start2 = &graph[v];
        while(start2->next!=NULL)
                {
                if((start2->next)->index == u)
                        {
                        ((start2->next)->cost)+=flow;
                       
                        break;
                        }
                start2=start2->next;
                }


	}

bool bfs(int s,int t,int parent[])
	{
	bool visited[5001];
	
	queue<int> q;
	q.push(s);
	for(int i=0;i<5001;i++)
		visited[i]=false;
	parent[s]=-1;
	visited[s]=true;
	while(!q.empty())
		{
		int u=q.front();
		q.pop();
		struct node *start2 = &graph[u];
	        while(start2->next!=NULL)
                {
                if((start2->next)->cost>0 && visited[(start2->next)->index]==false)
                        {
                        visited[(start2->next)->index]=true;
			q.push((start2->next)->index);
			parent[(start2->next)->index]=u;
                        }
                start2=start2->next;
                }

		}
	if(visited[t]==true)
		return 1;
	else return 0;
	}

long long int fordfulkerson(int s, int t)
	{	
	int parent[5001];
	long long int max_flow=0;
	int path_flow;
	int u,v;

	while(bfs(s,t,parent))
		{
		path_flow = maxval;
		
		for(v=t;v!=s;v=parent[v])
			{
			u=parent[v];
			path_flow=min(path_flow,u,v);
			}	

		for(v=t;v!=s;v=parent[v])
			{
			u=parent[v];
			insert(u,v,path_flow);
			}
		max_flow+=path_flow;	
		}
	return max_flow;
	}

int main()
{
int i,j,n,m,u,v,w;
long long int res;
scanf("%d %d",&n,&m);

for(j=0;j<=n;j++)
		{
		graph[j].index=j;
		graph[j].cost=0;
		graph[j].next=NULL;
		}

for(i=0;i<m;i++)
	{
	scanf("%d %d %d",&u,&v,&w);
	if(u!=v)
		add(u,v,w);	
	}

/*for(i=1;i<=n;i++)
	{
	 struct node *start2 = &graph[i];
        while(start2->next!=NULL)
                {
                printf("%d %d   ",start2->next->index,start2->next->cost);
                start2=start2->next;
                }
	printf("\n");
	}*/
res = fordfulkerson(1,n);
printf("%lld\n",res);
return 0;
}
