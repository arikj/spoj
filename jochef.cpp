#include<stdio.h>
#include<stack>

using namespace std;

long long int largerec(int hist[],int n)
{
  stack<int> s;
 
    long long int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    long long int area_with_top; // To store area with top bar as the smallest bar
 
    int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}

int main()
{
int i,j,n,m,a[4001],count[4001];
char x[4001];
long long int f,res,intm;
long long int ans;

scanf("%d %d",&m,&n); 

while(m!=0 || n!=0)
{
	scanf("%lld",&f);


	for(i=0;i<n;i++)
                count[i]=0;

	for(i=0;i<m;i++)
		{
			scanf("%s",x);
		for(j=0;j<n;j++)
			{
			if(x[j]=='H')
				a[j]=1;

			else
				a[j]=0;
			}


		
		for(j=0;j<n;j++)
			{
			if(a[j]==1)
				count[j]++;

			else
				count[j]=0;

			}
		

		intm = largerec(count,n);

		if(intm>res)
			res=intm;
		}


	ans=f*res;
	printf("%lld\n",ans);
	scanf("%d %d",&m,&n);
}
return 0;
}
