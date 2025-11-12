#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m;
int s[505];
int num[505], sn[505];
int dp[2][505][505];
int C[505][505];
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i = 0; i <= 500; i++){
        C[i][0] = 1;
        for(int j = 1; j <= i; j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    cin >> n >> m;
    string str;
    cin >> str;
    for(int i = 1; i <= n; i++)s[i] = str[i-1]-'0';
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        num[x]++;
        sn[x]++;
    }
    for(int i = 1; i <= n; i++)sn[i] += sn[i-1];
    dp[0][0][num[0]] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= n; k++){
                if(!dp[i&1][j][k])continue;
                dp[i&1][j][k] %= mod;
                if(s[i+1] == 0){
                    int res = 1;
                    for(int w = 0; w <= min(num[j+1], i-sn[j]+k); w++){
                        dp[(i+1)&1][j+1][k+num[j+1]-w] += dp[i&1][j][k] * res % mod * C[i-sn[j]+k][w] % mod;
                        if(w < num[j+1])dp[(i+1)&1][j+1][k+num[j+1]-w-1] += dp[i&1][j][k] * res % mod * (num[j+1]-w) % mod * C[i-sn[j]+k][w] % mod;
                        if(k)dp[(i+1)&1][j+1][k-1+num[j+1]-w] += dp[i&1][j][k] * res % mod * k % mod * C[i-sn[j]+k][w] % mod;
                        res *= num[j+1] - w;
                        res %= mod;
                    }
                }else{
                    dp[(i+1)&1][j][k] += dp[i&1][j][k];
                    if(k){
                        int res = 1;
                        for(int w = 0; w <= min(num[j+1], i-sn[j]+k); w++){
                            dp[(i+1)&1][j+1][k-1+num[j+1]-w] += dp[i&1][j][k] * res % mod * k % mod * C[i-sn[j]+k][w] % mod;
                            res *= num[j+1] - w;
                            res %= mod;
                        }
                    }
                }
            }
        }
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= n; k++)dp[i&1][j][k] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i <= n-m; i++){
        int res = 1;
        for(int j = 1; j <= n-sn[i]; j++)res *= j, res %= mod;
        ans += dp[n&1][i][0] % mod * res % mod;
    }
    cout << ans % mod << '\n';
    return 0;
}