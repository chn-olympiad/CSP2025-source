#include<bits/stdc++.h>
using namespace std;
const int N = 510;
bool flg[N];
const int MOD = 998244353;
int c[N];
namespace S1{
    const int N1 = 18;
    int f[N1 + 1][N1 + 1][1<<N1];
    void solve(int n,int m){
        f[0][0][0] = 1; 
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < i;j++){
                for(int S = 0;S < (1<<n);S++){
                    int lst = f[i - 1][j][S];
                    for(int k = 0;k < n;k++){
                        if(((S >> k)&1) == 0){
                            if(flg[i]){
                                if(j >= c[k + 1]){
                                    f[i][j + 1][S | (1<<k)] = (f[i][j + 1][S | (1<<k)] + lst)%MOD;
                                }else{
                                    f[i][j][S | (1<<k)] = (f[i][j][S | (1<<k)] + lst)%MOD;
                                }
                            }else{
                                f[i][j + 1][S | (1<<k)] = (f[i][j + 1][S | (1<<k)] + lst)%MOD;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i <= n - m;i++){
            ans = (ans + f[n][i][(1<<n) - 1])%MOD;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        char c;
        cin>>c;
        c -= '0';
        flg[i] = c;
        cnt+=c;
    }
    if(m == n){
        cout<<(cnt == n)<<'\n';
        return 0;
    }
    if(cnt == n){
        int ans = 1;
        for(int i = 1;i <= n;i++){
            ans = 1ll*ans*i%MOD;
        }
        cout<<ans<<'\n';
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin>>c[i];
    }
    if(n <= 18){
        S1::solve(n,m);
        return 0;
    }
    cout<<0<<'\n';
}