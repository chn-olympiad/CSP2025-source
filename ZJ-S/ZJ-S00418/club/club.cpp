#include<bits/stdc++.h>
// #define int long long
#define x first 
#define y second
using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> PII;

int T, n, vis[N], v[N][4], a[N][5];

struct sb {
    int id, gp, w;
    bool operator < (const sb &t) const {
        return w < t.w;
    }
};

struct sb2 {
    int id, to, c;
    bool operator < (const sb2 &t) const {
        return c < t.c;
    }
};

inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
    return x * f;
}

signed main() {
    // int st = clock();
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    T = read();
    while(T--) {
        n = read();
        priority_queue<sb> q;
        priority_queue<sb2> q2[4];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                a[i][j] = read(), q.push({i, j, a[i][j]});
            }
        }
        int cnt[4] = {0, 0, 0, 0}, res = 0;
        while(!q.empty()) {
            sb x = q.top(); q.pop();
            if(vis[x.id]) continue;
            if(cnt[x.gp] + 1 <= n / 2) {
                cnt[x.gp]++, vis[x.id] = x.gp; res += x.w; v[x.id][x.gp] = 1;
                if(!v[x.id][1]) q2[x.gp].push({x.id, 1, a[x.id][1] - x.w}); 
                if(!v[x.id][2]) q2[x.gp].push({x.id, 2, a[x.id][2] - x.w});
                if(!v[x.id][3]) q2[x.gp].push({x.id, 3, a[x.id][3] - x.w});
            }
            else {
                while(vis[q2[x.gp].top().id] != x.gp) q2[x.gp].pop();
                int p = q2[x.gp].top().c, flg = 1;
                for(int i = 1; i <= 3; i++) {
                    if(i == x.gp) continue;
                    flg &= (p > a[x.id][i] - x.w);
                }
                if(flg) {
                    int To = q2[x.gp].top().to, Id = q2[x.gp].top().id; res += p;
                    cnt[To]++; v[Id][To] = 1; vis[Id] = To; q2[x.gp].pop();
                    if(!v[Id][1]) q2[To].push({Id, 1, a[Id][1] - a[Id][To]});
                    if(!v[Id][2]) q2[To].push({Id, 2, a[Id][2] - a[Id][To]});
                    if(!v[Id][3]) q2[To].push({Id, 3, a[Id][3] - a[Id][To]});
                    vis[x.id] = x.gp; res += x.w; v[x.id][x.gp] = 1;
                    for(int i = 1; i <= 3; i++)
                        if(!v[x.id][i]) q2[x.gp].push({x.id, i, a[x.id][i] - a[x.id][x.gp]}); 
                    if(!v[x.id][1]) q2[x.gp].push({x.id, 1, a[x.id][1] - a[x.id][x.gp]});
                    if(!v[x.id][2]) q2[x.gp].push({x.id, 2, a[x.id][2] - a[x.id][x.gp]});
                    if(!v[x.id][3]) q2[x.gp].push({x.id, 3, a[x.id][3] - a[x.id][x.gp]});
                }
            }
        }
        printf("%lld\n", res);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) v[i][j] = 0;
            vis[i] = 0;
        }
    }
    // cerr << 1.0 * (clock() - st) / CLOCKS_PER_SEC << endl;
    return 0;
}