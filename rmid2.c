#include<stdio.h>
#include<stdlib.h>

struct element
	{
	int num;
	struct element *next;
	struct element *prev;
	};

void sortedinsert(struct element **h1, struct element **t1,int n)
{
if(*h1 == NULL)
	{
	struct element *temp = (struct element*)malloc(sizeof(struct element));
	temp->num = n;
	temp->prev = NULL;
	temp->next = NULL;
	*h1 = temp;
	*t1 = temp;
	}

else if((*h1)->num >= n)
	{
	struct element *temp = (struct element*)malloc(sizeof(struct element));
        temp->num = n;
        temp->prev = NULL;
        temp->next = *h1;
	(*h1)->prev = temp;
	*h1 = temp;
	}

else if((*t1)->num <= n)
	{
	struct element *temp = (struct element*)malloc(sizeof(struct element));
        temp->num = n;
        temp->prev = *t1;
        temp->next = NULL;
	(*t1)->next =temp;
	*t1 = temp;
	}
else
	{
	struct element *temp = (struct element*)malloc(sizeof(struct element));
        temp->num = n;
        temp->prev = NULL;
        temp->next = NULL;
	struct element *find = *h1;
	while(find!= NULL)
		{
		if(n<=find->num)
			{
			temp->next = find;
			temp->prev = find->prev;
			find->prev->next = temp;
			find->prev = temp;
			return;	
			}
		find = find->next;
		}
	
	}

}


int main()
{
int i,len1=0,len2=0,n;
struct element *h1, *t1, *h2, *t2;
h1 = h2 = t1 = t2  = NULL;
struct element *temp;
while(scanf("%d",&n)!= EOF)
	{
	if(n==0)
		{
		len1 = len2 = 0;
		h1 = h2 = t1 = t2  = NULL;		
		printf("\n");
		}

	else if(n == -1)
		{
		if(len1!= 0){
		printf("%d\n",t1->num);
		if(len1 > len2)
			{
			t1 = t1->prev;
			if(t1!=NULL)
				t1->next = NULL;
			else
				h1 = NULL;
			len1--;
			}
			
		else
			{
			t1 = t1->prev;
			temp = h2->next;
			if(t1 == NULL)
				{
				t1 = h1 = h2;
				t2 = h2 = NULL;
				}
			else
				{
                       		t1->next = h2;
                      		h2->prev = t1;
                        	h2->next = NULL;
                       		temp->prev = NULL;
                        	t1 = h2;
                        	h2 = temp;
				}
			len2--;
			}
		}
		}
	else
		{
		if(len1 > len2)
			{
			if(t1->num <= n)
				{
				sortedinsert(&h2,&t2,n);
				}
				
			else
				{
				sortedinsert(&h1,&t1,n);
				temp = t1->prev;
				if(h2 == NULL)
					{
					temp->next  = NULL;
					t1->prev = NULL;
					t1->next = NULL;	
					h2 = t1;
					t1 = temp;
					}
				else
					{
					t1->next = h2;
					h2->prev = t1;
					t1->prev = NULL;
					h2 = t1;
					t1 = temp;
					t1->next = NULL;
					}
				}	
			len2++;	
			}

		else
			{
			if(t1 == NULL)
				{
				sortedinsert(&h1,&t1,n);
				}
			else if(t1->num > n)
				{
				sortedinsert(&h1,&t1,n);
				}

			else
				{
				sortedinsert(&h2,&t2,n);
				temp = h2->next;
				t1->next = h2;
				h2->prev = t1;
				h2->next = NULL;
				temp->prev = NULL;
				t1 = h2;
				h2 = temp;
				}
			len1++;
			}	
		}
	temp = h1;
	printf("Low: ");
	while(temp!=NULL)
		{
		printf("%d ",temp->num);
		temp = temp->next;
		}
	printf("\nHigh: ");
	temp = h2;
	while(temp!=NULL)
		{
		printf("%d ",temp->num);
                temp = temp->next;
		}
	printf("\n");
	
	}
return 0;
}
