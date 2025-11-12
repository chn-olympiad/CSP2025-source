#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <typename type>
inline void read(type &x)
{
    x = 0; static bool flag; flag = 0; char ch = getchar();
    while (!isdigit(ch)) flag = ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
}

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const LL mod = 998244353;

int n, m;
int c[N], a[N], vis[N];
LL ans;
string s;

int check()
{
    int cnt = 0;
    for (int i = 0; i < n; i ++)
    {
        if (s[i] == '0') cnt ++;
        else if (cnt >= c[a[i + 1]]) cnt ++;
    }
    if (n - cnt < m) return 0;
    else return 1;
}

void DFS(int pos)
{
    if (pos > n)
        ans += check(), ans %= mod;
    for (int i = 1; i <= n; i ++)
    {
        if (vis[i]) continue;
        vis[i] = 1;
        a[pos] = i;
        DFS(pos + 1);
        vis[i] = 0;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    read(n); read(m);
    cin >> s;
    for (int i = 1; i <= n; i ++)
        read(c[i]);
    bool flag_A = true;
    for (int i = 0; i < n; i ++)
        if (s[i] == '0') flag_A = false;
    if (flag_A)
    {
        ans = 1;
        int cnt_0 = 0;
        for (int i = 1; i <= n; i ++)
            if (c[i] == 0) cnt_0 ++;
        if (n - cnt_0 < m)
        {
            puts("0");
            return 0;
        }
        for (LL i = 1; i <= n; i ++)
            ans = ans * i % mod, ans = (ans + mod) % mod;
        printf("%lld\n", ans);
        return 0;
    }
    DFS(1);
    cout << ans << endl;
    return 0;//Rem bless
}