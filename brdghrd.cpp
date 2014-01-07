#include<stdio.h>
#include<stdlib.h>

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

int binary_search(int arr[],int n,int x)
{
int mid;
int left=0,right=n-1;

while(left<right)
	{
	mid = (left+right)/2;

	if(arr[mid]>x && arr[mid-1]<=x)
		return mid-1;

	else if(arr[mid+1]>x && arr[mid]<=x)
		return mid;

	else if(arr[mid]>x)
		right = mid;

	else if(arr[mid]<x)
		left = mid;
	}
return 0;
}


long int lis(int array[],int len)
{
int sz = 1,k;
temp[1] = array[0]; /*at this point, the minimum value of the last element of the size 1 increasing sequence must be array[0]*/
temp2[0] = 1;
for( int i = 1; i < len; i++ ) {
   if( array[i] < temp[1] ) {
      temp[1] = array[i]; /*you have to update the minimum value right now*/
      temp2[i] = 1;
   }
   else if( array[i] > temp[sz] ) {
      temp[sz+1] = array[i];
      temp2[i] = sz+1;
      sz++;
   }
   else {
      k = binary_search( temp, sz, array[i] ); /*you want to find k so that c[k-1]<array[i]<c[k]*/
      temp[k] = array[i];
      temp2[i] = k;
   }
}
int max=temp2[0];
for(int i=1;i<len;i++)
	{
	if(max<temp2[i])
		max=temp2[i];
	}
return max;
}


int main()
{
int t,i,j,n,a[100000],b[100000],k,count,c[100000],d[100000];
long int res;
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

	res = lis(b,n);
	printf("%ld\n",res);
	}
return 0;
}
