#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 1e4 + 100;
const int MAXM = 1e6 + 100;
const int MAXK = 15;

struct E {
    int u, v;
    LL w;
    bool operator < (const E& _) const {
        return w < _.w;
    }
} e[MAXM * 2];

LL n, m, k, f[MAXN + MAXK], c[MAXK], a[MAXK][MAXN], ecnt, vcnt, ans;
bool inS[MAXN + MAXK], open[MAXK];
vector<pair<LL, int>> vec[MAXK];
LL sc[MAXK], nc[MAXK];///sc is value, nc is index

int getF(int x) { return x == f[x] ? x : f[x] = getF(f[x]); }

void adds(int x)
{
    inS[x] = true;
    for (int i = 1; i <= k; i++) {
        if (sc[i] > a[i][x]) {
            sc[i] = a[i][x];
        }
    }
    for (int i = 1; i <= k; i++) {
        while (nc[i] < vec[i].size() && inS[vec[i][nc[i]].second]) {
            nc[i]++;
        }
    }
}

void addv(int x)
{
    open[x] = true;
    for (int l = 1; l <= n; l++) {
        e[++ecnt] = {n + x, l, a[x][l]};
    }
    vcnt++;
}

bool kruskal()
{
    ans = 0;
    for (int i = 1; i <= k; i++) {
        if (open[i]) {
            ans += c[i];
        }
    }
    for (int i = 1; i <= n + k; i++) {
        f[i] = i;
    }
    memset(inS, false, sizeof(inS));
    memset(sc, 0x3f, sizeof(sc));
    sort(e + 1, e + ecnt + 1);
    for (int i = 1; i <= k; i++) { /// at first, add new vertex better
        if (open[i]) {
            continue;
        }
        for (int j = 1; j <= n; j++) {
            vec[i].push_back({a[i][j], j});
        }
        sort(vec[i].begin(), vec[i].end());
        if (vec[i].size() > 1 && c[i] + vec[i][0].first + vec[i][1].first <= e[1].w) {
//            cerr << i << " " << vec[i][0].second << " " << vec[i][1].second << endl;
            addv(i);
            return false;
        }
    }
    for (int i = 1; i <= ecnt; i++) {
        int fu = getF(e[i].u), fv = getF(e[i].v);
        if (fu == fv) {
            continue;
        }
//        if (e[i].u <= n && e[i].v <= n) {
            for (int j = 1; j <= k; j++) {
                if (open[j]) {
                    continue;
                }
                if (nc[j] < vec[j].size() && c[j] + sc[j] + vec[j][nc[j]].first <= e[i].w) {
                    addv(j);
                    return false;
                }
            }
//        }
        f[fu] = fv;
        ans += e[i].w;
        if (!inS[e[i].u]) {
            adds(e[i].u);
        }
        if (!inS[e[i].v]) {
            adds(e[i].v);
        }
    }
    return true;
}

namespace B {
    LL ans;
    void kruskal() {
        for (int i = 1; i <= n + k; i++) {
            f[i] = i;
        }
        sort(e + 1, e + ecnt + 1);
        int ccnt = 0;
        for (int i = 1; i <= ecnt; i++) {
            int fu = getF(e[i].u), fv = getF(e[i].v);
            if (fu == fv) {
                continue;
            }
            f[fu] = fv;
            ans += e[i].w;
            ccnt++;
            if (ccnt == vcnt - 1) {
                break;
            }
        }
    }
    void solve() {
//        cerr << "B";
        LL ret = 1e18;
        for (int i = 0; i < (1 << k); i++) {
            ans = 0;
            ecnt = m;
            vcnt = n;
            for (int j = 1; j <= k; j++) {
                if (i & (1 << (j - 1))) {
                    addv(j);
                    ans += c[j];
                }
            }
            kruskal();
            ret = min(ret, ans);
        }
        cout << ret << endl;
    }
};

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    ecnt = m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (k <= 5 && m <= 1e5) {
        B::solve();
        return 0;
    }
    while (!kruskal()) {
        kruskal();
    }
    cout << ans << endl;

    return 0;
}

