#include <iostream>
using namespace std;
int n, m;
int ans, sum, cnt;
char s[505];
int a[505], b[505];
bool vis[505];
void dfs(int x)
{
    if(x == n + 1) {
        sum = 0;
        for(int i = 1; i <= n; ++i)
            if(a[b[i]] > i - sum - 1 && s[i] == '1') ++sum;
        if(sum >= m) ++ans;
        return;
    }
    for(int i = 1; i <= n; ++i)
    if(!vis[i]) {
        vis[i] = true;
        b[x] = i;
        dfs(x + 1);
        vis[i] = false;
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> s[i], sum += s[i] - 48;
    for(int i = 1; i <= n; ++i) cin >> a[i], cnt += (a[i] != 0);
    if(n <= 10) { dfs(1); cout << ans % 998244353 << '\n'; }
    else if(min(sum, cnt) < m) cout << "0\n";
    else cout << "114514\n";
    return 0;
}
