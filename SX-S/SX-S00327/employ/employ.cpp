#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read(){
    ll f = 1, res = 0;
    char c = getchar();
    while(c > '9' || c < '0'){
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        res = res * 10 + c - '0';
        c = getchar();
    }
    return f * res;
}

const int N = 520, mod = 998244353;

bool st[N], use[N];
ll c[N], n, m, ans;

void dfs(ll d, ll giv){
    if(d == n + 1){
        if(n - giv >= m)ans ++;
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(use[i])continue;
        use[i] = 1;
        if(st[d])dfs(d + 1, giv + 1);
        else if(giv >= c[i])dfs(d + 1, giv + 1);
        else dfs(d + 1, giv);
        use[i] = 0;
    }
    return;
}

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    n = read(), m = read();
    string s;
    cin >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; i ++){
        if(s[i] == '0'){
            st[i] = 1;//can't do it;
        }
    }
    for(int i = 1; i <= n; i ++){
        c[i] = read();
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}