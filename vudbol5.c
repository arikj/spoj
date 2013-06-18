#include<stdio.h>

int main()
{
unsigned long long n,a,b,c,d,x,y,n1,n2,n3,n4,temp;
int flag,count;
scanf("%llu %llu %llu %llu %llu",&n,&a,&b,&c,&d);

while(n!=0)
	{
	flag=0;
	count=0;
	if(a%n!=0 || b%n!=0 || c%n!=0 || d%n!=0)
		{
		printf("Impossible\n");
		}

	else
		{

		a = a/n;
                b = b/n;
                c = c/n;
                d = d/n;
		while(flag==0 && count<4){
		
		
		n1 = a;

		n2 = (n-1)*n1;
		n3 = n-n1;
		n4 = n*(n-n1)-n+n1;

		if((b==n2 && c==n3 && d==n4) || (b==n2 && c==n4 && d==n3) || (b==n3 && c==n2 && d==n4) || (b==n3 && c==n4 && d==n2) || (b==n4 && c==n3 && d==n2) || (b==n4 && c==n2 && d==n3))
		{
		flag=1;
		}		
		
		if(count==0)
			{
			temp = a;
			a = b;
			b = temp;	
			}

		else if(count == 1)
			{
			temp = a;
			a = c;
			c = temp;
			}

		else if(count == 2)
			{
			temp = a;
			a = d;
			d = temp;
			}
		count++;
		}
		if(flag==0)
			printf("Impossible\n");

		else printf("Possible\n");
		}

	scanf("%llu %llu %llu %llu %llu",&n,&a,&b,&c,&d);
	}
return 0; 
}
