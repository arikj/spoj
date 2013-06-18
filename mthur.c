#include<stdio.h>
int temp[50001];

void merge(int *numbers,int left, int mid, int right);

void m_sort(int *numbers,int left, int right)
{
  int mid;
 
  if (right > left)
  {
    mid = (right + left) / 2;
    m_sort(numbers,left, mid);
    m_sort(numbers,mid+1, right);
 
    merge(numbers,left, mid+1, right);
  }
}
 
void merge(int *numbers,int left, int mid, int right)
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


int binary_search(int *array,int n,int search )
{
int  first = 0;
 int  last = n - 1;
   int middle = (first+last)/2;
 
   while( first <= last )
   {
      if ( array[middle] < search )
         first = middle + 1;    
      else if ( array[middle] == search ) 
      {
        return middle;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
return first;

}



int main()
{
int t,n,m,i,j,a[10001],b[10001],g[50001],index[10001],count,arr[10001];
long long int sum,sum2,left[10001],right[10001],min_sum;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);	

	for(j=0;j<n;j++)
		scanf("%d",&a[j]);

	for(j=0;j<n;j++)
                scanf("%d",&b[j]);

	scanf("%d",&m);

        for(j=0;j<m;j++)
                scanf("%d",&g[j]);

	sum=0;
	for(j=0;j<n;j++)
		{
		a[j]=a[j]-b[j];
		sum+=a[j];
		}
	min_sum=sum;
	m_sort(a,0,n-1);
	sum2=0;
	for(j=0;j<n;j++)
		{
                sum-=a[j];
		left[j]=sum2;
		right[j]=sum;
		sum2+=a[j];

		}

	for(j=0;j<n;j++)
		{
		sum = right[j] - left[j] + a[j]*(n-1-2*j);

		if(sum<0)
			sum = -1*sum;

		if(sum<min_sum)
			{
			count=1;
			arr[0]=a[j];
			index[0]=j;
			min_sum=sum;
			}

		else if(sum==min_sum)
			{
			arr[count]=a[j];
			index[count]=j;
			count++;
			}
		}

	m_sort(g,0,m-1);
	min_sum=0;
//	for(j=0;j<count;j++)
		{j=0;
		x = binary_search(g,m,arr[j]);
		
		if(arr[j]==g[x])
			{
			min = g[x];	
			if(g[x-1]>a[index[j]-1])
				{
				sum = (n - 2*i)*(g[x-1]-a[index[j]-1]);
				if(sum<min_sum)
					{min = g[x-1];min_sum=sum;}

				}

			if(g[x+1]<a[index[i]+1])
				{
				 sum = (n - 2*i)*(g[x+1]-a[index[j]+1]);
                                if(sum<min_sum)
                                        {min = g[x-1];min_sum=sum;}
                                

				}			
			
			}

		
		}
	}

return 0;
}
