#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M = 1e6 + 5;
typedef long long ll;
typedef pair<int, int> PII;
// typedef pair<int, pair<int, int>> PIII;
int n,m,k,vs[N],a[20][N],c[20],fa[N],cnt=0;
int head[N];
ll res[1<<11];
struct edge{
    int u, v, nxt, w;
} e[M << 2];
void add_edge(int x,int y,int w,bool flag=true){
    e[++cnt].u = x;
    e[cnt].v = y;
    e[cnt].w = w;
    if(flag){
        e[cnt].nxt = head[x];
        head[x] = cnt;
    }
}
int find(int x) { return fa[x] == x ? x : fa[x]=find(fa[x]); }
void merge(int x,int y){
    int fx = find(x), fy = find(y);
    if(fx!=fy){
        fa[fy] = fx;
    }
}
vector<PII> g[N];
void kruskal(int id){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    int sum = n;
    for (int i = 1; i <= n + k; ++i) fa[i] = i;
    for (int i = 1; i <= cnt; ++i){
        if(i>m){
            int p = (i - m - 1) / n ;
            if(id&(1<<p)){
                sum += 1;
            }else
                continue;
        }
        q.push({e[i].w, i});
    }
    for (int i = 1; i <= k;++i)
        if((1<<(i-1))&id)
            res[id] += c[i];
    int num = 0;
    while(!q.empty()&&num<sum-1){
        auto now=q.top();
        q.pop();
        int i = now.second, w = now.first;
        int x = e[i].u, y = e[i].v;
        if(find(x)==find(y))
            continue;
        merge(x,y);
        res[id] += w;
        num += 1;
    }
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    double start = clock();
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m>>k;
    int x, y, w;
    for (int i = 1; i <= n;++i)
        fa[i] = i;
    for (int i = 1; i <= m; ++i){
        cin >> x >> y >> w;
        // g[x].push_back({w, y});
        // g[y].push_back({w, x});
        add_edge(x, y, w);
        // add_edge(y, x, w);
    }
    bool flag=false;
    for (int i = 1; i <= k; ++i) {
        cin>>c[i];
        if(c[i]>0)
            flag = true;
        for (int j = 1; j <= n;++j){
            cin >> a[i][j];
            add_edge(n + i, j, a[i][j], 0);
        }  
    }
    kruskal(0);
    for (int i = 1; i < (1 << k);++ i){
        kruskal(i);
    }
    cout << *min_element(res, res + (1 << k) ) ;

    return 0;
}