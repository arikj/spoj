#include<stdio.h>
#include<stdlib.h>

struct node
	{
	int num;
	struct node* next;
	};
struct node *list[100000];

int visited[100000],res;

void insert(int x,int y)
{
struct node *tmp1 = (struct node *)malloc(sizeof(struct node));
struct node *tmp2 = (struct node *)malloc(sizeof(struct node));
tmp1->num = x;
tmp1->next = list[y];
list[y] = tmp1;

tmp2->num = y;
tmp2->next = list[x];
list[x] = tmp2;
}


void dfs(int index)
{
visited[index] = 1;
res++;
struct node *tmp = list[index];

while(tmp!=NULL)
	{
	if(visited[tmp->num]==0)
		dfs(tmp->num);	
	tmp=tmp->next;
	}
}

int main()
{
int t,n,e,i,j,x,y,ans,index;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&e);
	ans = n;
	for(j=0;j<n;j++)
		{
		list[j] = NULL;
		visited[j] = 0;
		}
	for(j=0;j<e;j++)
		{
		scanf("%d %d",&x,&y);
		insert(x,y);
		}
	index = 0;
	while(1)
		{
		dfs(index);		
		ans = ans - res + 1;
		res=0;
		for(j=index+1;j<n;j++)
			{
			if(visited[j]==0)
				{
				index = j;
				break;
				}
			}
		if(j>=n)
			break;
		}
	printf("%d\n",ans);
	}
return 0;
}
