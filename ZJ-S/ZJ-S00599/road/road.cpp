#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
const int N = 10010, bb1 = 131, bb2 = 13331;
inline u64 hs(int u, int v) {return u*bb1 + v*bb2;}
int n, m, k;
bool KK = false, A = true;
struct ss {
    int u, v;
    u64 w;
};
bool operator<(const ss &a, const ss &b) {
    return a.w > b.w;
}
unordered_map<u64, int> mmap;
unordered_map<u64, bool> mmapt;
bool ind[N];
vector<ss> g[N];
u64 csh[N][N];
priority_queue<ss> sds;
vector<int> dts;
int c[20];
u64 MST() {
    memset(ind, 0, sizeof(ind));
    u64 ret = 0;
    while(dts.size() < n) {
        ss ori = sds.top();
        ret += ori.w;
        while(!sds.empty()) sds.pop();
        if (!ind[ori.u]) dts.push_back(ori.u);
        if (!ind[ori.v]) dts.push_back(ori.v);
        ind[ori.u] = ind[ori.v] = true;
        for (auto i : dts) {
            for (auto j : g[i]) {
                int uu = j.u, vv = j.v;
                if (!ind[uu] || !ind[vv]) sds.push(j);
            }
        }
    }
    return ret;
}
int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    if (!k) KK = true;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        u64 w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        if (mmap.find(hs(u, v)) == mmap.end()
            || (mmap.find(hs(u, v)) != mmap.end()
                && mmap[hs(u, v)] > w))
                {
                    mmap[hs(u, v)] = w;
                    g[u].push_back((ss){u, v, w});
                    g[v].push_back((ss){u, v, w});
                }
    }
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        memset(csh, -1, sizeof(csh));
        if (c[i]) A = false;
        for (int j = 1; j <= n; ++j) {
            cin >> csh[i][j];
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        for (auto j : g[i]) {
            int uu = j.u, vv = j.v;
            if (mmapt.find(hs(uu, vv)) == mmapt.end()) {
                sds.push(j);
                mmapt[hs(uu, vv)] = 1;
            }
        } 
    } 
    
    if (KK) {
        cout << MST() << '\n';
    } else{
        for (int i = 1; i <= k; ++i) {
            for (int u = 1; u < n; ++u) {
                for (int v = u+1; v <= n; ++v) {
                    if (u == v) continue;
                    u64 w = csh[i][u] + csh[i][v];
                    if (mmap.find(hs(u, v)) == mmap.end()
                        || (mmap.find(hs(u, v)) != mmap.end()
                            && mmap[hs(u, v)] > w))
                            {
                                mmap[hs(u, v)] = w;
                                g[u].push_back((ss){u, v, w});
                                g[v].push_back((ss){u, v, w});
                            }
                }
            }
        }
        cout << MST() << '\n';
    }
    return 0;
}