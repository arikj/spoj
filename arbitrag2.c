#include<stdio.h>
#include<string.h>

char list[30][100];
float inf=0;
float matrix[30][30];
float final[30][30];
int n,m;


void floydwarshall()
{
int i,j,k;

for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		final[i][j]=matrix[i][j];

for(k=0;k<n;k++)
	{
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			{
			if(final[i][k]*final[k][j]>final[i][j])
				final[i][j]=final[i][k]*final[k][j];	
			}
		}	
	}

}


int send(char str[100])
	{
	int i;
	for(i=0;i<n;i++)
		{
		if(strcmp(str,list[i])==0)
			return i;
		}

	}




int main()
{
int i,x,y,j,c=1,flag;
char curr[100];
float val;

scanf("%d",&n);

while(n!=0)
	{
	for(i=0;i<n;i++)
		{
		scanf("%s",curr);
		strcpy(list[i],curr);
		}

	scanf("%d",&m);
	
	 for(x=0;x<n;x++)
                {
                for(y=0;y<n;y++)
			{
		
				matrix[x][y]=inf;
			}
                }


	for(i=0;i<m;i++)
		{	
		scanf("%s",curr);
		x=send(curr);
		scanf("%f",&val);
		scanf("%s",curr);
		y=send(curr);

		matrix[x][y]=val;	
		}


	floydwarshall();

	for(x=0;x<n;x++)
		{
		for(y=0;y<n;y++)
			printf("%f ",final[x][y]);
		printf("\n");
		}

	flag=0;
	for(x=0;x<n;x++)
		{
		for(y=0;y<n;y++)
			{
			if(x<=y)
				break;

			else
				{
				if(final[x][y]<inf && final[y][x]<inf && final[x][y]*final[y][x]>1)
					{
					flag=1;
					break;
					}
				}
				
			}
		if(flag==1)
			break;
		}


	if(flag==1)
		printf("Case %d: Yes\n",c);

	else
		printf("Case %d: No\n",c);

	scanf("%d",&n);	
	c++;
	}

return 0;
}

