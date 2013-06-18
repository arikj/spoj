#include<stdio.h>
#include<queue>
#include<deque>

using namespace std;

int main()
{
int i,start[6501]={0},end[6501]={0},current=1,index=1;
int j,t,n,ans;
queue<int> num;
queue<int> count;

num.push(1);
count.push(1);
start[1]=1;end[1]=1;
current++;
index++;

while(start[6500]==0)
	{
	start[current]=index;
	end[current]=index+num.front()-1;
	

	count.push(num.front());
	num.push(current);

	count.front()-=1;
	if(count.front()==0)
		{
		num.pop();
		count.pop();
		}

	index=end[current]+1;
	current++;		
	}

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
		
	for(j=2;j<6500;j++)
		{
		if(start[j]>n && start[j-1]<=n)
			{
			ans = j-1;
			break;
			}
		}

	printf("Case #%d: %d\n",i+1,ans);
	}
return 0;
}
