#include<stdio.h>
#include<map>
#include<string.h>
#include<utility>
#include<iostream>

using namespace std;
int num;

struct node{
int parent;
int rank;
int len;
int index;
};

map<string, struct node> element;
struct node list[100000];

int find(int index)
{
if(list[index].parent == -1)
	return index;
else
	{
	list[index].parent = find(list[index].parent);
	return list[index].parent;
	}
}

int set_union(char name1[], char name2[])
{
int index1,index2;
if(element.count(name1)==0 && element.count(name2)==0)
	{
	element.insert(std::pair<string, struct node>(name1, list[num++]));
	element.insert(std::pair<string, struct node>(name2, list[num++]));
	list[num-2].parent = num-1;
	list[num-2].index = num-2;
	list[num-1].parent = -1;
	list[num-1].index = num-1;
	list[num-1].rank = 1;
	list[num-1].len = 2;
	printf("aaaa\n");
	return 2;
	}
else if(element.count(name1)==0)
	{
	element.insert(std::pair<string, struct node>(name1, list[num++]));
	index1 = find(element[name2].parent);
	list[num-1].parent = index1;
	list[num-1].index = num-1;
	list[index1].len+=1;
	printf("bbbb\n");
	return list[index1].len;
	}
else if(element.count(name2)==0)
	{
	element.insert(std::pair<string, struct node>(name2, list[num++]));
	index1 = find(element[name1].parent);
	list[num-1].parent = index1;
	list[num-1].index = num-1;
	list[index1].len+=1;
	printf("cccc\n");
	return list[index1].len;
	}
else
	{
	printf("dddd %d %d\n",element[name1].parent,element[name2].parent);
	index1 = find(element[name1].index);
	index2 = find(element[name2].index);
	if(index1 == index2)
		return list[index1].len;
	else
		{
		if(list[index1].rank < list[index2].rank)
			{
			list[index1].parent = index2;
			list[index2].len+=list[index1].len;
			return list[index2].len;
			}
		else if(list[index1].rank > list[index2].rank)
			{
			list[index2].parent = index1;
			list[index1].len+=list[index2].len;
			return list[index1].len;
			}
		else
			{
			list[index1].parent = index2;
                        list[index2].len+=list[index1].len;
			list[index2].rank+=1;
			return list[index2].len;
			}
		}
		
	}
}

int main()
{
char name1[21], name2[21];

int i,j,t,n,x;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	num = 0;
	element.clear();
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%s %s",name1,name2);	
		x = set_union(name1,name2);
		printf("%d\n",x);
		}
	}
return 0;
}
