#include<stdio.h>

int list[1000][2];


void inc_sort(int n)
{
int i,j,min,temp;
for(i=0;i<n-1;i++)
	{
	min=i;
	for(j=i+1;j<n;j++)
		{
		if(list[min][0]>list[j][0])
			min=j;
		}

	if(min!=i)
		{
		temp = list[min][0];
		list[min][0] = list[i][0];
		list[i][0] = temp;

		temp = list[min][1];
                list[min][1] = list[i][1];
                list[i][1] = temp;

		}
	}	
}


int main()
{
int t,i,j,n,store[1000],count,ans,update[1000],start,dup;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count=0;
	scanf("%d",&n);
	
	

	for(j=0;j<n;j++)
		{
		scanf("%d %d",&list[j][0],&list[j][1]);
		store[j]=0;
		update[j]=1;
		}

	inc_sort(n);
	for(j=1;j<n;j++)
		{
		if(list[j][0]<=list[store[count]][1])
			update[count]+=1;
	
		else
			break;
		}

	count++;
	store[count]=update[count-1]+store[count-1];	

	while(store[count]<n)
		{
		for(j=store[count]+1;j<n;j++)
			{
			if(list[j][0]<=list[store[count]][1])
                        	update[count]+=1;

	                else
        	                break;

			}

		if(update[count-1]!=3 && update[count-1]!=1)
			{
			if(update[count-1]==2)
				{
				if(list[store[count]+update[count]-1][0]<=list[store[count-1]+1][1] && list[store[count-1]+1][0]!=list[store[count-1]][0])
					{
					update[count-1]-=1;
					update[count]+=1;
					store[count]-=1;
					}
				}

			else
				{
				start=store[count]-1;
				while(update[count-1]>3)
					{

					if(list[start][0]==list[start-1][0])
						{
						dup=1;
						while(list[start][0]==list[start-1][0])
							{
							start--;		
							dup++;
							}

						if(update[count-1]-dup>=3)
							{
							update[count-1]-=dup;
							update[count]+=dup;
							store[count]=start;
							}

						else
							break;
							
						}

					else if(list[store[count]+update[count]-1][0]<=list[start][1])
						{
						update[count-1]-=1;
						update[count]+=1;	
						store[count]-=1;
						start--;
						}
					

					else
						break;	
					}
							
				}
			}	
		
		count++;
		store[count] = update[count-1]+store[count-1];
		}

	ans=0;
	for(j=0;j<count;j++)
		{
		if(update[j]>2)
			ans+=update[j];
		
//		printf("%d %d\n",store[j],update[j]);
		}
	printf("Case #%d: %d\n",i+1,ans);
	}

return 0;
}
