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

const int M = 1000010, N = 10010;

ll n, m, k;

struct edge{
    ll a, b, w;
    bool operator<(const edge& a)const{
        return w < a. w;
    }
}e[M], x_e[20][N];

ll x_w[20], st[20];
ll ans = 0x3f3f3f3f3f3f3f3f;

ll p[N + 30];
ll find(ll x){
    if(p[x] == x)return x;
    else return p[x] = find(p[x]);
}

void add(edge x){
    p[find(x. a)] = p[find(x. b)];
}

void dfs(ll depth){
    if(depth == k + 1){

        ll t = n - 1;
        ll res = 0;
        for(int i = 1; i <= k; i ++){
            if(st[i]){
                t ++, res += x_w[i];
                // cout << "havexiang:" << i << endl;
            }
        }

        ll x_i[20] = {};
        ll e_i = 1;

        for(int i = 1; i <= n + k; i ++)p[i] = i;

        while(t){
            ll choose = 0;
            edge minn_e = e[e_i];
            for(int i = 1; i <= k; i ++){
                if(!st[i])continue;
                if(x_e[i][x_i[i]] < minn_e){
                    minn_e = x_e[i][x_i[i]];
                    choose = i;
                }
            }
            if(!choose)e_i ++;
            else x_i[choose] ++;
            
            if(find(minn_e. a) == find(minn_e. b))continue;
            
            add(minn_e);
            res += minn_e. w;
            t --;
            // cout << "add:" << minn_e. a << ' ' << minn_e. b << " " << endl;
        }
        ans = min(ans, res);
        // cout << "ans:" << res << endl;
        return;
    }
    dfs(depth + 1);
    st[depth] = 1;
    dfs(depth + 1);
    st[depth] = 0;
}

signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1; i <= m; i ++){
        ll u = read(), v = read(), ww = read();
        e[i] = {u, v, ww};
    }
    sort(e + 1, e + 1 + m);
    for(int i = 1; i <= k; i ++){
        x_w[i] = read();
        for(int j = 1; j <= n; j ++){
            ll ww = read();
            x_e[i][j] = {n + i, j, ww};
        }
        sort(x_e[i] + 1, x_e[i] + 1 + n);
    }
    dfs(1);

    cout << ans;

    return 0;
}