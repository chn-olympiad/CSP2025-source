#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int mod = 998244353;
int n,k,a[N];
string t;
namespace subtask1{
const int M = (1 << 18);
int f[20][M];
    void work(){
        f[0][0] = 1;
        for(int s = 1;s < (1 << n);s ++){
            int cnt = 0;
            for(int i = 0;i < n;i ++) if(s >> i & 1){
                cnt ++;
            }
            for(int i = 0;i < n;i ++) if(s >> i & 1){
                int ps = s ^ (1 << i);
                for(int j = 0;j < cnt;j ++) if(a[i + 1] > cnt - 1 - j){
                    if(t[cnt] == '1') (f[j + 1][s] += f[j][ps]) %= mod;
                    else (f[j][s] += f[j][ps]) %= mod;
                }else (f[j][s] += f[j][ps]) %= mod;
            }
        }int ans = 0;
        for(int i = k;i <= n;i ++){
            // cout << f[i][(1 << n) - 1] << '\n';
            (ans += f[i][(1 << n) - 1]) %= mod;
        }
        cout << ans << '\n';
    }
}
namespace subtask2{
    bool check(){
        bool flg = 1;
        for(int i = 1;i <= n;i ++)
            flg &= (t[i] == '1');
        return flg;
    }
    void work(){
        cout << 0 << '\n';
    }
}
namespace subtask3{
    void work(){
        for(int i = 1;i <= n;i ++){
            if(t[i] == '0'){
                cout << 0 << '\n';
                return ;
            }
        }
        for(int i = 1;i <= n;i ++){
            if(a[i] == 0){
                cout << 0 << '\n';
                return ;
            }
        }
        int fact = 1;
        for(int i = 1;i <= n;i ++){
            fact = 1ll * fact * i % mod;
        }cout << fact << '\n';
    }
}
void solve(){
    cin >> n >> k >> t;t = " " + t;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    if(n <= 18) return subtask1::work();
    if(n == k) return subtask3::work();
    if(subtask2::check()) return subtask2::work();
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while(T --) solve();
    return 0;
}
/*
no idea too
n <= 18 -> zhuangya

too difficult,maybe dp(n ^ 3)
*/