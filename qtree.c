#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct adj
	{
	int index;
	int weight;
	struct adj *next;
	};


struct adj graph1[10001];
int visited[10001],final[10001][3];

void add(int v,int u, int c,int pos)
	{
	struct adj *temp=(struct adj*)malloc(sizeof(struct adj));
        temp->index=u;
	temp->weight=c;
	struct adj *start = &graph1[v];
	temp->next = start->next;
	start->next=temp;

	struct adj *temp2=(struct adj*)malloc(sizeof(struct adj));
        temp2->index=v;
	temp2->weight=c;
        struct adj *start2 = &graph1[u];
	temp2->next = start2->next;
        start2->next=temp2;
	}


void singleadd(int u,int v,int c,int h)
	{
	final[u][0]=v;
	final[u][1]=c;
	final[u][2]=h;	

	}

void dfs(int v,int h)
	{
	visited[v]=1;
	struct adj *start = &graph1[v];
	start=start->next;
	while(start!=NULL)
		{
		if(visited[start->index]==0)
			{
			dfs(start->index,h+1);
			singleadd(start->index,v,start->weight,h+1);
			}
		start=start->next;
		}
	}


int main()
{
int i,t,n,j,a,b,store[10000][3],max;
scanf("%d",&t);
char str[10];
for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	
	for(j=0;j<n;j++)
		{
		graph1[j].index=j;
		graph1[j].next=NULL;
		visited[j]=0;
		}

	for(j=1;j<n;j++)
		{
		scanf("%d %d %d",&store[j][0],&store[j][1],&store[j][2]);
		add(store[j][0],store[j][1],store[j][2],j+1);
		}

	dfs(1,0);
	final[1][0]=0;
	final[1][1]=0;
	final[1][2]=0;

	scanf("%s",str);

	while(strcmp(str,"DONE")!=0)
		{
		scanf("%d %d",&a,&b);

		if(strcmp(str,"QUERY")==0)
			{
			max=0;
			while(a!=b)
				{
				if(final[a][1]>final[b][1])
					max=final[a][1];

				else
					max=final[b][1];

				if(final[a][2]>final[b][2])
					a = final[a][0];

				else	
					b = final[b][0];
					
				}

			printf("%d\n",max);		
			}

		else
			{
			if(store[a][1]==final[store[a][0]][0])
				final[store[a][0]][1]=b;

			else
				final[store[a][1]][1]=b;
			}

		scanf("%s",str);
		}
	}
return 0;
}
