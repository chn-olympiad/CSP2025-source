#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 7;
int n, a[N], num = 0, ans = 0;
bool flag = 0;

int qp(int x, int y){
    int ans = 1;
    for(; y; y >>= 1){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
    }
    return ans;
}

void countt (int now,int dep, int maxn){
    if(maxn > a[now]){
        ans = (ans + (qp(2, dep)) + mod) % mod;
        return;
    }
    if(dep == 0) return;
    // if(dep == 0){
    //     if(maxn > a[now]) ans = (ans + 1) % mod;
    //     return; 
    // }
    countt(now, dep - 1, maxn + a[dep]);
    countt(now, dep - 1, maxn);
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1) flag = 1;
    }
    if(!flag){
        cout << ((qp(2, n) - n - 1 - n * (n - 1) / 2) + mod) % mod << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        if(num > a[i]) countt(i, i - 1, 0);
        num += a[i];
    }
    cout << ans << endl;
    return 0;
}