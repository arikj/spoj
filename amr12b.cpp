#include<stdio.h>
#include<stdlib.h>

struct node
	{
	int num;
	struct node *next;
	};

struct node *list[1000001];

void insert(int x,int y)
{
struct node *tmp1 = (struct node*)malloc(sizeof(struct node));
tmp1->num = x;
tmp1->next = list[y];
list[y]=tmp1;
struct node *tmp2 = (struct node*)malloc(sizeof(struct node));
tmp2->num = y;
tmp2->next = list[x];
list[x]=tmp2;
}

int main()
{
int t,i,j,n,m;
int x,y,count,flag;
struct node *tmp;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&m);
	for(j=0;j<=n;j++)
		list[j] = NULL;
	for(j=0;j<m;j++)
		{
		scanf("%d %d",&x,&y);
		insert(x,y);
		}
	for(j=n;j>=0;j--)
		{
		tmp = list[j];
		count = 0;
		flag=0;
		while(tmp!=NULL)
			{
			if(tmp->num < j)
				{
				flag=1;
				break;
				}
			else
				count++;
			tmp = tmp->next;
			}
		if(n-j == count && flag==0)
			{
			printf("2 %d\n\n",j);
			flag=2;
			break;
			}
		}
	if(flag!=2)
		printf("1\n\n");
	}
return 0;
}
