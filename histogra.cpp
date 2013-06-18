#include<stdio.h>
#include<stack>

using namespace std;

long long int largerec(long long int hist[],long long int n)
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
long long int i,n,a[100000],res;
scanf("%lld",&n);

while(n!=0)
{

for(i=0;i<n;i++)
	scanf("%lld",&a[i]);

res = largerec(a,n);
printf("%lld\n",res);
scanf("%lld",&n);
}
return 0;

}
