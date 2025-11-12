// 好像k>=2的时候有问题
# include <bits/stdc++.h>
using namespace std;
# define int long long
# define rep(i,a,b) for (int i = a; i <= b; i++)

int read(){
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9'){
        if (ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    return x * f;
}

void write(int x){
    if (x < 0){
        putchar_unlocked('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar_unlocked(x % 10 + '0');
}

const int N = 1e4 + 50;
int n, m, k;
vector<pair<int,int>> g[N];
vector<pair<int,int>> tmp[N];
int a[15][N];
int fa[N];

struct Node{
    int u,v,w;
    bool operator >(const Node& other) const {
        return w > other.w;
    }
};

int find(int u){
    return (fa[u] == u) ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
    fa[find(u)] = find(v);
}

void kruskal0(){
    priority_queue<Node,vector<Node>, greater<Node>> pq;
    int res = 0;
    rep(u,1,n){
        for (pair<int,int> e : g[u]){
            int v = e.first;
            int w = e.second;
            pq.push({u,v,w});
        }
    }
    while(!pq.empty()){
        Node t = pq.top(); pq.pop();
        int u, v, w;
        u = t.u; v = t.v; w = t.w;
        if (find(u) == find(v)){
            continue;
        }
        res += w;
        unite(u, v);
    }
    cout << res;
}

int kruskal(int S){
    rep(i,1,n) fa[i] = i;

    priority_queue<Node,vector<Node>, greater<Node>> pq;
    int res = 0;
    rep(u,1,n){
        for (pair<int,int> e : g[u]){
            int v = e.first;
            int w = e.second;
            pq.push({u,v,w});
        }
    }
    rep(i,1,k){
        if (1 << (i - 1) & S){
            res += a[i][0];
            int u = i + n;
            fa[u] = u;
            rep(v,1,n){
                pq.push({u,v,a[i][v]});
            }
        }
    }
    while(!pq.empty()){
        Node t = pq.top(); pq.pop();
        int u, v, w;
        u = t.u; v = t.v; w = t.w;
        if (find(u) == find(v)){
            continue;
        }
        res += w;
        unite(u, v);
    }
    return res;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    rep(i,1,m){
        int u, v, w;cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    rep(i,1,k){
        rep(j,0,n){
            cin >> a[i][j];
        }
    }
    if (k == 0){
        rep(i,1,n) fa[i] = i;
        kruskal0();
    }else{
        int ans = 1e16;
        int U = (1 << k)- 1;
        rep(S,0,U) ans = min(ans,kruskal(S));
        cout <<ans;
    }
    return 0;
}
