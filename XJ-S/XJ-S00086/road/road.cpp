#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5;

int n, m, k, dis[N], ind[N];// maxd;
pair<int, int> Maxd;
queue<int> q;
vector<pair<int, ll> > e[N];
bool vis[N];

void prim(){//Oh no!I forgot it!
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push(1);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto nxt : e[u]){
            int v = nxt.first, w = nxt.second;

        }
    }

    /*
        enjoying the last minutes in my OI life, there's endless sorrow in my mind.
        if I'd revised the prim, maybe today i would have gotten 100 + 64 + 25 + 8 = 197pts.
        But... all  will be over, maybe im no a person to learn OI.....
        TaT..........
        c______ 2025.11.1
    */
}

void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v;ll w;
        cin >> u >> v >> w;
        ++ ind[u], ++ ind[v];
        e[u].push_back(make_pair(v, w));
        e[v].push_back(make_pair(u, w));
    }
    prim();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    clock_t st = clock();
    // int T;
    // cin >> T;
    // while (T --)
        solve();
    clock_t ed = clock();
    // printf("\nThe time is %.3lf s", (double)(ed - st) / CLOCKS_PER_SEC);
}