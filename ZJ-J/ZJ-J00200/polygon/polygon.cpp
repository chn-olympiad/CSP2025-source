#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MAXN = 5e3 + 10, MOD = 998244353;
ll n, a[MAXN], ans;
void dfs(ll x, ll num, ll length, ll mx){
    if(x > n){
        if(num >= 3 && length > mx * 2){
            ans++;
            ans %= MOD;
        }
        return;
    }
    dfs(x + 1, num, length, mx);
    dfs(x + 1, num + 1, length + a[x], max(mx, a[x]));
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(n <= 20){
        dfs(1, 0, 0, 0);
        cout << (ans % MOD) << '\n';
    }
    else{
        for(int i = n - 2; i < n; i++){
            ans += (i + 1) * i / 2;
            ans %= MOD;
        }
        cout << (ans % MOD) << '\n';
    }
}
/*
T3 is difficult.I give up.
T4 seems dp.
3 <= n <= 5000
let dp_i become the answer to use woolens which let i become the finish.
*/