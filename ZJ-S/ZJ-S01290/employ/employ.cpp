#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 510, mod = 998244353;
char s[N];
int n, m;
int c[N];
int ans = 0;
int a[N];
bool st[N];

void work()
{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i ++)
    {
        // cerr << a[i] << " \n"[i == n];
        if(c[a[i]] <= cnt2) cnt2 ++;
        else if(s[i] == '1') cnt1 ++;
        else cnt2 ++;
        // cerr << cnt1 << " " << cnt2 << endl;
    }
    // cerr << cnt1 << endl;
    if(cnt1 >= m) ans ++;
}

void dfs(int step)
{
    if(step > n)
    {
        work();
        return;
    }
    for(int i = 1; i <= n; i ++)
        if(!st[i])
        {
            st[i] = true;
            a[step] = i;
            dfs(step + 1);
            st[i] = false;
        }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    // cin >> n >> m;
    scanf("%d%d%s", &n, &m, s + 1);
    // cerr << (s + 1) << endl;
    for(int i = 1; i <= n; i ++) scanf("%d", &c[i]);
    if(m == n)
    {
        bool flag = true;
        for(int i = 1; i <= n; i ++) if(!c[i]) flag = false;
        for(int i = 1; i <= n; i ++) if(s[i] != '1') flag = false;
        if(flag)
        {
            int res = 1;
            for(int i = 1; i <= n; i ++) res = (LL)res * i % mod;
            printf("%d\n", res);
        }
        else puts("0");
        return 0;
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}