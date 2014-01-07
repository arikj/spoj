#include<stdio.h>

void sort(int *inter,int n)
	{
	int i,j,min,temp;
	for(i=0;i<n;i++)
		{
		min=i;
		for(j=i+1;j<n;j++)
			{
			if(inter[j]<inter[min])
				min=j;
			}

		if(min!=i)
			{
			temp=inter[min];
			inter[min]=inter[i];
			inter[i]=temp;
			}
		}
	}

int main()
{
int first,last,n,i,j,inter[10001],a,b,count,up,store[5001][2];
int min,max,forward[10001],same[10001],k;
for(i=0;i<10;i++)
	{
	scanf("%d %d",&first,&last);
	scanf("%d",&n);
	count=2;
	inter[0]=first;
	inter[1]=last;	
	for(j=0;j<n;j++)
		{
		scanf("%d %d",&a,&b);
		store[j][0]=a;
		store[j][1]=b;
		if(a>first && a<last)
			{
			inter[count]=a;
			count++;
			}

		if(b>first && b<last)
			{
			inter[count]=b;
			count++;
			}
		}

	for(j=0;j<count;j++)
		{
		same[j]=0;
		forward[j]=0;
		}
	
	sort(inter,count);
	up=0;
	for(j=0;j<count;j++)
		{

		inter[up]=inter[j];
		up++;
		
		
		while(inter[j]==inter[up-1])
			j++;
	
		j--;
			
		}


	for(j=0;j<n;j++)
		{
		k=0;
		if(store[j][0]>=first && store[j][0]<=last)
			{			
			while(store[j][0]!=inter[k])
				k++;	
			}

		else if(store[j][0]>last)
			continue;

	        while(store[j][1]>=inter[k] && k<up)
                                {
                                same[k]+=1;
                                forward[k]+=1;
                                k++;
                                }

               if(store[j][1]==inter[k-1] || k==up)
			      	{	
                                forward[k-1]-=1;
				}
	
			
		}
	min=n;
	max=0; 
	for(j=0;j<up-1;j++)
		{
		if(same[j]<min)
			min=same[j];

		if(same[j]>max)
			max=same[j];

		if(forward[j]<min)
			min=forward[j];
	
		if(forward[j]>max)
			max=forward[j];
		}

	if(same[j]<min)
                 min=same[j];

        if(same[j]>max)
                 max=same[j];
	

	printf("%d %d\n",min,max);
	
	}
return 0;

}
