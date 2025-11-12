#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 3, mod = 998244353;
int n, m, s[N];
int qzh[N];
int pw[N], inv[N];
int f[2][N][N];

int get(){
    char x;cin >> x;
    while(!isdigit(x))cin >> x;
    return x - '0';
}

int qpow(int x, int y = mod - 2){
    int res = 1;
    while(y){
        if(y & 1)res = res * x % mod;
        x = x * x % mod, y >>= 1;
    }
    return res;
}

int Binom(int x, int y){
    if(x < 0 || y < 0 || x < y)return 0;
    // cerr<<"Binom: "<<x<<' '<<y<<": "<<pw[x] * inv[y] % mod * inv[x - y] % mod<<endl;
    return pw[x] * inv[y] % mod * inv[x - y] % mod;
}

main(){
    pw[0] = 1;
    for(int i = 1; i < N; i++)pw[i] = pw[i - 1] * i % mod;
    inv[N - 1] = qpow(pw[N - 1]);
    for(int i = N - 2; ~i; i--)inv[i] = inv[i + 1] * (i + 1) % mod;
    freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)s[i] = get();
    //  cerr<<s[i]<<' ';cerr<<endl;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        qzh[x]++;
    }
    for(int i = 1; i <= n; i++)qzh[i] += qzh[i - 1];
    //  cerr<<i<<": "<<qzh[i]<<endl;
    int pre = 0, cur = 1;
    f[cur][0][0] = 1;
    for(int i = 0; i < n; i++){
        swap(pre, cur), memset(f[cur], 0, sizeof f[cur]);
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= n; k++){
                int val = f[pre][j][k];
                if(val == 0)continue;
                if(s[i + 1] == 1){
                    if(i - k < qzh[n] - qzh[i - j])(f[cur][j + 1][k] += val) %= mod;
                    if(k + 1 <= qzh[i - j])for(int x = 0; (x <= qzh[i - j + 1] - qzh[i - j]) && (x <= i - k); x++){
                        if(i - k - x <= qzh[n] - qzh[i - j + 1]){
                            (f[cur][j][k + 1 + x] += val * pw[x] % mod * Binom(i - k, x) % mod * Binom(qzh[i - j + 1] - qzh[i - j], x) % mod * (qzh[i - j] - k) % mod) %= mod;
                        }
                    }
                }
                else{
                    for(int x = 0; (x <= qzh[i - j + 1] - qzh[i - j]) && (x <= i - k + 1); x++)
                        if(i + 1 - k - x <= qzh[n] - qzh[i - j + 1])(f[cur][j][k + x] += val * Binom(i + 1 - k, x) % mod * Binom(qzh[i - j + 1] - qzh[i - j], x) % mod * pw[x] % mod) %= mod;
                    if(k + 1 <= qzh[i - j])for(int x = 0; (x <= qzh[i - j + 1] - qzh[i - j]) && (x <= i - k); x++){
                        if(i - k - x <= qzh[n] - qzh[i - j + 1]){
                            (f[cur][j][k + 1 + x] += val * pw[x] % mod * Binom(i - k, x) % mod * Binom(qzh[i - j + 1] - qzh[i - j], x) % mod * (qzh[i - j] - k) % mod) %= mod;
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    for(int j = m; j <= n; j++)
        for(int k = 0; k <= n; k++){
            // cerr<<n<<' '<<j<<' '<<k<<": "<<f[n][j][k]<<endl;
            // if(n - k > qzh[n] - qzh[n - j] && f[n][j][k] != 0)assert(0);
            (res += f[cur][j][k] * pw[n - k] % mod) %= mod;
        }
    printf("%lld\n", res);
}