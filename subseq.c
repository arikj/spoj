#include<stdio.h>
#include<stdlib.h>

struct hash{
long long int num;
int pos;
struct hash *next;
};

int main()
{
int t,n,i,j,x,count;
long long int sum[1000000];
struct hash *head;
struct hash table[100000];
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count = 0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		sum[j] = 0;
	for(j=0;j<100000;j++)
		table[j].next = NULL;

	for(j=0;j<n;j++)
		{
		scanf("%d",&x);
		if(j>0)
			sum[j]= x+sum[j-1];
		else
			sum[j] = x;
		x = sum[j]%100000;
		struct hash *node = (struct hash *)malloc(sizeof(struct hash));
		node->num = sum[j];
		node->pos = j;
		node ->next = table[x].next;
		table[x].next = node;	
		}
	/*for(j=0;j<70;j++)
		{
		head = table[j].next;
		printf("%d: ",j);
		while(head!=NULL)
			{
			printf("%d %d ||",head->num, head->pos);
			head = head->next;
			}
		printf("\n");
		}*/
	for(j=-1;j<n;j++)
		{
		if(j>-1)
			x = sum[j]+47;
		else
			x = 47;
		x = x%100000;
		head = table[x].next;
		while(head!=NULL)
			{
			if(head->num == x && head->pos > j)
				count++;
			head = head->next;
			}
		}
	printf("%d\n",count);
	}
return 0;
}
