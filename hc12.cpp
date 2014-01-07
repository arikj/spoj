#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int MOD = 1000000007;

/* This function calculates (a^b)%MOD */
long long pow(int a, int b)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n)
{
    return pow(n,MOD-2);
}
 
long long compute(int n, int r)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r]) * InverseEuler(f[n-r])) % MOD)) % MOD;
}

/*long long int compute(int n,int k)
{
int i;
long long int res=1;

for(i=1;i<=k;i++)
	{
	res= ((res*(n-k+i))/i);
	if(res>=p)	
		res = res%p;
	}

return res;
}*/

int main()
{
int i,j,t,n,k,arr[10000],sum;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&k);
	for(j=0;j<n;j++)
		scanf("%d",&arr[j]);

	sort(arr,arr+n);
	sum = 0;
	for(j=k-1;j<n;j++)
		{
		sum = (sum+compute(j,k-1)*arr[j]);
		if(sum>=MOD)
			sum = sum%MOD;	
		}
	printf("Case #%d: %d\n\n",i+1,sum);
	}
return 0;
}
