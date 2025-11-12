#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 500;
const ll mod = 998244353;
int read()
{
    int x = 0;
    char c = getchar();
    for(; !isdigit(c); c = getchar());
    for(; isdigit(c); c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    return x;
}
bool readb()
{
    char c = getchar();
    for(; !isdigit(c); c = getchar());
    return c == '1' ? 1 : 0;
}
int n, m;
int a[N + 5];
bool di[N + 5];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        di[i] = readb();
    for(int i = 1; i <= n; i++)
        a[i] = read();
    // for(int i = 1; i <= n; i++)
    //     printf("%d ", a[i]);
    sort(a + 1, a + 1 + n);
    ll x = 1, now = 1;
    a[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == a[i - 1])
            now = (now + 1) % mod;
        else
            now = 1;
        x = (x * now) % mod;
    }
    ll ans = 0;
    printf("%lld\n", x);
    do
    {
        int cnt = 0;
        int go = 0;
        for(int i = 1; i <= n; i++)
        {
            if(go >= a[i] || di[i] == 0)
                go++;
            else
                cnt++;
            if(cnt == m)
            {
                ans = (ans + x) % mod;
                // for(int j = 1; j <= n; j++)
                //     printf("%d ", a[j]);
                // puts("");
                break;
            }
        }
    }while(next_permutation(a + 1, a + 1 + n));
    printf("%lld\n", ans);
    return 0;
}