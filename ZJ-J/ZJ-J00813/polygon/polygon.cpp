#include <bits/stdc++.h>
using namespace std;

#define N 10000
#define mod 998244353

long long n;
long long a[N];
long long power[N];
long long ans;

long long f(long long i, long long zuida)
{
    long long res = 0;
    if (i < 3) return 0;
    for (long long j = i-1; j >= 2; j--)
    {
        long long cida = a[j];
        long long need = zuida - a[j];
        long long need_index = upper_bound(a+1, a+1+j, need) - a;
        if (j > need_index) res += power[need_index-1] * (power[j-need_index] - 1) % mod;
        if (j > need_index) res += f(min(need_index, j), a[min(need_index, j)]-1);
        else res += f(min(need_index, j), need);
    }
    return res;
}

int main()
{
    freopen("polygon.in",  "r", stdin);
    freopen("polygon.out", "w", stdout);
    power[0] = 1;
    for (long long i = 1; i < N; i++)
    {
        power[i] = (power[i-1] << 1) % mod;
    }
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", a+i);
    }
    sort(a+1, a+1+n);
    ans = 0;
    for (long long i = n; i >= 3; i--)
    {
        ans += f(i, a[i]);
    }
    printf("%lld", ans);
    return 0;
}
