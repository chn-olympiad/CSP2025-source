#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long fac[505];
int n, m, c[505], cnt, p[505], v[505], res, ans;
bool f;
string s;

void init(){
    fac[0] = 1;
    for(int i = 1;i <= 500;i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
}

void dfs(int dep){
    if(dep > n){
        cnt = 0;
        res = 0;
        for(int i = 1;i <= n;i++){
            // cout<<p[i]<<' ';
            if(c[p[i]] <= cnt) cnt++;
            else{
                if(s[i - 1] == '1') res++;
                else{
                    cnt++;
                }
            }
        }
        // cout<<'\n';
        // cout<<res<<'\n';
        if(res >= m) {
            ans++;
            if(ans > MOD) ans = ans % MOD;
        }
    }else{
        for(int i = 1;i <= n;i++){
            if(v[i] == 0){
                v[i] = 1;
                p[dep] = i;
                dfs(dep + 1);
                v[i] = 0;
            }
        }
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    // init();
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++) cin >> c[i];
    dfs(1);
    // f = 0;
    // for(int i = 0;i < n;i++){
    //     if(s[i] == '0') f = 1;
    // }
    // if(f == 0){
    //     cnt = 0;
    //     for(int i = 1;i <= n;i++) if(c[i] == 0) cnt++;
    //     cout<<fac[n - cnt]<<'\n';
    // }
    cout<<ans<<'\n';
    return 0;
}