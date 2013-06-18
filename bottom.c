#include<stdio.h>
#include<stdlib.h>

int visited[5001];
int stack[5001],all[5001];
int count;
int cnt_scc;

struct adj
	{
	int index;
	struct adj *next;
	};

struct adj graph[5001];
struct adj reverse[5001];

void add(int v,int u)
	{
	struct adj *temp=(struct adj*)malloc(sizeof(struct adj));
        temp->index=u;
	temp->next=NULL;
	struct adj *start = &graph[v];
	while(start->next!=NULL)
		{
		start=start->next;
		}
	start->next=temp;


	 struct adj *temp2=(struct adj*)malloc(sizeof(struct adj));
        temp2->index=v;
        temp2->next=NULL;
        struct adj *start2 = &reverse[u];
        while(start2->next!=NULL)
                {
                start2=start2->next;
                }
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
			dfs(start->index);
		start=start->next;
		}
	stack[count]=v;
	count++;
	}


void dfs2(int v)
	{
	visited[v]=1;
        struct adj *start = &reverse[v];
        start=start->next;
        while(start!=NULL)
                {
                if(visited[start->index]==0)
                        dfs2(start->index);
                start=start->next;
                }
	all[v]=cnt_scc;
	}

int main()
{
int i,n,m,v,u,store[5001],cand[5001],length,flag,first;

scanf("%d",&n);

while(n!=0)
	{
	for(i=0;i<=n;i++)
		{
		graph[i].index=i;
		graph[i].next=NULL;
		visited[i]=0;
		reverse[i].index=i;
                reverse[i].next=NULL;
		cand[i]=-1;
		}

	scanf("%d",&m);
	for(i=0;i<m;i++)
		{
		scanf("%d %d",&v,&u);
		add(v,u);
		}

	
	count=0;
	for(i=1;i<=n;i++)
		{
		if(visited[i]==0)
			dfs(i);	
		}
	
	
	for(i=1;i<=n;i++)
		visited[i]=0;
	
	cnt_scc=1;
	for(i=count-1;i>=0;i--)
		{
		if(visited[stack[i]]==0)
			{
			dfs2(stack[i]);
			cnt_scc++;
			}
		}

	count=0;
	for(i=1;i<=n;i++)
		{
		struct adj *start=&graph[i];
		start=start->next;
		while(start!=NULL)
			{
			if(all[i]!=all[start->index])
				{
				cand[count]=all[i];
				count++;			
				start=NULL;
				}
			if(start!=NULL)
				start=start->next;
			}

		}

		length=1;
		for(v=1; v<count; v++){

   			for(u=0; u< length ; u++)
   			{

      			if(cand[v] == cand[u])
     				 break;
   			}


  			if (u==length )
      				cand[length++] = cand[v];
		}


		first=1;
		for(v=1;v<=n;v++)
			{
			flag=0;
			for(u=0;u<length;u++)
				{
				if(all[v]==cand[u])
					{
					flag=1;
					break;
					}	
				}
			if(flag==0 && first==1)
				{
				printf("%d",v);
				first=0;
				}

			else if(flag==0 && first==0)
				{
				printf(" %d",v);
				}
			}
	printf("\n");

	scanf("%d",&n);
	}
return 0;
}
