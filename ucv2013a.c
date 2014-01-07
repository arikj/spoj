#include<stdio.h>
#define m 1000000007
int main()
{
long long int i,n, l, a, b;
while (1)
{
a = 1;
b = 0;
scanf("%lld%lld",&n,&l);
if(n == 0 && l == 0) return 0;
for (i = 1; i < l + 1; i++)
{
a=(n *a)% m;
b=(b+a) % m;
}
printf("%lld\n",b);
}
return(0);

}
