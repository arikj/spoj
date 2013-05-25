#include<stdio.h>

int numbers[4000],temp[4000];

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
    if (numbers[left] >= numbers[mid])
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
int i,t,j,n,k,m,ch;
long int res,x,sum;
long int in[4000],in_s;
int in_i;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res=0;x=0;sum=0;
	scanf("%d %d",&n,&k);
	for(j=0;j<n;j++)
		scanf("%d",&numbers[j]);

	m_sort(0,n-1);


	for(j=k-1;j>=0;j--)
		{in_s=3000000001;
			ch=j;
		for(m=0;m<n-k+1;m++)
			{
			in[m]=(m+1)*numbers[j+m];	
			if(in_s>in[m])
				{in_s=in[m];in_i=j+m;}

			
			}
		res+=numbers[in_i];
		for(m=0;m<n+ch-k;m++)
			{
				
			if(m<in_i)
				{
				
				numbers[m]=numbers[m]-numbers[in_i];
				if(numbers[m]==0)
					j--;
				res+=numbers[in_i];	
				}

			else 
				{
				if(numbers[m+1]-numbers[in_i]<=0)
					{
					if(j>0)
					{
					res+=numbers[m+1];
					numbers[m+1]=0;
					j--;}	
					}
		
				}
			}
			numbers[in_i]=0;
			for(m=0;m<n+ch-k;m++)
				{
				if(numbers[m]==0)
					{
					numbers[m]=numbers[m+1];
					
					}
				}
			
		}

	printf("%ld\n",res);
	}
return 0;
}
