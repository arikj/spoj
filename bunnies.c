#include<stdio.h>

int numbers[3000],temp[3000];

void merge(int left, int mid, int right);

void m_sort(int left, int right)
{
  int mid;
 
  if (right > left)
  {
    mid = (right + left) / 2;
    m_sort(left, mid);
    m_sort(mid+1, right);
 
    merge(left, mid+1, right);
  }
}
 
void merge(int left, int mid, int right)
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
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }
 
  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
	}

	for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}


int main()
{
int i,t,j,n,k;
long int res,x,sum;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res=0;x=0;sum=0;
	scanf("%d %d",&n,&k);
	for(j=0;j<n;j++)
		scanf("%d",&numbers[j]);

	m_sort(0,n-1);

	for(j=0;j<k;j++)
		sum+=numbers[j];

	for(j=k-1;j<n;j++)
		{
		x=sum+(n-j-1)*numbers[j];
		if(j==k-1)
			res=x;
		else
			{
			if(res>x)
				res = x;
			}
		if(j+1<n)	
			{	
			sum=sum+numbers[j+1]-numbers[j+1-k];

			}
		}
	printf("%ld\n",res);
	}
return 0;
}
