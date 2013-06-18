#include<stdio.h>
#include<stdlib.h>
int n,m,k;

int merge2(int *numbers,int left, int mid, int right);

int sort2(int *numbers,int left, int right)
{
  int mid;
  int inv=0;
  if (right > left)
  {
    mid = (right + left) / 2;
    inv+=sort2(numbers,left, mid);
    inv+=sort2(numbers,mid+1, right);
 
    inv+=merge2(numbers,left, mid+1, right);
  }
return inv;
}
 
int merge2(int *numbers,int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;
  int inv=0;
  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;
  //int *temp = (int *)malloc(sizeof(int)*(k));
  int temp[1000001];	
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
	inv+=left_end+1-left;
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

	for (i=0; i < num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
//free(temp);
return inv;
}




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
  //int *temp = (int *)malloc(sizeof(int)*k);
  //int *temp2 = (int *)malloc(sizeof(int)*k);
  int temp[1000001],temp2[1000001];
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

	for (i=0; i < num_elements; i++)
  {
    numbers[right] = temp[right];
	b[right] = temp2[right];
    right = right - 1;
  }
//free(temp);
//free(temp2);
}


int main()
{
int t,i,j,h,*a,*b,*c,ans;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d %d",&n,&m,&k);
	
	a = (int *)malloc(sizeof(int)*k);
	b = (int *)malloc(sizeof(int)*k);
	c = (int *)malloc(sizeof(int)*k);

	for(j=0;j<k;j++)
		scanf("%d %d",&a[j],&b[j]);

	sort(a,b,0,k-1);
		
	for(j=0;j<k;j++)
		{c[j]=b[j];}

	
	ans = sort2(c,0,k-1);
	for(j=1;j<k;j++)
		{
		h = j-1;
		while(a[h]==a[j])
			j++;
		if(j-h>=2)
			ans-=sort2(b,h,j-1);
	
		}

	printf("Test case %d: %d\n",i+1,ans); 
	free(a);
	free(b);
	free(c);
	}
return 0;
}
