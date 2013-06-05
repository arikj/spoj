#include<stdio.h>
#include<math.h>

long int p;


long int prime(long int n)
{
long int i;

for(i=2;i<=sqrt(n);i++)
	{
	if(n%i==0)
		return 0;
	}

return 1;
}


long int compute(long int a,long int n)
{

if(n==2)
        return (a*a)%p;

if(n==1)
        return a%p;

long int x=compute(a,n/2);
//printf("%ld ",x);
if(n%2==0)
        return (x*x)%p;

else
        return (((x*x)%p)*(a))%p;
}



int main()
{
long int i,j,t,g,q,list[100000],flag,len;
long int x;

scanf("%ld %ld",&p,&t);

while(p!=0 || t!=0)
{
	q=p-1;
	len=0;
	
	for(i=2;i<=sqrt(q);i++)
		{
		if(q%i==0 && prime(i)==1)
			{
			list[len]=q/i;
//			printf("%d ",list[len]);
			len++;
			}
		}
if(q==2)
	{
	list[len]=1;
	len++;
	}

	for(i=0;i<t;i++)
		{
		scanf("%ld",&g);
		flag=0;
		           
                if(p==2 && g==0)
                        {
                        printf("YES\n");
                        continue;
                        }

		if(g>=p || g<=0)
			{
			printf("NO\n");
			continue;
			}
		if(p==2 && g==1)
			{
			printf("NO\n");
			continue;
			}
		for(j=0;j<len;j++)
			{
			x=compute(g,list[j]);
//			printf("%ld\n",x);
			if(x==1)
				{
				printf("NO\n");
				flag=1;
				break;
				}
			}

		if(flag==0)
			printf("YES\n");		
		}


	scanf("%ld %ld",&p,&t);
}
return 0;
}
