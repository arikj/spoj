#include<stdio.h>
#include<algorithm>

#define mod 1000000000
using namespace std;
pair<int,int>list[100001];
long long int dp[100001];

struct CompareFirst
{
    bool operator() (const std::pair<int,int>& lhs, const std::pair<int,int>& rhs)
    {
        return lhs.first < rhs.first;
    }
};

/*
void binarysearch(int a,int b,int key)
{
int m,l=a,r=b;
 
    while( l <= r )
    {
        m = l + (r-l)/2;
 
        if( list[m].first == key ) 
    		break;        
 
        if( list[m].first < key ) 
            l = m + 1;
        else
            r = m - 1;
    }

if(list[m].first==key){ 
	while(list[m].first==list[m-1].first)
		m--;
}

if(list[m].first>=key)
	dp[m]+=dp[a-1];    
}*/

int main()
{
int i,n,loop,indx;
long long int res;
int arr[8],a[100001];
scanf("%d",&n);
while(n!=-1)
	{
	res=0;
	for(i=0;i<n;i++)
		{
		scanf("%d %d",&list[i].first,&list[i].second);
		dp[i]=1;
		}
	sort(list,list+n,CompareFirst());
	//binarysearch(1,n-1,list[0].second);
	for(i=0;i<n;i++)
		a[i]=list[i].first;
	i=0;
	indx = upper_bound(a,a+n-1,list[i].second)-a;
	if(indx>0){
	while(a[indx-1]==list[i].second)
			indx--;
	}
        if(a[indx]>=list[i].second) 
		dp[indx]+=dp[i];

	for(i=1;i<n;i++)
		{
		dp[i]+=dp[i-1]-1;
		//binarysearch(i+1,n-1,list[i].second);
		indx = upper_bound(a,a+n-1,list[i].second)-a;
		while(a[indx-1]==list[i].second)
                        indx--;
		if(a[indx]>=list[i].second)
			dp[indx]+=dp[i];
		}

	for(i=0;i<n;i++)

		{
		res=(res+dp[i])%mod;
		}
	i=7;
	while(res>0 && i>=0)
		{
		arr[i]=res%10;
		res=res/10;
		i--;
		}
	while(i>=0)
		{
		arr[i]=0;
		i--;
		}
	for(i=0;i<8;i++)
		printf("%d",arr[i]);
	printf("\n");
	scanf("%d",&n);
	}
return 0; 
}
