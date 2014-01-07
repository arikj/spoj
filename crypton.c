#include<stdio.h>
#include<string.h>
#include<math.h>

int divide(int key[],int prime, int size)
{
int i,rem=0,temp=prime,digits=0;

while(temp>0)
	{
	temp=temp/10;
	digits++;
	}

i = digits-1;

while(i>=0)
	{
	rem+=key[digits-1-i]*pow(10,i);
	i--;
	} 

i = digits;
rem = rem%prime;
while(i<size)
	{
	rem = rem*10 + key[i];
	rem = rem%prime;
	i++;		
	}

if(rem==0)
	return 1;

else 
	return 0;
}

int main()
{
char num[105];
int i,l,key[105],len,p,j,arr[1000001]={0};
int flag,prime[100000],tot=0;

for(i=2;i<=1000000;i++){
        if(arr[i]==0)
        {   p=i;
            for (j=2;p*j<=1000000;j++)
            {   
                arr[p*j]=1;
            }
        }
    }

for(i=2;i<=1000000;i++)
	{
	if(arr[i]==0)
		{
		prime[tot]=i;
		tot++;
		}
	}

scanf("%s",num);
scanf("%d",&l);

while(l!=0)
	{
	len=strlen(num);

	for(i=0;i<len;i++)
		key[i] = num[i] - '0';

	flag=0;
	for(i=0;i<tot;i++)
		{
		if(divide(key,prime[i],len)==1)
			{
			if(prime[i]<l)
				printf("BAD %d\n",prime[i]);
				
			else	
				printf("GOOD\n");

			flag=1;
			break;
				
			}
		}

	if(flag==0)
		printf("GOOD\n");
			
	scanf("%s",num);
	scanf("%d",&l);
	}

return 0;
}
