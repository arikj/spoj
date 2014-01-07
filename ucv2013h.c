#include<stdio.h>

int main()
{
int sum,n,m,i,j,curr=1,k,l,store;
int arr[250][250];
int count[100000], id[100000];
scanf("%d %d",&n,&m);
while(n!=0 || m!=0)
	{
	curr = 1;
	for(i=0;i<100000;i++)
		{
		count[i] = 0;
		id[i] = 0;
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&arr[i][j]);

	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			{
			if(arr[i][j] == 1)
				{
				if(i-1>=0 && arr[i-1][j]!=0 && j-1>=0 && arr[i][j-1]!=0 && arr[i-1][j]!=arr[i][j-1])
					{
					store = arr[i-1][j];
					for(k=0;k<=i;k++)	
						{
						for(l=0;l<m;l++)
							{
							if(arr[k][l] == store)
								{
								id[arr[i][j-1]]++;
								arr[k][l] = arr[i][j-1];
								}		
							}
						}
					id[store] = 0;
					arr[i][j] = arr[i][j-1];
					id[arr[i][j-1]]++;							
					}

				else if(i-1>=0 && arr[i-1][j]!=0)
						{
						id[arr[i-1][j]]++;
						arr[i][j] = arr[i-1][j];
						}
				else if(j-1>=0 && arr[i][j-1]!=0)
						{
						id[arr[i][j-1]]++;	
						arr[i][j] = arr[i][j-1];
						}
				else	
					{
					arr[i][j] = curr+1;
					curr++;
					id[curr] = 1;
					}
				}
			}
		}
/*
	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			printf(" %d ",arr[i][j]);
		printf("\n");
		}*/
	store = 0;
	sum = 0;
	for(i=0;i<=curr;i++)
		{
		if(id[i]!=0)
			{
			if(store<id[i])
				store = id[i];
			count[id[i]]++;
			sum++;
			}
		}
	printf("%d\n",sum);
	for(i=0;i<=store;i++)
		{
		if(count[i]!=0)
			printf("%d %d\n",i,count[i]);
		}
	scanf("%d %d",&n,&m);
	}
return 0;
}
