#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int a[5005];
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int ff = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1)ff = 0;
    }
    if(ff == 1){
        cout << ((n * (n - 1)) % mod * (n - 2)) % mod/ 6;
        return 0;
    }
    for(int i = 7; i < 1 << n; i++){
        if(__builtin_popcount(i) < 3)continue;
        int sum = 0, maxn = 0;
        for(int x = i, j; x; x ^= j){
            j = x & -x;
            int l = __builtin_ffs(x);
            maxn = max(maxn, a[l]);
            sum += a[l];
        }
        if(sum > 2 * maxn)ans++;
        ans %= mod;
    }
    cout << ans;
    return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10
*/