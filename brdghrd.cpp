#include<stdio.h>
#include<stdlib.h>
#include <vector>

using namespace std;
int temp[100000],temp2[100000]; 

void merge(int *numbers,int *b,int left, int mid, int right);

void sort(int *numbers,int *b,int left, int right)
{
  int mid;
 
  if (right > left)
  {
    mid = (right + left) / 2;
    sort(numbers,b,left, mid);
    sort(numbers,b,mid+1, right);
 
    merge(numbers,b,left, mid+1, right);
  }
}
 
void merge(int *numbers,int *b,int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;
 
  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;
 
  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
      temp[tmp_pos] = numbers[left];
      temp2[tmp_pos] = b[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
	temp2[tmp_pos] = b[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }
 
  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
	temp2[tmp_pos] = b[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
temp2[tmp_pos] = b[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
	}

	for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
	b[right] = temp2[right];
    right = right - 1;
  }
}

void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] <= a[i]) 
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
int t,i,j,res,n,a[100000],b[100000],k,count,c[100000],d[100000];

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	
	scanf("%d",&n);

	for(j=0;j<n;j++)
		{
		scanf("%d",&a[j]);
		
		}

	for(j=0;j<n;j++)
                scanf("%d",&b[j]);

			
	sort(a,b,0,n-1);

	j=1;
	count=1;
	c[0]=b[0];
	while(j<n)
		{
		if(a[j-1]==a[j])
			{
			c[count]=b[j];
			count++;
			}

		else
			{
			if(count>1)
				{
				sort(c,d,0,count-1);
				for(k=0;k<count;k++)
					b[k+j-count] = c[k];
				}
			count=1;
			c[0]=b[j];			
			}
		j++;
		}

				if(count>1)
                                {
                                sort(c,d,0,count-1);
                                for(k=0;k<count;k++)
                                        b[k+j-count] = c[k];
                                }

	vector<int> seq(b, b+sizeof(b)/sizeof(b[0])); // seq : Input Vector
	vector<int> lis;
	find_lis(seq,lis);

	printf("%ld\n",lis.size());
	}
return 0;
}
