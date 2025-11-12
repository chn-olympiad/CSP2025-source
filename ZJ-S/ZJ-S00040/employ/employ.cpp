#include<bits/stdc++.h>
#define PII pair<int,int>
#define pb push_back
using namespace std;
const int Maxn = 1e5 + 10;
const int mod = 998244353;
int s[Maxn], c[Maxn], a[Maxn];
int p[Maxn];
int qPow(int a, int b){
    int r = 1;
    while(b){
        if(b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string ss;
    cin >> ss;
    ss = ' ' + ss;
    for(int i = 1; i <= n; i++){
        s[i] = ss[i] - '0';
        a[i] = a[i - 1] + s[i];
    }
    for(int i = 1; i <= n; i++) cin >> c[i];
    int sm = 0;
    for(int i = 1; i <= n; i++) sm += c[i];
    if(!sm){
        cout << 0 << endl;
        return 0;
    }
    if(m == 1){
        int ans = 1;
        for(int i = 1; i <= n; i++){
            ans = ans * i % mod;
        }
        cout << (ans - 1 + mod) % mod << endl;
        return 0;
    }
    if(m == n){
        int ans = 1;
        for(int i = 1; i <= n; i++){
            ans = ans * i % mod;
        }
        if(sm == n * n){
            cout << ans;
        }else cout << 0 << endl;
        return 0;
    }
    // for(int i = 1; i <= n; i++) a[i] = i - a[i];
    if(n <= 10){
        for(int i = 1; i <= n; i++) p[i] = i;
        int ans = 0;
        do{
            int r = 0;
            int x = 0;
            for(int i = 1; i <= n; i++){
                if(!s[i])x++;
                else {
                    if(x >= c[p[i]]) x++;
                    else r++;
                }
            }
            if(r >= m) ans++;
        }while(next_permutation(p + 1, p + 1 + n));
        cout << ans << endl;
        return 0;
    }
    cout << 0 << endl;
}