#include<bits/stdc++.h>
using namespace std;
#define int long long
long long read() {
    long long x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') f = -1;c = getchar();}
    while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c - '0');c = getchar();}
    return x * f;
}
const int N = 1e4 + 10, M = 2e6 + 10;

struct node {
    int u, v, w;
    bool operator < (const node& b) const {
        return w < b.w;
    }
}e[M], e2[M];
struct DSU {
    int fa[N];
    void init(int n) {
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int getfa(int x) {
        if(fa[x] != x) fa[x] = getfa(fa[x]);
        return fa[x];
    }
    void merge(int x, int y) {
        int fax = getfa(x);
        int fay = getfa(y);
        if(fax == fay) return ;
        fa[fax] = fay;
    }
    bool check(int x, int y) {
        return getfa(x) == getfa(y);
    }
}D;
int sum[N];
int dfscnt = 0;
int a[N];
vector<int> g[15];
int c[N];
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        e[i] = {u, v, w};
    }
    int sumc = 0;
    for (int j = 1; j <= k; j++) {
        c[j] = read();
        sumc += c[j];
        for (int i = 1; i <= n; i++) {
            g[j].push_back(read());
        }
    }
    if(sumc == 0) {
        for (int j = 1; j <= k; j++) {
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if(g[j][i] == 0) {
                    idx = i + 1;
                    break;
                } 
            }
            for (int i = 0; i < n; i++) {
                if(i + 1 == idx) continue;
                e[++m] = {idx, i + 1, g[j][i]};
            }
        }
        sort(e + 1, e + m + 1);
        
        D.init(n);
        int cnt = 0, ans = 0;
        for (int i = 1; i <= m; i++) {
            if(D.check(e[i].u, e[i].v)) continue;
            ans += e[i].w;
            D.merge(e[i].u, e[i].v);
            cnt++;
            if(cnt == n-1) break;
        }
        cout << ans << endl;
        return 0;
    }
    sort(e + 1, e + m + 1);
    D.init(n);
    int cnt = 0, ans = 0;
    for (int i = 1; i <= m; i++) {
        if(D.check(e[i].u, e[i].v)) continue;
        ans += e[i].w;
        D.merge(e[i].u, e[i].v);
        cnt++;
        if(cnt == n-1) break;
    }
    cout << ans << endl;
    
    return 0;
}
/*

g++ -std=c++14 -O2 -Wall -Wextra -Wl,--stack=512000000 1.cpp -o 1
*/