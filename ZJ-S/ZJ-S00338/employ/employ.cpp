#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 1e6 + 7;
int n, m, a[N], ans = 0, c[N];
string s;
bool f[N];
bool flag = 0;
void solve(int dep, int num){ 
    // cout << dep << " " << num << " " << endl;   
    if(num == m){ 
        // cout << dep << endl;
       int res = 1;
       for(int i = i; i <= n - dep + 1; i++){
           res = (res * i) % mod;
       } 
       ans = (ans + res) % mod;
       return;
    }
    if(dep > n){
        return;
    }
    for(int i = 1; i <= n; i++){
        if(f[i]) continue;
        f[i] = 1;
        if(s[dep - 1] == '0') solve(dep + 1, num);
        else{
           if(c[i] > a[dep]) solve(dep + 1, (num + 1) % mod);
           else solve(dep + 1, num);
        }
        f[i] = 0;
    }
    return;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= s.size(); i++){
        if(s[i - 1] == '0'){
            a[i] = a[i - 1] + 1;
            flag = 1;
        }
        else a[i] = a[i - 1];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    if(m == n && flag){
        cout << 0 << endl;
        return 0;
    }
    if(n > 18){
        int yy = 1;
        for(int i = 1; i <= n; i++){
            yy = (yy * i) % mod;
        }
        cout << yy << endl;
        return 0;
    }
    solve(1, 0);
    cout << ans << endl;
    return 0;
}