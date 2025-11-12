#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int s = 0, f = 1;
    signed c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
    for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
    return s * f;
}
void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar('0' + x % 10);
    return;
}
const int N = 1e4 + 101,
          M = 1e6 + 101,
        inf = 1e17;
int n, m, k, a[11][N], c[11], cst[1101];
int tp[1101], res[1101], cnt[1101];
int f[1101][N];
struct Edge{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator < (const Edge &oth) const{
        return this -> w < oth.w;
    }
}e[M];
vector<Edge> ex[1101];
vector<int> state[11], op[M];
int getf(int id, int u){
    return f[id][u] == u ? u : f[id][u] = getf(id, f[id][u]);
}
int Search(int x){
    int l = 1, r = m, mid;
    if(x < e[1].w) return 0;
    while(l + 1 < r){
        mid = l + r >> 1;
        if(e[mid].w <= x) l = mid;
        else r = mid;
    }
    if(e[r].w <= x) return r;
    return l;
}
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for(int i = 1, u, v, w; i <= m; ++ i){
        u = read(), v = read(), w = read();
        e[i] = Edge(u, v, w);
    }
    sort(e + 1, e + m + 1);
    e[m + 1].w = inf;
    for(int i = 1; i < (1 << k); ++ i){
        for(int j = 0; j < k; ++ j){
            if(i >> j & 1)
                state[j].push_back(i);
        }
    }
    for(int i = 0; i < k; ++ i){
        c[i] = read();
        for(int j = 1, tmp; j <= n; ++ j){
            a[i][j] = read();
            tmp = Search(a[i][j]);
            for(int S : state[i])
                op[tmp].push_back(S);
        }
    }
    for(int i = 0; i < k; ++ i){
        for(int j = 1; j <= n; ++ j)
            ex[1 << i].emplace_back(n + i + 1, j, a[i][j]);
        sort(ex[1 << i].begin(), ex[1 << i].end());
    }
    for(int i = 1, x, y; i < (1 << k); ++ i){
        x = i ^ (i & -i), y = (i & -i);
        cst[i] = cst[x] + c[__lg(y)];
        if(x == 0) continue;
        ex[i].resize(ex[x].size() + ex[y].size());
        merge(ex[x].begin(), ex[x].end(), ex[y].begin(), ex[y].end(), ex[i].begin());
    }
    // cout << "ex_edge:\n";
    // for(int i = 0; i < (1 << k); ++ i){
    //     for(Edge e : ex[i]){
    //         cout << "{" << e.u << " " << e.v << " " << e.w << "} ";
    //     }
    //     cout << "\n";
    // }
    // cout << "options:\n";
    // for(int i = 0; i <= m; ++ i){
    //     cout << i << ": ";
    //     for(int S : op[i]){
    //         cout << S << " ";
    //     }
    //     cout << "\n";
    // }
    memset(tp, 0, sizeof(tp));
    for(int i = 0; i < (1 << k); ++ i)
        iota(f[i] + 1, f[i] + (n + k) + 1, 1);
    for(int S : op[0]){
        for(int u, v, fu, fv; tp[S] < ex[S].size() && ex[S][tp[S]].w < e[1].w; ++ tp[S]){
            u = ex[S][tp[S]].u, v = ex[S][tp[S]].v;
            fu = getf(S, u), fv = getf(S, v);
            if(fu == fv) continue;
            f[S][fu] = f[S][fv];
            ++ cnt[S];
            res[S] += ex[S][tp[S]].w;
        }
    }
    // cout << "tps:\n";
    // for(int i = 1; i < (1 << k); ++ i){
    //     cout << i << ": " << tp[i] << "\n";
    // }
    // cout << "cnts:\n";
    // for(int i = 1; i < (1 << k); ++ i){
    //     cout << i << ": " << cnt[i] << "\n";
    // }
    // cout << "res:\n";
    // for(int i = 1; i < (1 << k); ++ i){
    //     cout << i << ": " << res[i] << "\n";
    // }
    for(int i = 1, u, v, fu, fv; i <= m; ++ i){
        u = e[i].u, v = e[i].v;
        for(int S = 0; S < (1 << k); ++ S){
            fu = getf(S, u), fv = getf(S, v);
            if(fu == fv) continue;
            f[S][fu] = f[S][fv];
            cnt[S] ++;
            res[S] += e[i].w;
        }
        for(int S : op[i]){
            for(; tp[S] < ex[S].size() && ex[S][tp[S]].w < e[i + 1].w; ++ tp[S]){
                u = ex[S][tp[S]].u, v = ex[S][tp[S]].v;
                fu = getf(S, u), fv = getf(S, v);
                if(fu == fv) continue;
                f[S][fu] = f[S][fv];
                ++ cnt[S];
                res[S] += ex[S][tp[S]].w;
            }
        }
    }
    int ans = 1e18;
    // cout << "final_results:\n";
    for(int i = 0; i < (1 << k); ++ i){
        if(cnt[i] != (n + __builtin_popcount(i) - 1)) res[i] = inf;
        ans = min(ans, res[i] + cst[i]);
        // cout << i << ": " << res[i] << "\n";
    }
    write(ans);
    puts("");
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/