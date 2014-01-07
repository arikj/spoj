#include<stdio.h>

int inverse(int a, int n)
{
int t=0,temp,r=n,newt=1,newr=a,q;
while(newr!=0)
	{
	q = r/newr;
	temp = t;
	t = newt;
	newt = temp - q*newt;
	temp = r;
	r = newr;
	newr = temp - q*newr;
	
	}
if(r>1)
	return -1;
else if(t<0)
	t = t+n;

return t;
	
}

int main()
{
int a,n;
a = 1000000007;
printf("%d",a);
//scanf("%d %d",&a,&n);

//printf("%d\n", inverse(a,n));

}
