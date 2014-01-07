#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<string.h>

using namespace std;

const int MAX = 100005;
const int MOD = 1e9;
pair<int, int> a[MAX];
int dp[MAX];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == -1) break;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; ++i) {
            pair<int, int> aux;
            aux.second = a[i].first;
            int k = upper_bound(a, a + i, aux, cmp) - a - 1;
            dp[i] = (dp[i - 1] + dp[k]) % MOD;
        }
        printf("%08d\n", dp[n] - 1);
    }
return 0;
}
