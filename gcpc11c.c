#include<stdio.h>
#include<stdlib.h>

struct adj
	{
	int index;
	struct adj *next;
	};

struct adj graph[10001];
int visited[10001],degree[10001],recstack[10001];
int cycle=0;

void cyclecheck(int u)
	{
	visited[u]=1;
	recstack[u]=1;
	struct adj *start = &graph[u];
	start=start->next;
	while(start!=NULL)
		{
		if(cycle==1)
			break;
		else if(recstack[start->index]==1)
			cycle=1;
		else if(visited[start->index]==0)
			cyclecheck(start->index);
		start=start->next;
		}
	recstack[u]=0;
	}

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

	}

int main()
{
int t,i,j,n,h,u,v,first,list[10001];
int count,tot,opt,err;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&h);
	count=0;
	opt=-1;
	for(j=0;j<=n;j++)
		{
		graph[j].index=j;
		graph[j].next=NULL;
		visited[j]=0;
		degree[j]=0;
		recstack[j]=0;
		}

	for(j=0;j<h;j++)
		{
		scanf("%d %d",&u,&v);
		add(u,v);
		degree[v]++;
		}

	
	for(j=1;j<=n;j++)
		{
		if(degree[j]==0)
			{
			first=j;
			count++;
			}	
		}

	if(count==0)
		opt=1;

	else
		{
		for(j=1;j<=n;j++)
			{
			cycle=0;
			if(visited[j]==0)
				cyclecheck(j);

			if(cycle==1)
				{
				opt=1;
				break;
				}
			}
	
		}

	
	if(opt==-1 && count>1)	
		opt=2;
	
	else
	{
	list[0]=first;
	tot=1;	
	while(tot<n && opt==-1)
		{
		struct adj *start = &graph[first];
		start=start->next;
		err=0;
		while(start!=NULL)
		{
		degree[start->index]--;
		if(degree[start->index]==0)
			{
			first=start->index;
			err++;	
			}

		if(err>1)
			{
			opt=2;
			break;
			}
		start=start->next;
		}

		list[tot]=first;
		tot++;	
		}

	}

		if(opt==1)
			printf("recheck hints\n");

		else if(opt==2)
			printf("missing hints\n");

		else{
		for(j=0;j<n-1;j++)
			printf("%d ",list[j]);
		printf("%d\n",list[n-1]);
		}
	}
return 0;
}
