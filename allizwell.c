#include<stdio.h>

char matrix[105][105];
char string[20] = "ALLIZZWELL";
int n,m,visited[105][105];
int allizwell(int i,int j,int k)
{
if(i<0 || i>n-1 || j<0 || j>m-1)
	return 0;

if(k==9 && matrix[i][j]==string[k] && visited[i][j]==0)
	return 1;

if(visited[i][j]==1 || string[k]!=matrix[i][j])
	return 0;
int x,y;
visited[i][j]=1;
if(allizwell(i,j+1,k+1)==1)
	return 1;
if(allizwell(i,j-1,k+1)==1)
        return 1;
if(allizwell(i+1,j,k+1)==1)
        return 1;
if(allizwell(i-1,j,k+1)==1)
        return 1;
if(allizwell(i+1,j+1,k+1)==1)
        return 1;
if(allizwell(i-1,j-1,k+1)==1)
        return 1;
if(allizwell(i-1,j+1,k+1)==1)
        return 1;
if(allizwell(i+1,j-1,k+1)==1)
        return 1;
visited[i][j]=0;
return 0;

}

int main()
{
int t,i,j,k,x,y;
scanf("%d",&t);

for(k=0;k<t;k++)
	{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%s",matrix[i]);

	x = 0;	
	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			{
			if(matrix[i][j]=='A')
				{
				for(x=0;x<n;x++)
					for(y=0;y<m;y++)
						visited[x][y]=0;
				x = allizwell(i,j,0);
				
				if(x==1)
					break;
				}
			
			}
		if(x==1)
			break;
		}
	if(x==1)
		printf("YES\n\n");
	else
		printf("NO\n\n");
	}	
return 0;
}
