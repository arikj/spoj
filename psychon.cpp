#include<stdio.h>

#define max 10000001
int arr[max][2];
bool prime[max];

int calc(int num,int n)
{
int x=0;
while(num%n==0)
	{
	num=num/n;
	x++;
	}
return x;
}

void sieve()
{
int i,num,j,x;
for(i=2;i<max;i++)
        {
        if(prime[i]==0)
                {
                j=1;
                while((num = j*i) < max)
                        {
                  	x = calc(num,i);
			if(x%2==0)
				arr[num][0]+=1;
			else
				arr[num][1]+=1;
                        prime[num]=1;
                        j++;
                        }
                }
        }
}


int main()
{
int t,n,i;
sieve();
scanf("%d",&t);
for(i=0;i<t;i++)
	{
	scanf("%d",&n);
//	printf("even %d   odd %d\n",arr[n][0],arr[n][1]);
	if(arr[n][0]<=arr[n][1])
		printf("Ordinary Number\n");
	else
		printf("Psycho Number\n");
	}
return 0;
}
