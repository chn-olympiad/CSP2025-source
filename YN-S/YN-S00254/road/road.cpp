#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int fa[N], t[N];

int p(int x) {
    return (fa[x] == x ? x : p(fa[x]));
}

struct edge {
    int u, v, w;
    bool operator<(const edge &rhs)const {
        return rhs.w < w;
    }
};
int n, m, sum, k;
int l;
priority_queue<edge>q;

void f() {
    for (int i = 1; i <= n + k + 1; i++)
        fa[i] = i;
    while (!q.empty()) {
        auto xx = q.top();
        q.pop();
        //cout<<xx.u<<" "<<xx.v<<" "<<xx.w<<endl;
        if (p(xx.u) != p(xx.v)) {
            if (xx.u > m && fa[xx.u] != xx.u)
                xx.w -= t[xx.u - m];
            sum += xx.w;
            fa[p(xx.u)] = p(xx.v);
            //cout << xx.u << " " << xx.v << " " << xx.w << endl;
            int d = 0;
            for (int i = 2; i <= n; i++) {
                //cout << p(i) << " ";
                if (p(i) != p(i - 1)) {
                    d = 1;
                    break;
                }
            }
            //cout << endl;
            if (d == 0) {
                return;
            }
        }
    }
}
int minn = INT_MIN;

signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        q.push({u, v, w});
    }
    for (int i = 1; i <= k; i++) {
        cin >> t[i] >> l;
        q.push({m + i, 1, t[i] + l});
        for (int j = 2; j <= n; j++) {
            cin >> l;
            q.push({m + i, j, t[i] + l});
        }
    }
    f();
    cout << sum;
    return 0;
}
