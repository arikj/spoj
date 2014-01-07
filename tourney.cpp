#include<stdio.h>
#include<math.h>

using namespace std;
int arr[2100000][2];

int main()
{
int n,m,i,win,p,j;
char ch;
scanf("%d %d", &n, &m);

for(i=pow(2,n)-1;i<pow(2,n+1)-1;i++)
	{
	scanf("%d",&arr[i][1]);
	arr[i][0] = i - pow(2,n) + 1;
	}

for(i=pow(2,n+1)-2; i>0; i=i-2)
	{
	if(arr[i][1] > arr[i-1][1])
		{
		arr[(i-1)/2][1] = arr[i][1];
		arr[(i-1)/2][0] = arr[i][0];
		}

	else
		{
		arr[(i-1)/2][1] = arr[i-1][1];
                arr[(i-1)/2][0] = arr[i-1][0];
		}
	}

for(i=0;i<m;i++)
	{
	scanf("%c",&ch);
	scanf("%c",&ch);
	if(ch == 'S')
		{
		scanf("%d",&p);
		win = 0;
		for(j = pow(2,n)-2+p;j>=0;j = (j-1)/2)
			{
			if(arr[j][0] == p-1)
				win++;
			if(j==0)
				break;
			}
		printf("%d\n",win-1);
		}

	else if(ch == 'W')
		{
		printf("%d\n",arr[0][0]+1);	
		}

	else if(ch == 'R')
		{
		scanf("%d %d",&p, &win);
		j = pow(2,n) - 2 + p;
		arr[j][1] = win;
		arr[j][0] = p-1;
		while(j>0)
			{
			if(j%2 == 0)
				{
				if(arr[j][1] > arr[j-1][1])
					{
					arr[(j-1)/2][1] = arr[j][1];
					arr[(j-1)/2][0] = arr[j][0];		
					}

				else
					{
					 arr[(j-1)/2][1] = arr[j-1][1];
                                        arr[(j-1)/2][0] = arr[j-1][0];
					}
				}

			else
				{
				if(arr[j][1] > arr[j+1][1])
                                        {
                                        arr[(j-1)/2][1] = arr[j][1];
                                        arr[(j-1)/2][0] = arr[j][0];
                                        }
                                
                                else
                                        {
                                         arr[(j-1)/2][1] = arr[j+1][1];
                                        arr[(j-1)/2][0] = arr[j+1][0];
                                        }

				}
			j = (j-1)/2;
			}
		}
			
	}

//for(i=0;i<pow(2,n+1)-1;i++)
//	printf("%d %d\n",arr[i][0], arr[i][1]);

return 0;
}


