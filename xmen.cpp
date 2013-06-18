#include<stdio.h>

#include <vector>
using namespace std;
 
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<long int> &a, vector<long int> &b)
{
	vector<long int> p(a.size());
	long int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main()
{
long int i,t,j,n,a[100001],b[100001],c[100001];

scanf("%ld",&t);

for(i=0;i<t;i++)
	{
	scanf("%ld",&n);

	for(j=1;j<=n;j++)
		{
		scanf("%ld",&a[j]);
		c[a[j]]=j;
		}

	 for(j=1;j<=n;j++)
		{
                scanf("%ld",&b[j]);
		a[j]=c[b[j]];
		}

	vector<long int> seq(a,a+sizeof(a)/sizeof(a[0])); 
	vector<long int> lis; 
	find_lis(seq, lis);
	
	printf("%ld\n",lis.size()-1);
	}
return 0;
}
