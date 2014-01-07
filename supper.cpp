#include<stdio.h>
#include<algorithm>
#include<set>

using namespace std;

int main()
{
int i,n,x,j;
set<int>::iterator indx;
set<int> myset;
for(i=0;i<10;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%d",&x);
		myset.insert(x);
		indx = myset.upper_bound(x);		
		printf("%d",*(indx--))
		}
	}

return 0;
}
