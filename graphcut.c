#include<stdio.h>
#include<stdlib.h>

struct adj
	{
	int index;
	struct adj *next;
	};

struct adj graph[501];
int count,cc[501],visited[501];

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
        struct adj *start2 = &graph[u];
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
	cc[v]=count;
	}



int main()
{
int t,n,m,k,i,j,flag,v,u,x,temp,part[501];
int match[10000][2];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d %d",&n,&m,&k);
	flag=0;
	for(j=0;j<=n;j++)
		{
		graph[j].index=j;
		graph[j].next=NULL;
		visited[j]=0;
		part[j]=0;
		}

	for(j=0;j<k;j++)
		{
		scanf("%d %d",&match[j][0],&match[j][1]);
		}

	for(j=k;j<m;j++)
		{
		scanf("%d %d",&u,&v);
		add(u,v);
		}

	count=1;
	for(j=1;j<=n;j++)
		{
		if(visited[j]==0)
			{
			dfs(j);	
			count++;
			}
		}

	for(j=0;j<k;j++)
		{
		u = match[j][0];
		v = match[j][1];

		if(cc[u]==cc[v])
			{
			printf("NO\n");
			flag=1;
			break;
			}

		else if(part[u]==0 && part[v]==0)
			{
			for(x=1;x<=n;x++)
				{
				if(cc[x]==cc[u])
					part[x]=1;

				else if(cc[x]==cc[v])
					part[x]=2;
				}	
			}

		else if(part[u]==0)	
			{
			if(part[v]==1)
				temp=2;

			else
				temp=1;
			for(x=1;x<=n;x++)
				{
				if(cc[x]==cc[u])
					part[x]=temp;	
				}
			}

		else if(part[v]==0)
                        {
                        if(part[u]==1)
                                temp=2;

                        else
                                temp=1;
                        for(x=1;x<=n;x++)
                                {
                                if(cc[x]==cc[v])
                                        part[x]=temp;
                                }
                        }

		else
			{
			if(part[v]==part[u])
				{
				printf("NO\n");
				flag=1;
				break;
				}
			}

			
		}
	if(flag==0)
		printf("YES\n");

		
	}
return 0;
}
