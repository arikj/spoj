#include<stdio.h>
#include<math.h>

int main()
{
unsigned long long i,x[1000000],n,a,b,c,d,n1,s,n2,n3,n4,temp;
int flag,count,j;
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
		
		if(b<a && b<c && b<d)
			{
			temp = a;
			a = b;
			b = temp;
			}

		else if(c<a && c<b && c<d)
			{
			 temp = a;
                        a = c;
                        c = temp;

			}

		   else if(d<a && d<b && d<c)
                        {
                         temp = a;
                        a = d;
                        d = temp;

                        }

		s = sqrt(a);
		for(i=1;i<=s;i++)
			{
			if(a%i==0)
				{
				x[count]=i;
				count++;
				}
			}
		j=0;

		while(j<count && flag==0){
		
		
		n1 = a;

		n2 = n*(a/x[j]) - n1;
		n3 = n*(x[j])-n1;
		n4 = n*n - n1 -n2 -n3;;

		if((b==n2 && c==n3 && d==n4) || (b==n2 && c==n4 && d==n3) || (b==n3 && c==n2 && d==n4) || (b==n3 && c==n4 && d==n2) || (b==n4 && c==n3 && d==n2) || (b==n4 && c==n2 && d==n3))
		{
		flag=1;
		}		
		
		j++;
		}
		if(flag==0)
			printf("Impossible\n");

		else printf("Possible\n");
		}

	scanf("%llu %llu %llu %llu %llu",&n,&a,&b,&c,&d);
	}
return 0; 
}
