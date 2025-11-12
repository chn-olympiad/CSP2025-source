#include <iostream>
#define mod %998244353
using std::cin;
using std::cout;
int n, m;
int a[505], ans;
bool s[505], flag, vis[505];

void dfs(int k, int now){
    if (now > n){
        ans = (ans + (k >= m)) mod;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(k + (now - 1 - k < a[i] && s[now]), now + 1);
        vis[i] = 0;
    }
}

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        s[i] = (c == '1'), flag &= s[i];
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i], flag &= (a[i] > 0);
    if (m == n){
        ans = 1;
        if (flag)
            for (int i = 1; i <= n; i++)
                ans = ans * i mod;
        else
            ans = 0;
    }
    else
        dfs(0, 1);
    cout << ans << '\n';
}