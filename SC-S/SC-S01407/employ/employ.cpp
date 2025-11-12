#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, MOD = 998244353;
int n, m, a[N], t[N], ans;
char c[N];
bool flg[N];
void dfs(int idx){
    if (idx > n){
        int cnt = 0;
        for (int i = 1;i <= n;i ++)
            if (t[i] <= cnt || c[i] == '0') cnt ++;
        if (n - cnt >= m) ans ++;
        return;
    }
    for (int i = 1;i <= n;i ++){
        if (!flg[i]){
            flg[i] = true;
            t[idx] = a[i];
            dfs(idx + 1);
            t[idx] = 0;
            flg[i] = false;
        }
    }
    return;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    bool flg = true;
    for (int i = 1;i <= n;i ++) {
        cin >> c[i];
        if (c[i] == '0') flg = false;
    }
    for (int i = 1;i <= n;i ++) cin >> a[i];
    if (flg){
        long long cnt = 1;
        for (int i = 1;i <= n;i ++){
            cnt *= i;
            cnt %= MOD;
        }
        cout << cnt;
        return 0;
    }
    dfs(1);
    cout << ans;
    return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
