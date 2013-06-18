#include<stdio.h>
#include<string.h>
#include<stack>
#include<iostream>
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
int i,t,j,n,m,k,a[2002],count[2002];
char x;
long long int res,intm;
long long int ans;

scanf("%d",&t); 

for(k=0;k<t;k++)
{
	res=0;
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++)
                count[i]=0;

	for(i=0;i<m;i++)
		{
		j=0;
		while(j<n)
			{
			scanf("%c",&x);
			if(x =='F')
				{ a[j]=1; j++;}

			else if(x=='R')
				{ a[j]=0; j++;}
	

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

	ans=3*res;
	printf("%lld\n",ans);
}
return 0;
}
