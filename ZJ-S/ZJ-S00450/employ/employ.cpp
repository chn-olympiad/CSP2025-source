#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510,mod=998244353;
int n, m, c[N];
int dp[1 << 18][18];
string s;
#define cnt(x) __builtin_popcount(x)
void solve1(){
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n)-1;i++){
        // cout << i << ' ';
        for (int j = 0; j <= cnt(i);j++){
            for (int k = 1; k <= n;k++){
                if(((i>>(k-1))&1)==0){
                    int nxt = i | (1 << (k - 1));
                    if(c[k]<=cnt(i)-j){
                        dp[nxt][j] = (dp[nxt][j] + dp[i][j]) % mod;
                        continue;
                    }
                    if(s[cnt(i)+1]=='0'){
                        dp[nxt][j] = (dp[nxt][j] + dp[i][j]) % mod;
                    }
                    else{
                        dp[nxt][j + 1] = (dp[nxt][j + 1] + dp[i][j]) % mod;
                    }
                }
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    int ans = 0;
    for (int i = m; i <= n;i++)
        ans = (ans + dp[(1 << n) - 1][i]) % mod;
    cout << ans << '\n';
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n;i++)
        cin >> c[i];
    if (n <= 18)
        solve1();
    return 0;
}