#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int c[505];
int a[505];
int vis[505];
int ans = 0, n, m;
void dfs(int dep, int cnt, int mtg){
    if(dep >= n){
        if(cnt >= m)ans++;
        ans %= mod;
        return;
    }
    if(n - dep + cnt < m)return;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            if(mtg < c[i] && a[dep + 1] == 1)dfs(dep + 1, cnt + 1, mtg);
            else dfs(dep + 1, cnt, mtg + 1);
            vis[i] = 0;
        }
    }
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        char s;
        cin >> s;
        a[i] = s - '0';
    }
    for(int i = 1; i <= n; i++)cin >> c[i];
    dfs(0, 0, 0);
    cout << ans % mod;
    return 0;
}
